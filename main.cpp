#include <Arduino.h>
#include "Miura\automovel.h"

Carro muira = Carro();

void setup()
{
  Serial.begin(9600);
  muira.set_cambio(5);
  muira.set_cinto_moto(6);
  muira.set_cinto_carona(7);
  muira.set_ignicao(9);
  muira.set_ignicao_feedback(8);
  muira.set_partida(13);
  muira.set_porta_moto(3);
  muira.set_porta_carona(4);
}

void loop()
{
  muira.monitora_cinto_moto();
  muira.monitora_cinto_carona();
  muira.monitora_cambio();
  muira.monitora_porta_moto();
  muira.monitora_porta_carona();
  if (Serial.available())
  {
    String comando = Serial.readStringUntil('\n');
    if (comando == "ligar")
    {
      muira.liga_chave();
      comando = "";
    }
    else if (comando == "partida")
    {
      muira.dar_partida(2000);
      comando = "";
    }
    else if (comando == "desligar")
    {
      muira.desligar();
    }
  }
}
