#ifndef AVIAO_H
#define AVIAO_H

class Aviao:public Produto{
    private:

        float TaxaEconomica_Aviao = 1.20;
        float TaxaExecutiva_Aviao = 2.40;
        float TaxaPrimeiraClasse_Aviao = 4.80;

        int Distancia_Aviao;

        int Aereo_Brasilia[27] = {1292, 1592, 624, 2496, 0, 2667, 2107, 3370, 3620, 2562, 2503, 3067, 1110, 1485, 1932,
					 1775, 620, 1619, 1900, 1657, 2246, 933, 1060, 1524, 873, 1313, 947};

        int Aereo_Florianopolis[27] = {2892, 3500, 1301, 5128, 1673, 1298, 1986, 300, 0, 3838, 1493, 3485, 4033, 3168, 4443, 3662, 2336
						, 476, 3442, 3375, 3976, 1144, 2682, 3537, 705, 3450, 1597};

		int Aereo_Joao_Pessoa[27] = {611, 2161, 2171, 6593, 2245, 3357, 3366, 3188, 3485, 688, 2442, 0, 2639, 395,
					      5808, 185, 2253, 3889, 4822, 120, 5356, 2448, 949, 1660, 2770, 1224, 2001};

		int Aereo_Manaus[27] = {5215, 5298, 3951, 785, 3590, 3051, 2357, 4036, 4443, 5763, 3291, 5808, 3015, 5491, 0, 5985,
					4141, 4563, 901, 5698, 1445, 4374, 5009, 5335, 3971, 5267, 4476};

		int Aereo_Sao_Paulo[27] = {2187, 2933, 586, 4756, 1015, 1014, 1614, 408, 705, 3127, 926, 2770, 3447, 2453, 3971,
					    2947, 1776, 1109, 3070, 2660, 3604, 429, 1926, 2970, 0, 2792, 882};

    public:
        Aviao(int, int, int, int, int, int, int, int, int, int, int);

        void Define_Distancia_Aviao(int, int);
        int Retorna_Distancia_Aviao();

        void Calcula_TempoDeViagemAviao();
        void Calcula_PrecoDaPassagemAviao(int);

        void ImprimePassagemAviao();

};

#endif // AVIAO_H
