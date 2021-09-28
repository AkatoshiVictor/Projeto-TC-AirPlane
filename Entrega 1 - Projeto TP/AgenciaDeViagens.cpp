#include "AgenciaDeViagens.h"

AgenciaDeViagens::AgenciaDeViagens(){


}

void AgenciaDeViagens::set_posicao_atual(int posicao_atual){

    this->posicao_atual = posicao_atual;
}

void AgenciaDeViagens::RelatorioGeral(){


}

bool AgenciaDeViagens::Login(int opcao){

    string email, senha;

    cout<<"E-mail\n -> ";
    cin>>email;

    cout<<"Senha\n -> ";
    cin>>senha;

    return AutenticadorDeLogin(email, senha, opcao);
}

bool AgenciaDeViagens::AutenticadorDeLogin(string email, string senha, int opcao){

    if (opcao == 0){

        if (email == "empresaviagenstp@airplanes.com" && senha == "senhadificil"){
                cout << "Login efetuado com sucesso!" << endl;
                system("Pause");
        return true;
        }
    }

    else if (opcao == 1){

        if (email == "empresaviagenstpg1@airplanes.com" && senha == "gerente01"){
                cout << "Login efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Norte" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg2@airplanes.com" && senha == "gerente02"){
                cout << "Login efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Nordeste" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg3@airplanes.com" && senha == "gerente03"){
                cout << "Login efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Centro Oeste" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg4@airplanes.com" && senha == "gerente04"){
                cout << "Login efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Sudeste" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg5@airplanes.com" && senha == "gerente05"){
                cout << "Login efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Sul" << endl;
                system("Pause");
            return true;
        }
    }

    else if (opcao == 2){

        for(unsigned i(0); i<Funcionario.size(); i++){

            if(email==Funcionario[i].get_email() && senha==Funcionario[i].get_senha()){
                email_atual = email;
                senha_atual = senha;
                return true;
            }
        }
    }

    return false;
}

void AgenciaDeViagens::CadastraFuncionario(){

    string email, senha, nome_completo, data_nascimento, endereco, telefone, telefone_familiar, documento;

    int classe_do_funcionario;

    float salario;
    system("cls");
    cout << "RH - Admissões -> Funcionários" << endl;
    int opcao = 1;
    while(1){
        cout << "Insira o email: ";
        cin >> email;

        if(VerificaDisponibilidadeDeEmail(email,opcao)){
            break;
        }
        else{
            cout << "O e-mail inserido já está cadastrado, tente outro por favor!" << endl;
            system("Pause");
            system("cls");
        }
    }

    cout << "\nInsira a senha: ";
    cin >> senha;

    cin.ignore();
    cout << "\nInsira o nome completo: ";
    getline(cin, nome_completo);

    cout << "\nInsira a data de nascimento: ";
    cin >> data_nascimento;

    cin.ignore();
    cout << "\nInsira o endereço: ";
    getline(cin, endereco);

    cout << "\nInsira o telefone: ";
    cin >> telefone;

    cout << "\nInsira o telefone de um familiar: ";
    cin >> telefone_familiar;

    cout << "\nInsira o documento do funcionário (RG/CPF/CNH): ";
    cin >> documento;

    while(1){

    cout << "\nInsira a classe do funcionário (1, 2 ou 3): ";
    cin >> classe_do_funcionario;

    if (!(classe_do_funcionario != 1 && classe_do_funcionario != 2 && classe_do_funcionario != 3)){
        salario = CalculaSalario(classe_do_funcionario);
        break;
    }
    else
        cout << "A classe inserida é inválida!" << endl;
        system("Pause");
        system("cls");
    }


    float orcamento = 0;
    string acompanhante = "0";
    float gastos_totais = 0;

    Usuario auxiliar (email, senha, nome_completo, data_nascimento,
                            endereco, telefone, telefone_familiar, documento,
                            classe_do_funcionario, orcamento, acompanhante, gastos_totais, salario);
    cout << "Cadastro realizado com sucesso!" << endl;

    Funcionario.push_back(auxiliar);

}

float AgenciaDeViagens::CalculaSalario(int classe_do_funcionario){

    if (classe_do_funcionario == 1){
        return 2000;
    }

    else if(classe_do_funcionario == 2){
        return 2500;
    }

    else {
        return 4500;
    }

}

