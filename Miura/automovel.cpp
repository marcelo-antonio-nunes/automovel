#include "automovel.h"
#include <Arduino.h>

// Construtor da classe Carro
Carro::Carro()
{
}

// Configuração do pino de ignição
void Carro::set_ignicao(int ignicao)
{
    _IGNICAO = ignicao;
    pinMode(_IGNICAO, OUTPUT);
}

// Configuração do pino de feedback da ignição
void Carro::set_ignicao_feedback(int ignicao_feedback)
{
    _IGNICAO_FEEDBACK = ignicao_feedback;
    pinMode(_IGNICAO_FEEDBACK, INPUT);
}

// Configuração do pino de partida
void Carro::set_partida(int partida)
{
    _PARTIDA = partida;
    pinMode(_PARTIDA, OUTPUT);
}

// Configuração do pino do cinto de segurança do motorista
void Carro::set_cinto_moto(int cinto_moto)
{
    _CINTO_MOTO = cinto_moto;
    pinMode(_CINTO_MOTO, INPUT_PULLUP);
}

// Configuração do pino do cinto de segurança do passageiro
void Carro::set_cinto_carona(int cinto_carona)
{
    _CINTO_CARONA = cinto_carona;
    pinMode(_CINTO_CARONA, INPUT_PULLUP);
}

// Configuração do pino do câmbio
void Carro::set_cambio(int cambio)
{
    _CAMBIO = cambio;
    pinMode(_CAMBIO, INPUT_PULLUP);
}

// Configuração do pino da porta do motorista
void Carro::set_porta_moto(int porta_moto)
{
    _PORTA_MOTO = porta_moto;
    pinMode(_PORTA_MOTO, INPUT_PULLUP);
}

// Configuração do pino da porta do passageiro
void Carro::set_porta_carona(int porta_carona)
{
    _PORTA_CARONA = porta_carona;
    pinMode(_PORTA_MOTO, INPUT_PULLUP);
}

// Liga a chave de ignição
void Carro::liga_chave()
{
    // Armazena o tempo em que a função foi chamada
    unsigned long tempoInicial = millis();
    // Define a duração máxima de tentativa de ligar a chave
    unsigned long duracaoMaxima = 2000;

    // Verifica se o feedback da ignição é baixo (ignição desligada)
    while (digitalRead(_IGNICAO_FEEDBACK) == 0)
    {
        digitalWrite(_IGNICAO, HIGH);
        Serial.print("[{\"say\": \"Chave ligada!");

        // Aguarda um curto período de tempo para permitir que o relé da ignição se feche
        unsigned long duracaoEspera = 100;
        while (millis() - tempoInicial < duracaoEspera)
        {
            // Aguarda até que a duração de espera seja atingida
        }

        // Verifica novamente o feedback da ignição
        if (digitalRead(_IGNICAO_FEEDBACK) == 0)
        {
            // Se a ignição ainda estiver desligada, tenta ligar novamente
            // Verifica se o tempo máximo de tentativa de ligar a chave foi atingido
            if (millis() - tempoInicial >= duracaoMaxima)
            {
                // Tempo máximo atingido, não é possível ligar a chave
                Serial.print("[{\"say\": \"Não foi possível ligar a chave!");
                return;
            }
        }
        else
        {
            Serial.print("[{\"say\": \"Ignição ligada com sucesso!");
            // Ignição ligada com sucesso
            break;
        }
    }
};

// Dá partida no carro
void Carro::dar_partida(int tempo)
{
    // Verifica se a ignição está ligada, se os cintos de segurança estão colocados, e se o câmbio está na posição neutra
    if (digitalRead(_IGNICAO_FEEDBACK) == 1)
    {
        Serial.print("[{\"say\": \"Dando partida...");
        digitalWrite(_PARTIDA, HIGH);
        delay(tempo);
        digitalWrite(_PARTIDA, LOW);
    }
    else
    {
        // Se as condições acima não forem atendidas, tenta ligar a chave novamente e dar partida novamente depois de 2 segundos
        liga_chave();
        dar_partida(2000);
    }
};
// Método para monitorar se o cinto do motorista está solto.
bool Carro::monitora_cinto_moto()
{
    if (digitalRead(_CINTO_MOTO)) // Verifica se o pino _CINTO_MOTO está em nível alto.
    {
        Serial.print("[{\"say\": \"Cinto do motorista solto"); // Imprime mensagem no console serial.
        delay(2000);                                           // Aguarda 2 segundos.
        return 1;                                              // Retorna verdadeiro (1) indicando que o cinto está solto.
    }
    return 0; // Retorna falso (0) indicando que o cinto está preso.
}

