# 🤖 ROS 2 Workspace: `robot_ras_decision`

O `robot_ras_decision` é um pacote ROS 2 projetado para o controle de movimento de um robô, utilizando dados de sensores ultrassônicos para navegação e desvio de obstáculos.

## ✨ Funcionalidades Principais

- 📡 **Processamento de Sensores**: Processa dados de sensores ultrassônicos (frontal, esquerdo, direito e traseiro) para detectar obstáculos em tempo real.
- 🔄 **Tomada de Decisão**: Decide a próxima ação do robô — seguir em frente, virar ou parar — para evitar colisões.
- ⚙️ **Controle de Movimento**: Controla os motores com base em comandos de distância e ângulo, garantindo movimentos suaves e precisos.
- ⚡ **Ajuste Dinâmico de Velocidade**: Oferece um serviço para ajustar a velocidade linear do robô dinamicamente durante a execução.

---

## 🗂 Estrutura do Projeto

| Arquivo / Nó        | Função Principal                                               |
| ------------------- | -------------------------------------------------------------- |
| `Manager`           | Recebe dados dos sensores e publica comandos de movimento.     |
| `MovementControl`   | Recebe comandos de movimento e gera os sinais para os motores. |
| `msg/Movement.msg`  | Mensagem para definir a direção, distância e ângulo do robô.   |
| `srv/SetVelocity.srv` | Serviço para ajustar a velocidade do robô em tempo real.       |

---

## 📨 Mensagens e Serviços Personalizados

### Mensagem: `Movement.msg`
Define o movimento a ser executado pelo robô.

```proto
string direcao       # "front", "left", "right" ou "stop"
float32 distancia    # Distância para se mover (em metros)
float32 angulo       # Ângulo de curva (em radianos, positivo = esquerda, negativo = direita)
````

### Serviço: `SetVelocity.srv`

Permite o ajuste da velocidade linear do robô.

**Requisição:**

```proto
float32 velocity     # Nova velocidade linear do robô
---
```

**Resposta:**

```proto
bool success         # True se o ajuste foi bem-sucedido
string message       # Mensagem informativa sobre o resultado
```

-----

## ⚙️ Instalação

### Pré-requisitos

  - **ROS 2 Humble** (ou versão compatível) instalado e configurado.
      - [Guia oficial de instalação do ROS 2](https://docs.ros.org/en/humble/Installation.html)
  - Ferramentas de build do ROS 2: `colcon`, `rosdep`, `build-essential`.

### Passos para Instalar Dependências

Navegue até a raiz do seu workspace e execute os seguintes comandos para instalar as dependências do projeto:

```bash
rosdep update
rosdep install --from-paths src --ignore-src -r -y
```

-----

## 🛠️ Build e Execução

### Build do Workspace

Na raiz do seu workspace, compile o pacote:

```bash
colcon build
```

Após a compilação, não se esqueça de carregar as variáveis de ambiente do workspace:

```bash
source install/setup.bash
```

### Executar os Nós

Abra dois terminais separados e execute os nós `Manager` e `MovementControl`:

**Terminal 1:**

```bash
ros2 run robot_ras_decision Manager
```

**Terminal 2:**

```bash
ros2 run robot_ras_decision MovementControl
```

-----

## 🚀 Uso

O sistema opera da seguinte forma:

1.  O nó `Manager` escuta os tópicos dos sensores ultrassônicos para receber as leituras de distância:

      - `/sensor_range/front`
      - `/sensor_range/left`
      - `/sensor_range/right`

2.  Com base nessas leituras, o `Manager` publica comandos de movimento no tópico `/movement` (do tipo `Movement.msg`).

3.  O nó `MovementControl` escuta o tópico `/movement`, calcula o tempo e a velocidade necessários para cada ação e publica os comandos de baixo nível para os motores nos seguintes tópicos:

      - `/motor1/commands`
      - `/motor2/commands`

<!-- end list -->

```
```