void AgenciaDeViagens::DemiteFuncionario(){

    cout << "RH - Demissões -> Funcionários" << endl;
    posicao_atual = -1;
    char confirmacao;

    RetornaPosicaoFuncionario();

    if (posicao_atual!=-1){
            ExibirFuncionario();
            while(1){
                cout << "\nDeseja confimar a demissão desse funcionário? (s/n)" << endl;
                cin >> confirmacao;

                if (confirmacao == 's'){
                    Funcionario.erase(Funcionario.begin()+posicao_atual);
                    cout << "Demissão concluída!" << endl;
                    cout << "Redirecionando ao menu principal!" << endl;
                    system("Pause");
                    system("cls");
                    break;
                }
                else if(confirmacao == 'n'){
                    cout << "Demissão cancelada!" << endl;
                    cout << "Redirecionando ao menu principal!" << endl;
                    system("Pause");
                    system("cls");
                    break;
                }
                else{
                    cout << "Opção inválida, por favor insira uma das opções apresentadas!" << endl;
                }
            }
    }

}

int AgenciaDeViagens::RetornaPosicaoFuncionario(){

    string email;

    cout << "Digite o e-mail do funcionário à procurar: ";
    cin >> email;

    int opcao = 1;

    if (!(VerificaDisponibilidadeDeEmail(email, opcao))){
        for (int i = 0; i<Funcionario.size(); i++){
            if (Funcionario[i].get_email() == email)
                posicao_atual = i;
                return i;
        }
    }
    else
        cout << "\nO e-mail inserido não está cadastrado no sistema!" << endl;

    system ("Pause");
    system("cls");
}

int AgenciaDeViagens::RetornaPosicaoParaFuncionario(string email){//Utilizada para mudança de dados do funcionário

        for (int i = 0; i<Funcionario.size(); i++){
            if (Funcionario[i].get_email() == email_atual)
                posicao_atual = i;
        }

    system ("Pause");
    system("cls");
}

void AgenciaDeViagens::ExibirFuncionario(){

    cout << "\nE-mail: " << Funcionario[posicao_atual].get_email();
    cout << "\nNome Completo: " << Funcionario[posicao_atual].get_nome_completo();
    cout << "\nData de nascimento: " << Funcionario[posicao_atual].get_data_nascimento();
    cout << "\nEndereço: " << Funcionario[posicao_atual].get_endereco();
    cout << "\nTelefone: " << Funcionario[posicao_atual].get_telefone();
    cout << "\nTelefone do familiar: " << Funcionario[posicao_atual].get_telefone_familiar();
    cout << "\nDocumento: " << Funcionario[posicao_atual].get_documento();
    cout << "\nClasse: " << Funcionario[posicao_atual].get_classe_do_funcionario();
    cout << "\nSalário: " << Funcionario[posicao_atual].get_salario() << endl;
}

