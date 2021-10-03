#ifndef PRODUTO_H
#define PRODUTO_H

class Produto{
    private:
        string Tipo_de_viagem; //colocar pra agencia

        int Horario;

        struct Data_de_ida{
            int Dia_de_ida;
            int Mes_de_ida;
            int Ano_de_ida;
        };

        struct Data_de_volta{
            int Dia_de_volta;
            int Mes_de_volta;
            int Ano_de_volta;
        };

        string Origem;
        string Destino;
        string TempoDaViagem;

        float PrecoDaPassagem;
        string TagPassagem;
        string DefinicaoUnica;

    public:
        Produto();
        Produto(int, int, int, int, int, int, int, int, int, int);

        Data_de_ida Embarque;
        Data_de_volta Retorno;

        void set_dia_de_ida(int);
        void set_mes_de_ida(int);
        void set_ano_de_ida(int);

        void set_dia_de_volta(int);
        void set_mes_de_volta(int);
        void set_ano_de_volta(int);

        int get_dia_de_ida();
        int get_mes_de_ida();
        int get_ano_de_ida();

        int get_dia_de_volta();
        int get_mes_de_volta();
        int get_ano_de_volta();

        void Escolha_Tipo_de_viagem(int);
        void Escolha_Origem(int);
        void Escolha_Destino(int);

        string Retorna_Tipo_de_viagem();
        string Retorna_Origem();
        string Retorna_Destino();

        virtual void Define_TempoDeViagem(string);
        virtual void Define_PrecoDaPassagem(float);

        float Retorna_PrecoDaPassagem();
        string Retorna_TempoDeViagem();

        void Define_TagPassagem();
        string Retorna_TagPassagem();


        void set_Horario(int);
        int get_Horario();

        void ImprimirDadosDaViagem();

};

#endif // PRODUTO_H
