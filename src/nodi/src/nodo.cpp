#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "example_interfaces/msg/float64_multi_array.hpp"
#include <vector>
#include <mutex>

class NodoConsenso : public rclcpp::Node {
public:
    NodoConsenso() : Node("nodo" )  {
        this->declare_parameter<int>("id", 0); 
        id_ = this->get_parameter("id").as_int();
        std::string nomepub = "stima_" + std::to_string(id_);
        pub_Vv = this->create_publisher<example_interfaces::msg::Float64MultiArray>("nomepub", 10);
        
        // sub_Vv = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
        //     "stima", 10,
        //     std::bind(&NodoConsenso::callback_Vv, this, std::placeholders::_1));
            
        sub_misura = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            "misura_ricevuta", 10,
            std::bind(&NodoConsenso::callback_misura, this, std::placeholders::_1));

        if (id_ > 0) {
            std::string topic_adiacente_sinistro = "stima_" + std::to_string(id_ - 1);
            subscriber_sinistro_ = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
                topic_adiacente_sinistro, 10,    std::bind(&NodoConsenso::callback_sinistro, this, std::placeholders::_1));
        }
        if (id_ == 0) {
            std::string topic_adiacente_sinistro = "stima_" + std::to_string(7);
            subscriber_sinistro_ = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
                topic_adiacente_sinistro, 10,    std::bind(&NodoConsenso::callback_sinistro, this, std::placeholders::_1));
        }

        if (id_ == 7) {
            std::string topic_adiacente_destro = "stima_" + std::to_string(0);
            subscriber_destro_ = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
                topic_adiacente_destro, 10, std::bind(&NodoConsenso::callback_destro, this, std::placeholders::_1));
        }

        if (id_ < 7) {
            std::string topic_adiacente_destro = "stima_" + std::to_string(id_ + 1);
            subscriber_destro_ = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
                topic_adiacente_destro, 10,    std::bind(&NodoConsenso::callback_destro, this, std::placeholders::_1));
        }
        
    }

private:
    int id_;
    // void callback_Vv(const example_interfaces::msg::Float64MultiArray::SharedPtr msg) {
    //     std::lock_guard<std::mutex> lock(mutex_);
    //     stima_ricevuta_.push_back(msg->data);
    // }
    void callback_misura(const example_interfaces::msg::Float64MultiArray::SharedPtr msg) {
        std::lock_guard<std::mutex> lock(mutex_);
        misura_ricevuta.push_back(msg->data);
    }
    void callback_destro(const example_interfaces::msg::Float64MultiArray::SharedPtr msg) {
        std::lock_guard<std::mutex> lock(mutex_);
        stima_destra_ricevuta_.push_back(msg->data);
    }
    void callback_sinistro(const example_interfaces::msg::Float64MultiArray::SharedPtr msg) {
        std::lock_guard<std::mutex> lock(mutex_);
        stima_sinistra_ricevuta.push_back(msg->data);
    }

    std::vector<std::vector<double>> trasposta(const std::vector<std::vector<double>>& matrice) {
        int righe = matrice.size();
        int colonne = matrice[0].size();

        std::vector<std::vector<int>> matrice_trasposta(colonne, std::vector<int>(righe, 0));

        for (int i = 0; i < righe; ++i) {
            for (int j = 0; j < colonne; ++j) {
                matrice_trasposta[j][i] = matrice[i][j];
            }
        }

        return matrice_trasposta;
    }

    std::vector<std::vector<double>> moltiplicaMatrici(
        const std::vector<std::vector<double>>& A,
        const std::vector<std::vector<double>>& B) {
        int righeA = A.size();
        int colonneA = A[0].size();
        int colonneB = B[0].size();
    
        if (colonneA != B.size()) {
            throw std::invalid_argument("errore");
        }
    
        std::vector<std::vector<double>> C(righeA, std::vector<double>(colonneB, 0));
    
        for (int i = 0; i < righeA; ++i) {
            for (int j = 0; j < colonneB; ++j) {
                for (int k = 0; k < colonneA; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    
        return C;
    }
    std::vector<std::vector<double>> appendColonne(const std::vector<std::vector<double>>& matrice,const std::vector<std::vector<double>>& vettore2) {
        std::vector<double> vettore;
        int righe = matrice.size();
        int colonne = matrice[0].size();
        for (int j = 0; j < colonne; ++j) {
            for (int i = 0; i < righe; ++i) {
                vettore.push_back(matrice[i][j]);
            }
        }
        for (int k = 0; k < colonne; ++k) {
            vettore.push_back(vettore2[k][1]);
        }
        return vettore;
    }
    void crea_stima() {
            std::lock_guard<std::mutex> lock(mutex_);
        if (!misura_ricevuta.empty()) {
       	    std::vector<std::vector<double>>  V0 = 1/8 * Jpri + moltiplicaMatrici(moltiplicaMatrici(trasposta(H),R),H);
            std::vector<std::vector<double>>  v0 = 1/8 * moltiplicaMatrici(Jpri,misura_ricevuta) + moltiplicaMatrici(moltiplicaMatrici(trasposta(H),R),misura_ricevuta);
            std::vector<std::vector<double>>  V = appendColonne(V0,v0);

            auto messaggio = example_interfaces::msg::Float64MultiArray();
            messaggio.data = V;
            pub_Vv->publish(messaggio);
    }}

    // void aggiorna_consenso() {
    //     std::lock_guard<std::mutex> lock(mutex_);
       
    // }
    std::vector<std::vector<double>> Jpri = {
        {100, 0, 0, 0, 0, 0},
        {0, 100, 0, 0, 0, 0},
        {0, 0, 100, 0, 0, 0},
        {0, 0, 0, 10, 0, 0},
        {0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 10}
    };

    std::vector<std::vector<double>> H = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };
    
    std::vector<std::vector<double>> R = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    
    double valore_corrente_;
    std::vector<double> valori_ricevuti_;
    std::mutex mutex_;
    rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr pub_Vv;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr sub_misura;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr subscriber_sinistro_;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr subscriber_destro_;
    std::vector<std::vector<double>> stima_destra_ricevuta_;
    std::vector<std::vector<double>> stima_sinistra_ricevuta;
    std::vector<std::vector<double>> misura_ricevuta;

    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NodoConsenso>());
    rclcpp::shutdown();
    return 0;
}