void AgenciaDeViagens::AlterarDadosFuncionario(int a){
    string senha;
    string newnome, newdocumento, newendereco, newtelefone, newtelefone_familiar;
    int auxiliar;
    auxiliar = RetornaPosicaoParaFuncionario("a");

    switch (a){

        case 0:{

            cout << "Digite sua senha atual"  << endl;
            cin >> senha;

            if(senha == senha_atual){

                cout << "Digite sua nova senha\n-> ";
                cin >> senha;
                senha_atual = senha;

                Funcionario[auxiliar].set_senha(senha);
            }
            else{
                cout << "Senha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 1:{

            cout << "Mudança de nome"  << endl;

            cout << "Digite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "Digite seu novo nome\n-> ";
                cin >> newnome;

                Funcionario[auxiliar].set_nome_completo(newnome);
            }
            else{
                cout << "Senha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 2:{

            cout << "Alteração de endereço"  << endl;

            cout << "Digite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "Digite seu novo nome\n-> ";
                cin >> newendereco;

                Funcionario[auxiliar].set_endereco(newendereco);
            }
            else{
                cout << "Senha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 3:{

            cout << "Mudança de telefone" << endl;

            cout << "Digite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "Digite seu novo telefone\n-> ";
                cin >> newtelefone;

                Funcionario[auxiliar].set_telefone(newtelefone);
            }
            else{
                cout << "Senha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 4:{

            cout << "Mudança de telefone do familiar" << endl;
            cout << "Digite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "Digite o novo telefone do familiar\n-> ";
                cin >> newtelefone_familiar;

                Funcionario[auxiliar].set_telefone_familiar(newtelefone_familiar);
            }
            else{
                cout << "Senha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 5:{

            cout << "Alteração de documento" << endl;
            cout << "Digite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "Digite o seu novo documento\n-> ";
                cin >> newdocumento;

                Funcionario[auxiliar].set_documento(newdocumento);
            }
            else{
                cout << "Senha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;
    }
}

void AgenciaDeViagens::CadastraCliente(){

    string email, senha, nome_completo, data_nascimento, endereco, telefone, telefone_familiar, documento;

    cout << "Bem vindo ao cadastramento de Clientes" << endl;
    int opcao = 2;
    while(1){

        cout << "Insira o seu e-mail: ";
        cin >> email;

        if(VerificaDisponibilidadeDeEmail(email, opcao)){
            break;
        }
        else{
            cout << "O e-mail inserido já está cadastrado, tente outro por favor!" << endl;
            system("Pause");
            system("cls");
        }
    }

    cout << "\nInsira a sua senha: ";
    cin >> senha;

    cin.ignore();
    cout << "\nInsira o nome completo: ";
    getline(cin, nome_completo);

    cout << "\nInsira a data de nascimento: ";
    cin >> data_nascimento;

    cin.ignore();
    cout << "\nInsira o endereço: ";
    getline(cin, endereco);

    cout << "\nInsira o telefone: ";
    cin >> telefone;

    cout << "\nInsira o telefone de um familiar: ";
    cin >> telefone_familiar;

    cout << "\nInsira o documento do funcionário (RG/CPF/CNH): ";
    cin >> documento;
}

bool AgenciaDeViagens::VerificaDisponibilidadeDeEmail(string email, int opcao){

    if (opcao == 1){

        for (unsigned i = 0; i<Funcionario.size(); i++){

            if (Funcionario[i].get_email() == email)
                return false;
        }
        return true;
    }

    else{
        for (unsigned i = 0; i<Cliente.size(); i++){

            if (Cliente[i].get_email() == email)
                return false;
        }
        return true;
    }
}

void AgenciaDeViagens::FuncaoGeradorDePassagem(int a){


}

void AgenciaDeViagens::CalculaFaturamento(){


}

void AgenciaDeViagens::CalculaLucro(){


}

void AgenciaDeViagens::CalculaGasto(){

    //Cada gerente ganha 8000
    //O salário dos funcionários será adicionado conforme forem adicionados novos funcionários

    Gasto = 5*8000; // Número de gerentes multiplicado pelo salário.

    for (unsigned i = 0; i<Funcionario.size(); i++){
        Gasto = Gasto + Funcionario[i].get_salario();
    }
    cout << "O gasto mensal é de: R$" << Gasto << " (Não aplicável em dezembro)";
    cout << "O gasto anual previsto é de: R$" << Gasto*13;
    cout << "Uma projeção pros próximos 5 anos é de: R$" << Gasto*13*5;
}

float AgenciaDeViagens::get_Faturamento() const{

    return Faturamento;
}

float AgenciaDeViagens::get_Lucro()const{

    return Lucro;
}

float AgenciaDeViagens::get_Gasto() const{

    return Gasto;
}

AgenciaDeViagens::~AgenciaDeViagens(){

    fstream DadosCliente;

    DadosCliente.open("DadosCliente.txt", ios::out);


    if(DadosCliente){
        for(int i=0; i<Cliente.size();i++){

            DadosCliente<<Cliente[i].get_nome_completo();
            DadosCliente<<Cliente[i].get_data_nascimento();
            DadosCliente<<Cliente[i].get_endereco();
            DadosCliente<<Cliente[i].get_telefone();
            DadosCliente<<Cliente[i].get_telefone_familiar();
            DadosCliente<<Cliente[i].get_documento();
            DadosCliente<<Cliente[i].get_classe_do_funcionario();
            DadosCliente<<Cliente[i].get_orcamento();
            DadosCliente<<Cliente[i].get_acompanhante();
            DadosCliente<<Cliente[i].get_gastos_totais();
            DadosCliente<<Cliente[i].get_salario();

        }
    }

    Passagens[0].Retornar_passagens();

    DadosCliente.close();

}
