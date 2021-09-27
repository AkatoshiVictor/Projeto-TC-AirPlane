#ifndef PRODUTO_H
#define PRODUTO_H

class Produto{
    private:
        string Tipo_de_viagem; //colocar pra agencia
        string Data_de_ida;
        string Data_de_volta;
        string Origem;
        string Destino;
        string TempoDaViagem;

        string teste;

        float PrecoDaPassagem;

        string TagPassagem;

        string const Regiao_Norte [7] = {"BELÉM", "BOA VISTA", "MACAPÁ", "MANAUS", "PALMAS", "PORTO VELHO", "RIO BRANCO"};
        string const Regiao_Nordeste [9] = {"ARACAJU","FORTALEZA", "JOÃO PESSOA", "MACEIÓ", "NATAL","RECIFE", "SALVADOR", "SÃO LUÍS", "TERESINA"};
        string const Regiao_CentroOeste [4] = {"BRASÍLIA", "CUIABÁ", "CAMPO GRANDE", "GOIÂNIA"};
        string const Regiao_Sudeste [4] = {"BELO HORIZONTE", "RIO DE JANEIRO", "SÃO PAULO", "VITÓRIA"};
        string const Regiao_Sul [3] = {"CURITIBA", "FLORIANÓPOLIS", "PORTO ALEGRE"};

    public:
        Produto(string, string, int, int, int);

        void set_Data_de_ida(string);
        void set_Data_de_volta(string);

        string get_Data_de_ida();
        string get_Data_de_volta();

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

        void ImprimirDadosDaViagem();

};

#endif // PRODUTO_H
