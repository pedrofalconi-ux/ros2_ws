#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/float64_multi_array.hpp>
#include "robot_ras_decision/msg/movement.hpp"
#include "robot_ras_decision/srv/set_velocity.hpp"

using namespace std::chrono_literals;

class MovementControl : public rclcpp::Node
{
public:
  MovementControl() : Node("movement_control")
  {
    sub_movimento_ = this->create_subscription<robot_ras_decision::msg::Movement>(
      "movement", 10, std::bind(&MovementControl::callback_movimento, this, std::placeholders::_1));

    pub_motor1_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/motor1/commands", 10);
    pub_motor2_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/motor2/commands", 10);

    srv_velocidade_ = this->create_service<robot_ras_decision::srv::SetVelocity>(
      "velocidade", std::bind(&MovementControl::callback_velocidade, this, std::placeholders::_1, std::placeholders::_2));

    velocidade_ = 1.2f;
    distancia_entre_rodas_ = 1.0f;  // distância entre rodas em metros
  }

private:
  void callback_velocidade(
    const std::shared_ptr<robot_ras_decision::srv::SetVelocity::Request> req,
    std::shared_ptr<robot_ras_decision::srv::SetVelocity::Response> res)
  {
    velocidade_ = req->velocity;
    res->success = true;
    res->message = "Velocidade atualizada!";
  }

  void callback_movimento(const robot_ras_decision::msg::Movement &msg)
  {
    std::string direcao = msg.direction;
    float distancia = msg.distance;
    float angulo = msg.angle;

    float tempo = 0.1f;
    float vel_motor1 = 0.0f;
    float vel_motor2 = 0.0f;

    if (direcao == "front")
    {
      if (distancia / velocidade_ > 0.1f)
        tempo = distancia / velocidade_;
      vel_motor1 = velocidade_;
      vel_motor2 = velocidade_;
    }
    else if (direcao == "left" || direcao == "right")
    {
      if (angulo != 0.0f)
      {
        float velocidade_angular = velocidade_ / distancia_entre_rodas_;
        tempo = std::abs(angulo) / velocidade_angular;

        if (direcao == "left")
        {
          vel_motor1 = -velocidade_;
          vel_motor2 = velocidade_;
        }
        else // right
        {
          vel_motor1 = velocidade_;
          vel_motor2 = -velocidade_;
        }
      }
      else
      {
        if (distancia / velocidade_ > 0.1f)
          tempo = distancia / velocidade_;

        if (direcao == "left")
        {
          vel_motor1 = -velocidade_;
          vel_motor2 = velocidade_;
        }
        else // right
        {
          vel_motor1 = velocidade_;
          vel_motor2 = -velocidade_;
        }
      }
    }
    else if (direcao == "stop")
    {
      vel_motor1 = 0.0f;
      vel_motor2 = 0.0f;
      cancelar_timers();
      enviar_comando_motor(vel_motor1, vel_motor2);
      return;
    }

    cancelar_timers();
    enviar_comando_motor(vel_motor1, vel_motor2);

    auto timer = this->create_wall_timer(
      std::chrono::duration<double>(tempo),
      [this]() {
        enviar_comando_motor(0, 0);
        RCLCPP_INFO(this->get_logger(), "Parou após o tempo.");
      });

    timers_ativos_.push_back(timer);
  }

  void enviar_comando_motor(float vel1, float vel2)
  {
    std_msgs::msg::Float64MultiArray motor1;
    std_msgs::msg::Float64MultiArray motor2;

    motor1.data = {vel1};
    motor2.data = {vel2};

    pub_motor1_->publish(motor1);
    pub_motor2_->publish(motor2);
  }

  void cancelar_timers()
  {
    for (auto &t : timers_ativos_)
      t->cancel();
    timers_ativos_.clear();
  }

  rclcpp::Subscription<robot_ras_decision::msg::Movement>::SharedPtr sub_movimento_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_motor1_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_motor2_;
  rclcpp::Service<robot_ras_decision::srv::SetVelocity>::SharedPtr srv_velocidade_;

  std::vector<rclcpp::TimerBase::SharedPtr> timers_ativos_;
  float velocidade_;
  float distancia_entre_rodas_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MovementControl>());
  rclcpp::shutdown();
  return 0;
}