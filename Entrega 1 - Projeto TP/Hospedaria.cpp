#include "Hospedaria.h"

void Hospedaria::set_PrecoDeHotel(float preco){

    this -> PrecoDoHotel = PrecoDoHotel;
}

void Hospedaria::set_TipoDeHotel(int TipoDeHotel){

    this -> TipoDeHotel = TipoDeHotel;
}

float Hospedaria::get_PrecoDoHotel() const{

    return PrecoDoHotel;
}

int Hospedaria::get_TipoDeHotel() const{

    return TipoDeHotel;
}
