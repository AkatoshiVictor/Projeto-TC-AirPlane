#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario{

private:
    string email; //Tida como o registro para o funcionário, já que cada e-mail é único.
    string senha;

    string nome_completo;
    string data_nascimento;
    string endereco;
    string telefone;
    string telefone_familiar;
    string documento;
    int classe_do_funcionario;

    string Tag = "";

    float orcamento;
    string acompanhante;
    float gastos_totais;

    float salario;

public:

    Usuario ();
    Usuario(string, string, string, string, string, string, string, string, int, float, string, float, float);
    Usuario(string, string, string, string, string, string, string, string, int);

    void set_email(string);
    void set_senha(string);

    void set_nome_completo(string);
    void set_data_nascimento(string);
    void set_endereco(string);
    void set_telefone(string);
    void set_telefone_familiar(string);
    void set_documento(string);
    void set_classe_do_funcionario(int);
    void set_orcamento(float);
    void set_acompanhante(string);
    void set_gastos_totais(float);
    void set_salario(float);
    void set_tag(string);

    string get_email() const;
    string get_senha() const;

    string get_nome_completo() const;
    string get_data_nascimento() const;
    string get_endereco() const;
    string get_telefone() const;
    string get_telefone_familiar() const;
    string get_documento() const;
    int get_classe_do_funcionario() const;
    float get_orcamento() const;
    string get_acompanhante() const;
    float get_gastos_totais() const;
    float get_salario() const;
    string get_Tag() const;

    void testar_classe(); //Somente para teste da atividade proposta.

};

#endif // USUARIO_H_INCLUDED
