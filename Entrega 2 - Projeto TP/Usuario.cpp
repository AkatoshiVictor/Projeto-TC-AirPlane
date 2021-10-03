#include "Usuario.h"

Usuario::Usuario(){

}

Usuario::Usuario(string email, string senha, string nome_completo, string data_nascimento,
                 string endereco, string telefone, string telefone_familiar, string documento,
                 int classe_do_funcionario, float orcamento, string acompanhante, float gastos_totais
                 , float salario){

    this-> email = email;
    this-> senha = senha;

    this-> nome_completo = nome_completo;
    this-> data_nascimento = data_nascimento;
    this-> endereco = endereco;
    this-> telefone = telefone;
    this-> telefone_familiar = telefone_familiar;
    this-> documento = documento;
    this-> classe_do_funcionario = classe_do_funcionario;

    this-> orcamento = orcamento;
    this-> acompanhante = acompanhante;
    this-> gastos_totais = gastos_totais;

    this-> salario = salario;
}

void Usuario::set_email(string email){

    this-> email = email;
}

void Usuario::set_senha(string senha){

    this-> senha = senha;
}

void Usuario::set_nome_completo(string nome_completo){

    this-> nome_completo = nome_completo;
}

void Usuario::set_data_nascimento(string data_nascimento){

    this-> data_nascimento = data_nascimento;
}

void Usuario::set_endereco(string endereco){

    this-> endereco = endereco;
}

void Usuario::set_telefone(string telefone){

    this-> telefone = telefone;
}

void Usuario::set_telefone_familiar(string telefone_familiar){

    this-> telefone_familiar = telefone_familiar;
}

void Usuario::set_documento(string documento){

    this-> documento = documento;
}

void Usuario::set_classe_do_funcionario(int classe_do_funcionario){

    this-> classe_do_funcionario = classe_do_funcionario;
}

void Usuario::set_orcamento(float orcamento){

    this-> orcamento = orcamento;
}

void Usuario::set_acompanhante(string acompanhante){

    this-> acompanhante = acompanhante;
}

void Usuario::set_gastos_totais(float gastos_totais){

    this-> gastos_totais = gastos_totais;
}

void Usuario::set_salario(float salario){

    this-> salario = salario;
}


string Usuario::get_email() const{

    return email;
}

string Usuario::get_senha() const{

    return senha;
}

string Usuario::get_nome_completo() const{

    return nome_completo;
}

string Usuario::get_data_nascimento() const{

    return data_nascimento;
}

string Usuario::get_endereco() const{

    return endereco;
}

string Usuario::get_telefone() const{

    return telefone;
}

string Usuario::get_telefone_familiar() const{

    return telefone_familiar;
}

string Usuario::get_documento() const{

   return documento;
}

int Usuario::get_classe_do_funcionario() const{

    return classe_do_funcionario;
}

float Usuario::get_orcamento() const{

    return orcamento;
}

string Usuario::get_acompanhante() const{

    return acompanhante;
}

float Usuario::get_gastos_totais() const{

    return gastos_totais;
}

float Usuario::get_salario() const{

    return salario;
}

void Usuario::testar_classe(){ //Será excluída no projeto!

    cout << "Email: " << get_email() << endl << "Senha: " << get_senha() << endl << "Nome completo: "
    << get_nome_completo() << endl << "Data de nascimento: " << get_data_nascimento() << endl
    << "Endereço: " << get_endereco() << endl << "Telefone: " << get_telefone() << endl << "Telefone familiar: "
    << get_telefone_familiar() << endl << "Documento: " << get_documento() << endl << "Classe do funcionário: "
    << get_classe_do_funcionario() << endl << "Orçamento: " << get_orcamento() << endl << "Acompanhante: "
    << get_acompanhante() << endl  << "Gastos totais: " << get_gastos_totais() << endl;

}
