### Este é um código em C++ para controlar um carro usando um microcontrolador Arduino. Ele inclui a definição de uma classe chamada "Carro" que tem várias funções para configurar e controlar os pinos do microcontrolador que estão conectados aos diferentes componentes do carro, como a ignição, o motor de arranque, os cintos de segurança e as portas.

### A classe Carro tem um construtor padrão vazio e vários métodos para configurar os pinos e controlar o carro. Os métodos incluem:

* set_ignicao: configura o pino de ignição
* set_ignicao_feedback: configura o pino de feedback da ignição
* set_partida: configura o pino de partida
* set_cinto_moto: configura o pino do cinto de segurança do motorista
* set_cinto_carona: configura o pino do cinto de segurança do passageiro
* set_cambio: configura o pino do câmbio
* set_porta_moto: configura o pino da porta do motorista
* set_porta_carona: configura o pino da porta do passageiro
* liga_chave: liga a chave de ignição
* dar_partida: dá partida no carro
* monitora_cinto_moto: monitora se o cinto do motorista está solto
* monitora_cinto_carona: monitora se o cinto do passageiro está solto
O código também inclui a biblioteca Arduino.h e uma função main vazia, já que o código é projetado para ser usado como uma biblioteca que pode ser incorporada em outros programas.

### Em resumo, este código é uma classe para controlar um carro usando um microcontrolador Arduino e é um exemplo de como a eletrônica pode ser usada para automatizar e controlar sistemas mecânicos.

``` C++ Arduino
#include <Arduino.h>
#include "Miura\automovel.h"

Carro muira = Carro(); // Cria um objeto do tipo Carro com o nome "muira"

void setup()
{
  Serial.begin(9600); // Inicia a comunicação serial com a taxa de transmissão de dados de 9600 bits por segundo
  muira.set_cambio(5); // Define o pino usado para monitorar o câmbio do carro como 5
  muira.set_cinto_moto(6); // Define o pino usado para monitorar o cinto de segurança do motorista como 6
  muira.set_cinto_carona(7); // Define o pino usado para monitorar o cinto de segurança do passageiro como 7
  muira.set_ignicao(9); // Define o pino usado para controlar a ignição do carro como 9
  muira.set_ignicao_feedback(8); // Define o pino usado para monitorar o feedback da ignição do carro como 8
  muira.set_partida(13); // Define o pino usado para controlar a partida do carro como 13
  muira.set_porta_moto(3); // Define o pino usado para monitorar a porta do motorista como 3
  muira.set_porta_carona(4); // Define o pino usado para monitorar a porta do passageiro como 4
}

void loop()
{
  muira.monitora_cinto_moto(); // Verifica se o cinto de segurança do motorista está conectado
  muira.monitora_cinto_carona(); // Verifica se o cinto de segurança do passageiro está conectado
  muira.monitora_cambio(); // Verifica a posição do câmbio do carro
  muira.monitora_porta_moto(); // Verifica se a porta do motorista está aberta ou fechada
  muira.monitora_porta_carona(); // Verifica se a porta do passageiro está aberta ou fechada
  if (Serial.available()) // Verifica se há dados disponíveis na porta serial
  {
    String comando = Serial.readStringUntil('\n'); // Lê o comando da porta serial até encontrar o caractere '\n' (nova linha)
    if (comando == "ligar") // Se o comando for "ligar"
    {
      muira.liga_chave(); // Ligar o carro
      comando = ""; // Limpa a variável comando
    }
    else if (comando == "partida") // Se o comando for "partida"
    {
      muira.dar_partida(2000); // Inicia a partida com um tempo de espera de 2000ms (2 segundos)
      comando = ""; // Limpa a variável comando
    }
    else if (comando == "desligar") // Se o comando for "desligar"
    {
      muira.desligar(); // Desliga o carro
    }
  }
}


### This is a C++ code to control a car using an Arduino microcontroller. It includes the definition of a class called "Car" that has several functions to set up and control the microcontroller pins that are connected to the different components of the car, such as the ignition, starter motor, seat belts, and doors.
### The Car class has an empty default constructor and several methods to set up the pins and control the car. The methods include:
* set_ignition: sets up the ignition pin
* set_ignition_feedback: sets up the ignition feedback pin
* set_starter: sets up the starter pin
* set_driver_seatbelt: sets up the driver's seatbelt pin
* set_passenger_seatbelt: sets up the passenger's seatbelt pin
* set_gear_shift: sets up the gear shift pin
* set_driver_door: sets up the driver's door pin
* set_passenger_door: sets up the passenger's door pin
* turn_on_ignition: turns on the ignition key
* start_engine: starts the car engine
* monitor_driver_seatbelt: monitors if the driver's seatbelt is unbuckled
* monitor_passenger_seatbelt: monitors if the passenger's seatbelt is unbuckled

### The code also includes the Arduino.h library and an empty main function, since the code is designed to be used as a library that can be incorporated into other programs.

### In summary, this code is a class to control a car using an Arduino microcontroller and is an example of how electronics can be used to automate and control mechanical systems.










