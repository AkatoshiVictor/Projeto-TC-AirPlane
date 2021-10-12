#ifndef CRUZEIRO_H
#define CRUZEIRO_H

class Cruzeiro:public Produto{
    private:
        int TaxaFixaDeDistancia = 5.00;

        int PacoteDeLuaDeMel;

        int Distancia_Cruzeiro;

        int maritimo_Salvador[2]={9036, 4949};

    public:
        Cruzeiro(string,int,int,int,int,int,int,int,string,string,int,int);
        Cruzeiro(int, int, int, int, int, int, int, int, int, int, int);


        void set_PacoteLuaDeMel(int);


        int get_PacoteLuaDeMel();

        void Define_Distancia_Cruzeiro(int);
        int Retorna_Distancia_Cruzeiro();

        void Calcula_TempoDeViagemCruzeiro();
        void Calcula_PrecoDaPassagemCruzeio();

        void ImprimePassagemCruzeiro();

        void set_Distancia(int);


};

#endif // CRUZEIORO_H
