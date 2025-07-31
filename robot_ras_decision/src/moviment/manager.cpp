#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/range.hpp>
#include "robot_ras_decision/msg/movement.hpp"

class Manager : public rclcpp::Node
{
public:
  Manager() : Node("manager")
  {
    pub_movement_ = this->create_publisher<robot_ras_decision::msg::Movement>("/movement", 10);

    sub_sensor_frente_ = this->create_subscription<sensor_msgs::msg::Range>(
        "sensor_range/front", 10, std::bind(&Manager::callback_frente, this, std::placeholders::_1));
    sub_sensor_esquerda_ = this->create_subscription<sensor_msgs::msg::Range>(
        "sensor_range/left", 10, std::bind(&Manager::callback_esquerda, this, std::placeholders::_1));
    sub_sensor_direita_ = this->create_subscription<sensor_msgs::msg::Range>(
        "sensor_range/right", 10, std::bind(&Manager::callback_direita, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100), std::bind(&Manager::timer_callback, this));
  }

private:
  rclcpp::Publisher<robot_ras_decision::msg::Movement>::SharedPtr pub_movement_;

  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_sensor_frente_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_sensor_esquerda_;
  rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_sensor_direita_;

  rclcpp::TimerBase::SharedPtr timer_;

  float distancia_frente_ = 0.0;
  float distancia_esquerda_ = 0.0;
  float distancia_direita_ = 0.0;

  void callback_frente(const sensor_msgs::msg::Range::SharedPtr msg) { distancia_frente_ = msg->range; }
  void callback_esquerda(const sensor_msgs::msg::Range::SharedPtr msg) { distancia_esquerda_ = msg->range; }
  void callback_direita(const sensor_msgs::msg::Range::SharedPtr msg) { distancia_direita_ = msg->range; }
void timer_callback()
{
  robot_ras_decision::msg::Movement msg;

  float velocidade_linear = 1.2f; 
  // DISTÂNCIAS SEGURA PRA IR RETO
  float distancia_segura_frente = 0.6f; 

  float tempo_minimo_lateral = 0.2f; // MEDIDA DE SEGURANÇA
  float tolerancia_tempo_centralizacao = 0.05f; // DIFERENCA DE TEMPO LATERAL PRA SE CONSIDERAR CENTRALIZADO OU N
  float tempo_alvo_centralizacao = 0.3f; // TEMPO DOS 2 LADOS QUE DEFINE O EQUILIBRIO ENTRE AS DISTANCIAS
  float angulo_correcao_lateral_tempo = 0.3f; 
  
  // BECO SEM SAIDA: 
  float distancia_apertada_canto_frente = 0.25f;
  float distancia_apertada_canto_direita = 0.25f;
  float angulo_curva_90 = 1.57f; // 90 graus em radianos

  // CALCULO D TEMPO, E USO DE OPERADOR TERNÁRIO PARA EVITAR DIVISÃO POR ZERO
  float tempo_frente = (distancia_frente_ > 0.05f) ? distancia_frente_ / velocidade_linear : 1000.0f;
  float tempo_esquerda = (distancia_esquerda_ > 0.05f) ? distancia_esquerda_ / velocidade_linear : 1000.0f;
  float tempo_direita = (distancia_direita_ > 0.05f) ? distancia_direita_ / velocidade_linear : 1000.0f;

  // FRENTE E DIREITA ESTÃO APERTADAS
  if (distancia_frente_ < distancia_apertada_canto_frente && distancia_direita_ < distancia_apertada_canto_direita)
  {
    msg.direction = "left";
    msg.distance = 0.2f;
    msg.angle = angulo_curva_90; 
  }
  // APENAS A FRENTE ESTÁ BLOQUEADA ---> VAI SE MOVER PRA ONDE TEM MAIS TEMPO LIVRE ATE A COLISAO
  else if (distancia_frente_ < distancia_segura_frente)
  {
    if (tempo_esquerda > tempo_direita + tolerancia_tempo_centralizacao) 
    {
      msg.direction = "left";
      msg.distance = 0.2f;
      msg.angle = angulo_curva_90; 
    }
    else if (tempo_direita > tempo_esquerda + tolerancia_tempo_centralizacao)
    {
      msg.direction = "right";
      msg.distance = 0.2f;
      msg.angle = -angulo_curva_90; 
    }
    else // OS DOIS LADOS ESTAO APERTADOS IGUAL
    {
      msg.direction = "left";
      msg.distance = 0.0f; 
      msg.angle = angulo_curva_90;
    }
  }
  else
  {
    // A frente está livre, O Objetivo é manter os tempos dos lados iguais

    // Calcular a diferença de tempo entre os lados
    float diferenca_tempo_lateral = tempo_esquerda - tempo_direita;

    if (diferenca_tempo_lateral > tolerancia_tempo_centralizacao)
    {
      // tempo_esquerda > tempo_direita (robô tem mais tempo livre à esquerda, está perto da parede direita)
      // Precisa virar para a ESQUERDA para se afastar da parede direita e igualar os tempos.
      msg.direction = "left";
      msg.distance = velocidade_linear * 0.05f; 
      msg.angle = angulo_correcao_lateral_tempo; 
    }
    else if (diferenca_tempo_lateral < -tolerancia_tempo_centralizacao)
    {
      msg.direction = "right";
      msg.distance = velocidade_linear * 0.05f; 
      msg.angle = -angulo_correcao_lateral_tempo; 
    }
    else //SE 0 TEMPO ESTA CENTRALIZADO, VAI PRA FRENTE SEM DÓ
    {
      msg.direction = "front";
      msg.distance = distancia_frente_; 
      msg.angle = 0.0f; 
    }
  }

  pub_movement_->publish(msg);
}
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Manager>());
  rclcpp::shutdown();
  return 0;
}