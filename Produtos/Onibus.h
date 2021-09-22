#ifndef ONIBUS_H
#define ONIBUS_H

class Onibus:public Produto{
    private:

        int TaxaEconomica_Onibus = 2;
        int TaxaExecutiva_Onibus = 3;

        bool seguro;
        string bagagem;
        int poltrona; //Escrita em arquivo

        int Distancia_Onibus;

        int const Terrestre_Brasilia[27] = {1652, 2120, 716, 4275, 0, 1134, 1133, 1366, 1673, 2200, 209, 2245, 2499, 1930,
					   3490, 2422, 973, 2027, 2589, 2135, 3123, 1148, 1446, 2157, 1015, 1789, 1239};

        int const Terrestre_Florianopolis[27] = {2892, 3500, 1301, 5128, 1673, 1298, 1986, 300, 0, 3838, 1493, 3485, 4033, 3168, 4443, 3662, 2336
						, 476, 3442, 3375, 3976, 1144, 2682, 3537, 705, 3450, 1597};

		int const Terrestre_Joao_Pessoa[27] = {611, 2161, 2171, 6593, 2245, 3357, 3366, 3188, 3485, 688, 2442, 0, 2639, 395,
					      5808, 185, 2253, 3889, 4822, 120, 5356, 2448, 949, 1660, 2770, 1224, 2001};

		int const Terrestre_Manaus[27] = {5215, 5298, 3951, 785, 3590, 3051, 2357, 4036, 4443, 5763, 3291, 5808, 3015, 5491, 0, 5985,
					4141, 4563, 901, 5698, 1445, 4374, 5009, 5335, 3971, 5267, 4476};

		int const Terrestre_Sao_Paulo[27] = {2187, 2933, 586, 4756, 1015, 1014, 1614, 408, 705, 3127, 926, 2770, 3447, 2453, 3971,
					    2947, 1776, 1109, 3070, 2660, 3604, 429, 1926, 2970, 0, 2792, 882};

    public:
        Onibus(string, string, int, int, int, int);//, int, int);

        void Define_Distancia_Onibus(int, int);
        int Retorna_Distancia_onibus();

        void Calcula_TempoDeViagemOnibus();
        void Calcula_PrecoDaPassagemOnibus(int);

        void ImprimirPassagemOnibus();

};

#endif // ONIBUS_H
