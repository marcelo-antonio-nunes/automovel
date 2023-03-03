#ifndef _CARRO_H
#define _CARRO_H

class Carro
{
public:
    Carro();
    void liga_chave();                               // feito
    void set_ignicao(int ignicao);                   // feito
    void set_ignicao_feedback(int ignicao_feedback); // feito
    void set_partida(int partida);                   // feito
    void set_cinto_moto(int cinto_moto);             // feito
    void set_cinto_carona(int cinto_carona);         // feito
    void set_cambio(int cambio);                     // feito
    void set_porta_moto(int porta_moto);             // feito
    void set_porta_carona(int porta_carona);         // feito
    int set_vidro_carona(int vidro);                 // feito
    int set_vidro_moto(int vidro);                   // feito
    int set_vidro_passageiro_direta(int vidro);      // feito
    int set_vidro_passageiro_esquerda(int vidro);    // feito
    void dar_partida(int tempo);                     // feito
    bool monitora_cinto_moto();                      // feito
    bool monitora_cinto_carona();                    // feito
    bool monitora_cambio();                          // feito
    bool monitora_porta_moto();                      // feito
    bool monitora_porta_carona();                    // feito
    bool abrir_vidro(int vidro, int fimDeCurso);     // feito
    bool fechar_vidro(int vidro, int fimDeCurso);    // feito
    bool ligar_farol_baixo();                        // feito
    bool desligar_farol_baixo();                     // feito
    bool ligar_farol_alto();                         // feito
    bool desligar_farol_alto();                      // feito
    bool desligar();                                 // feito

private:
    int _IGNICAO;
    int _PARTIDA;
    int _IGNICAO_FEEDBACK;
    int _CINTO_MOTO;
    int _CINTO_CARONA;
    int _CAMBIO;
    int _SENSOR_DO_COMBUSTIVEL;
    int _SENSOR_DO_OLEO;
    int _SENSOR_DA_TEMPERATURA;
    int _SENSROR_DA_AGUA;
    int _LIMPADO_DE_PARABRISA;
    int _SETA_DIREITA;
    int _SETA_ESQUERDA;
    int _FAROIS_BAIXO;
    int _FAROIS_ALTO;
    int _PORTA_MOTO;
    int _PORTA_CARONA;
    int _PORTA_PASSAGEIRO_DIREITA;
    int _PORTA_PASSAGEIRO_ESQUERDA;
    int _PORTA_MALA;
    int _VIDRO_MOTO;
    int _VIDRO_CARONA;
    int _VIDRO_PASSAGEIRO_DIREITO;
    int _VIDRO_PASSAGEIRO_ESQUERDO;
};

#endif // _MIURA_H
