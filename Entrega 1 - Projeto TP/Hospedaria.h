#ifndef HOSPEDARIA_H_INCLUDED
#define HOSPEDARIA_H_INCLUDED

class Hospedaria{
    private:
        int TipoDeHotel;
        float PrecoDoHotel;

    public:

        void set_TipoDeHotel(int);
        void set_PrecoDeHotel(float);

        int get_TipoDeHotel() const;
        float get_PrecoDoHotel() const;

};

#endif // HOSPEDARIA_H_INCLUDED