// Método para monitorar se o cinto do carona está solto.
bool Carro::monitora_cinto_carona()
{
    if (digitalRead(_CINTO_CARONA)) // Verifica se o pino _CINTO_CARONA está em nível alto.
    {
        Serial.print("[{\"say\": \"Cinto do carona solto"); // Imprime mensagem no console serial.
        delay(2000);                                        // Aguarda 2 segundos.
        return 1;                                           // Retorna verdadeiro (1) indicando que o cinto está solto.
    }
    return 0; // Retorna falso (0) indicando que o cinto está preso.
}

// Método para monitorar se o câmbio está engatado.
bool Carro::monitora_cambio()
{
    if (digitalRead(_CAMBIO)) // Verifica se o pino _CAMBIO está em nível alto.
    {
        Serial.print("[{\"say\": \"Cambio engatado!!!"); // Imprime mensagem no console serial.
        delay(2000);                                     // Aguarda 2 segundos.
        return 1;                                        // Retorna verdadeiro (1) indicando que o câmbio está engatado.
    }
    return 0; // Retorna falso (0) indicando que o câmbio está desengatado.
}

// Método para monitorar se a porta do motorista está aberta.
bool Carro::monitora_porta_moto()
{
    if (digitalRead(_PORTA_MOTO)) // Verifica se o pino _PORTA_MOTO está em nível alto.
    {
        Serial.print("[{\"say\": \"Porta do motorista aberta!!!"); // Imprime mensagem no console serial.
        delay(2000);                                               // Aguarda 2 segundos.
        return 1;                                                  // Retorna verdadeiro (1) indicando que a porta está aberta.
    }
    return 0; // Retorna falso (0) indicando que a porta está fechada.
}

// Método para monitorar se a porta do carona está aberta.
bool Carro::monitora_porta_carona()
{
    if (digitalRead(_PORTA_CARONA)) // Verifica se o pino _PORTA_CARONA está em nível alto.
    {
        Serial.print("[{\"say\": \"Porta do motorista carona!!!"); // Imprime mensagem no console serial.
        delay(2000);                                               // Aguarda 2 segundos.
        return 1;                                                  // Retorna verdadeiro (1) indicando que a porta está aberta.
    }
    return 0; // Retorna falso (0) indicando que a porta está fechada.
}

// Método para desligar o carro.
bool Carro::desligar()
{
    if (!digitalRead(_IGNICAO))
    {
        Serial.print("[{\"say\": \"O carro ja esta ligado!");
        return 1;
    }
    else
    {
        digitalWrite(_IGNICAO, LOW);
    }
    return 0;
}
int Carro::set_vidro_carona(int vidro)
{
    _VIDRO_CARONA = vidro;
    pinMode(_VIDRO_CARONA, OUTPUT);
    return vidro;
}
int Carro::set_vidro_moto(int vidro)
{
    _VIDRO_MOTO = vidro;
    pinMode(_VIDRO_MOTO, OUTPUT);
    return vidro;
}
int Carro::set_vidro_passageiro_direta(int vidro)
{
    _VIDRO_PASSAGEIRO_DIREITO = vidro;
    pinMode(_VIDRO_PASSAGEIRO_DIREITO, OUTPUT);
    return vidro;
}
int Carro::set_vidro_passageiro_esquerda(int vidro)
{
    _VIDRO_PASSAGEIRO_ESQUERDO = vidro;
    pinMode(_VIDRO_PASSAGEIRO_ESQUERDO, OUTPUT);
    return vidro;
}
bool Carro::abrir_vidro(int vidro, int fimDeCurso)
{
    pinMode(fimDeCurso, INPUT_PULLUP);
    if (!fimDeCurso)
    {
        digitalWrite(vidro, HIGH);
        delay(2000);
        digitalWrite(vidro, LOW);
    }
    return fimDeCurso;
}
bool Carro::fechar_vidro(int vidro, int fimDeCurso)
{
    pinMode(fimDeCurso, INPUT_PULLUP);
    if (!fimDeCurso)
    {
        digitalWrite(vidro, HIGH);
        delay(2000);
        digitalWrite(vidro, LOW);
    }
    return fimDeCurso;
}
bool Carro::ligar_farol_baixo()
{
    pinMode(_FAROIS_BAIXO, OUTPUT);
    digitalWrite(_FAROIS_BAIXO, HIGH);
    return _FAROIS_BAIXO;
}
bool Carro::desligar_farol_baixo()
{
    pinMode(_FAROIS_ALTO, OUTPUT);
    digitalWrite(_FAROIS_ALTO, LOW);
    return _FAROIS_ALTO;
}
bool Carro::ligar_farol_alto()
{
    pinMode(_FAROIS_ALTO, OUTPUT);
    digitalWrite(_FAROIS_ALTO, HIGH);
    return _FAROIS_ALTO;
}
bool Carro::desligar_farol_alto()
{
    pinMode(_FAROIS_ALTO, OUTPUT);
    digitalWrite(_FAROIS_ALTO, LOW);
    return _FAROIS_ALTO;
}