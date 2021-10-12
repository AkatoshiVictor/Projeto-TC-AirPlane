#include "AgenciaDeViagens.h"

GeradorDePassagens ger;

void AgenciaDeViagens::set_posicao_atual(int posicao_atual){

    this->posicao_atual = posicao_atual;
}

void AgenciaDeViagens::RelatorioGeral(){


}

bool AgenciaDeViagens::LoginFuncionario(int opcao){

    string email, senha;

    cout<<"E-mail\n -> ";
    cin>>email;

    cout<<"Senha\n -> ";
    cin>>senha;

    return AutenticadorDeLoginFuncionario(email, senha, opcao);
}

bool AgenciaDeViagens::AutenticadorDeLoginFuncionario(string email, string senha, int opcao){

    if (opcao == 0){

        if (email == "empresaviagenstp@airplanes.com" && senha == "senhadificil"){
                cout << "Login efetuado com sucesso!" << endl;
                cout << "Bem vindo, Presidente" << endl;
                system("Pause");
        return true;
        }
    }

    else if (opcao == 1){

        if (email == "empresaviagenstpg1@airplanes.com" && senha == "gerente01"){
                cout << "\nLogin efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Norte\n" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg2@airplanes.com" && senha == "gerente02"){
                cout << "\nLogin efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Nordeste\n" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg3@airplanes.com" && senha == "gerente03"){
                cout << "\nLogin efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Centro Oeste\n" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg4@airplanes.com" && senha == "gerente04"){
                cout << "\nLogin efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Sudeste\n" << endl;
                system("Pause");
            return true;
        }

        else if (email == "empresaviagenstpg5@airplanes.com" && senha == "gerente05"){
                cout << "\nLogin efetuado com sucesso!" << endl;
                cout << "Bem vindo, Gerente do Sul\n" << endl;
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

bool AgenciaDeViagens::LoginCliente(){

    string email, senha;

    cout<<"E-mail\n -> ";
    cin>>email;

    cout<<"Senha\n -> ";
    cin>>senha;

    return AutenticadorDeLoginCliente(email, senha);
}

bool AgenciaDeViagens::AutenticadorDeLoginCliente(string email, string senha){


    for(unsigned i(0); i<Cliente.size(); i++){

        if(email==Cliente[i].get_email() && senha==Cliente[i].get_senha()){
            email_atual = email;
            senha_atual = senha;
            return true;
        }
    }

}

void AgenciaDeViagens::CadastraFuncionario(){

    string email, senha, nome_completo, data_nascimento,
        endereco, telefone, telefone_familiar, documento;

    int classe_do_funcionario;

    float salario;
    system("cls");
    cout << "RH - Admissões -> Funcionários" << endl;
    int opcao = 1;
    while(1){
        cout << "Insira o email: (sem espaços) ";
        cin >> email;

        if(VerificaDisponibilidadeDeEmailFuncionario(email)){
            break;
        }
        else{
            cout << "O e-mail inserido já está cadastrado, tente outro por favor!" << endl;
            system("Pause");
            system("cls");
        }
    }

    cout << "\nInsira a senha: (sem espaços) ";
    cin >> senha;

    cin.ignore();
    cout << "\nInsira o nome completo: ";
    getline(cin, nome_completo);

    cout << "\nInsira a data de nascimento: (sem espaços)";
    cin >> data_nascimento;

    cin.ignore();
    cout << "\nInsira o endereço: ";
    getline(cin, endereco);

    cout << "\nInsira o telefone (sem espaços): ";
    cin >> telefone;

    cout << "\nInsira o telefone de um familiar (sem espaços): ";
    cin >> telefone_familiar;

    cout << "\nInsira o documento do funcionário (RG/CPF/CNH) (sem espaços): ";
    cin >> documento;


    bool controle = true;

    cin.exceptions(istream::failbit);
    do{
        try {
            cout << "\nInsira a classe do funcionário (1, 2 ou 3): ";
            cin >> classe_do_funcionario;
            controle = true;

            if(classe_do_funcionario<1||classe_do_funcionario>3){
                cout << "\nEsse número precisa ser 1,2 ou 3" << endl;
                controle = false;
            }

            salario = CalculaSalario(classe_do_funcionario);

        }catch (ios_base::failure &fail) {
            controle = false;
            cout << "\n\nERRO 0xC0000005 - Caractere inválido, por favor, digite sua entrada como números inteiros.\n" << endl;
            cin.clear();
            string digitada;
            getline(cin, digitada);
        }
    }while(controle == false);

    float orcamento = 0;
    string acompanhante = " ";
    float gastos_totais = 0;

    Usuario auxiliar (email, senha, nome_completo, data_nascimento,
                            endereco, telefone, telefone_familiar, documento,
                            classe_do_funcionario, orcamento, acompanhante, gastos_totais, salario);
    cout << "\n\nCadastro realizado com sucesso!\n\n" << endl;

    Funcionario.push_back(auxiliar);


}


void AgenciaDeViagens::CadastraCliente(){

    string email, senha, nome_completo, data_nascimento,
        endereco, telefone, telefone_familiar, documento;

    int opcao = 1;
    while(1){
        cout << "Insira o email: (sem espaços) ";
        cin >> email;

        if(VerificaDisponibilidadeDeEmailCliente(email)){
            break;
        }
        else{
            cout << "O e-mail inserido já está cadastrado, tente outro por favor!" << endl;
            system("Pause");
            system("cls");
        }

    }
    cout << "\nInsira a senha: (sem espaços) ";
    cin >> senha;

    cin.ignore();
    cout << "\nInsira o nome completo: ";
    getline(cin, nome_completo);

    cout << "\nInsira a data de nascimento: (sem espaços) ";
    cin >> data_nascimento;

    cin.ignore();
    cout << "\nInsira o endereço: ";
    getline(cin, endereco);

    cout << "\nInsira o telefone: (sem espaços) ";
    cin >> telefone;

    cout << "\nInsira o telefone de um familiar: (sem espaços) ";
    cin >> telefone_familiar;

    cout << "\nInsira o seu documento (RG/CPF/CNH): (sem espaços) ";
    cin >> documento;


    float orcamento = 0;
    string acompanhante = " ";
    float gastos_totais = 0;

    Usuario auxiliar (email, senha, nome_completo, data_nascimento,
                            endereco, telefone, telefone_familiar, documento,
                            0, orcamento, acompanhante, gastos_totais, 0);

    Cliente.push_back(auxiliar);
    cout << "\n\nCadastro realizado com sucesso!\n\n" << endl;

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
                    cout << "\n\nDemissão concluída!" << endl;
                    cout << "Redirecionando ao menu principal!\n" << endl;
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


    if (!(VerificaDisponibilidadeDeEmailFuncionario(email))){
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

int AgenciaDeViagens::RetornaPosicaoParaFuncionario(){//Utilizada para mudança de dados do funcionário


        for (int i = 0; i<Funcionario.size(); i++){
            if (Funcionario[i].get_email() == email_atual)
                posicao_atual = i;
        }

    system("cls");
}

void AgenciaDeViagens::ExibirFuncionario(){

    if(Funcionario.size()>0){

        cout << "\nE-mail: " << Funcionario[posicao_atual].get_email();
        cout << "\nNome Completo: " << Funcionario[posicao_atual].get_nome_completo();
        cout << "\nData de nascimento: " << Funcionario[posicao_atual].get_data_nascimento();
        cout << "\nEndereço: " << Funcionario[posicao_atual].get_endereco();
        cout << "\nTelefone: " << Funcionario[posicao_atual].get_telefone();
        cout << "\nTelefone do familiar: " << Funcionario[posicao_atual].get_telefone_familiar();
        cout << "\nDocumento: " << Funcionario[posicao_atual].get_documento();
        cout << "\nClasse: " << Funcionario[posicao_atual].get_classe_do_funcionario();
        cout << "\nSalário: \n" << Funcionario[posicao_atual].get_salario() << endl;
    }
}

void AgenciaDeViagens::AlterarDadosFuncionario(int a){
    string senha;
    string newnome, newdocumento, newendereco, newtelefone, newtelefone_familiar;
    int auxiliar;
    auxiliar = RetornaPosicaoParaFuncionario();

    switch (a){

        case 0:{

            cout << "Digite sua senha atual"  << endl;
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite sua nova senha\n-> ";
                cin >> senha;
                senha_atual = senha;

                Funcionario[auxiliar].set_senha(senha);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 1:{

            cout << "Mudança de nome"  << endl;

            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo nome\n-> ";
                cin.ignore();
                getline(cin,newnome);

                Funcionario[auxiliar].set_nome_completo(newnome);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 2:{

            cout << "Alteração de endereço"  << endl;

            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo enredeço\n-> ";
                cin.ignore();
                getline(cin,newendereco);


                Funcionario[auxiliar].set_endereco(newendereco);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 3:{

            cout << "Mudança de telefone" << endl;

            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo telefone\n-> ";
                cin >> newtelefone;

                Funcionario[auxiliar].set_telefone(newtelefone);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 4:{

            cout << "Mudança de telefone do familiar" << endl;
            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite o novo telefone do familiar\n-> ";
                cin >> newtelefone_familiar;

                Funcionario[auxiliar].set_telefone_familiar(newtelefone_familiar);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 5:{

            cout << "Alteração de documento" << endl;
            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite o seu novo documento\n-> ";
                cin >> newdocumento;

                Funcionario[auxiliar].set_documento(newdocumento);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;
    }
}

void AgenciaDeViagens::ExibirCliente(){
    if(Cliente.size()>0){

        cout << "\nE-mail: " << Cliente[posicao_atual].get_email();
        cout << "\nNome Completo: " << Cliente[posicao_atual].get_nome_completo();
        cout << "\nData de nascimento: " << Cliente[posicao_atual].get_data_nascimento();
        cout << "\nEndereço: " << Cliente[posicao_atual].get_endereco();
        cout << "\nTelefone: " << Cliente[posicao_atual].get_telefone();
        cout << "\nTelefone do familiar: " << Cliente[posicao_atual].get_telefone_familiar();
        cout << "\nDocumento: " << Cliente[posicao_atual].get_documento() << endl;
    }
}

int AgenciaDeViagens::RetornaPosicaoCliente(){
    string email;

    cout << "Digite o e-mail do cliente à procurar: ";
    cin >> email;


    if (!(VerificaDisponibilidadeDeEmailCliente(email))){
        for (int i = 0; i<Cliente.size(); i++){
            if (Cliente[i].get_email() == email)
                posicao_atual = i;
                return i;
        }
    }
    else
        cout << "\nO e-mail inserido não está cadastrado no sistema!" << endl;

    system ("Pause");
    system("cls");
}

int AgenciaDeViagens::RetornaPosicaoParaCliente(){
    for (int i = 0; i<Cliente.size(); i++){
            if (Cliente[i].get_email() == email_atual)
                posicao_atual = i;
        }

    system("cls");
}

void AgenciaDeViagens::AlterarDadosCliente(int a){
    string senha, email;
    string newnome, newdocumento, newendereco, newtelefone, newtelefone_familiar;
    int auxiliar;
    auxiliar = RetornaPosicaoParaFuncionario();

    switch (a){
        case 0:{

            cout << "Digite sua senha atual\n->";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo E-mail\n-> ";
                cin >> email;


                Cliente[auxiliar].set_email(email);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }

        }break;

        case 1:{

            cout << "Digite sua senha atual\n->"  << endl;
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite sua nova senha\n-> ";
                cin >> senha;
                senha_atual = senha;

                Cliente[auxiliar].set_senha(senha);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 2:{

            cout << "Mudança de nome"  << endl;

            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo nome\n-> ";
                cin.ignore();
                getline(cin,newnome);

                Cliente[auxiliar].set_nome_completo(newnome);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 3:{

            cout << "Alteração de endereço"  << endl;

            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo endereço\n-> ";
                cin.ignore();
                getline(cin,newendereco);

                Cliente[auxiliar].set_endereco(newendereco);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 4:{

            cout << "Mudança de telefone" << endl;

            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite seu novo telefone\n-> ";
                cin >> newtelefone;

                Cliente[auxiliar].set_telefone(newtelefone);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 5:{

            cout << "Mudança de telefone do familiar" << endl;
            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite o novo telefone do familiar\n-> ";
                cin >> newtelefone_familiar;

                Cliente[auxiliar].set_telefone_familiar(newtelefone_familiar);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;

        case 6:{

            cout << "Alteração de documento" << endl;
            cout << "\nDigite sua senha atual\n-> ";
            cin >> senha;

            if(senha == senha_atual){

                cout << "\nDigite o seu novo documento\n-> ";
                cin >> newdocumento;

                Cliente[auxiliar].set_documento(newdocumento);
            }
            else{
                cout << "\nSenha incorreta! Voltando ao menu de opções" << endl;
                system("Pause");
                system("cls");
            }
        }
        break;
    }
}

bool AgenciaDeViagens::VerificaDisponibilidadeDeEmailFuncionario(string email){


        for (unsigned i = 0; i<Funcionario.size(); i++){

            if (Funcionario[i].get_email() == email)
                return false;
        }
        return true;
}

bool AgenciaDeViagens::VerificaDisponibilidadeDeEmailCliente(string email){

        for (unsigned i = 0; i<Cliente.size(); i++){

            if (Cliente[i].get_email() == email)
                return false;
        }
        return true;
}

void AgenciaDeViagens::CalculaFaturamento(){
    Faturamento = ger.PassaOFaturamentoTotal();
}

void AgenciaDeViagens::CalculaLucro(){
    Lucro = Faturamento - Gasto;

}

void AgenciaDeViagens::ImprimiReceita(){
    CalculaGasto();
    CalculaFaturamento();
    CalculaLucro();

    system("cls");
    cout << "#########################################################" << endl;
    cout << "RELATÓRIO DE RECEITA GERAL DA AGÊNCIA DE VIAGENS AIRPLANE" << endl;
    cout << "#########################################################" << endl << endl;
    cout << "Gastos da empresa: " << Gasto << endl;
    cout << "Faturamento da empresa: " << Faturamento << endl;
    cout << "Lucro geral da empresa: " << Lucro << endl << endl;
    system("pause");
}

void AgenciaDeViagens::PassaParaOGeradorDePassagens(int DiaDeIda, int MesDeIda, int AnoDeIda, int DiaDeVolta, int MesDeVolta, int AnoDeVolta,
int TipoDePassagem, int Regiao, int Cidade, int TipoDeViagem, int Origem, int Turno){


    if((DiaDeIda == 999)||(MesDeIda == 999)||(AnoDeIda == 999)||(DiaDeVolta == 999)||(MesDeVolta == 999)||(AnoDeVolta == 999)||
    (TipoDePassagem == 999)||(Regiao == 999)||(Cidade == 999)||(TipoDeViagem == 999)||(Origem == 999)){
        cout << endl << "POR FAVOR PREENCHA A PASSAGEM COMPLETAMENTE ANTES DE FINALIZAR" << endl;
    }
    else{
        switch(TipoDeViagem){

            /*Para o avião*/
            case 0:{
                system("cls");
                cout<<"####################"<<endl<< "AIRPLANES - PASSAGEM AVIÃO" <<endl<<"####################"<<endl;
                int Destino = DecodificadorDeDestino(Regiao,Cidade);
                //cout << endl << endl << Destino << endl << endl;
                Aviao PassagemAviao(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDeViagem, Origem, Destino, TipoDePassagem, Turno);
                ger.AgendandoPassagemAviao(PassagemAviao);
                PassagemAviao.ImprimePassagemAviao();

                /*
                if(PassagemAviao.Retorna_TagPassagem()!="")
                    Cliente[posicao_atual].set_tag(PassagemAviao.Retorna_TagPassagem());*/
            }
            break;
            /*Para o ônibus*/
            case 1:{
                system("cls");
                cout<<"####################"<<endl<< "AIRPLANES - PASSAGEM ÔNIBUS" <<endl<<"####################"<<endl;
                int Destino = DecodificadorDeDestino(Regiao,Cidade);
                //cout << endl << endl << Destino << endl << endl;
                Onibus PassagemOnibus(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDeViagem, Origem, Destino, TipoDePassagem, Turno);
                ger.AgendandoPassagemOnibus(PassagemOnibus);
                PassagemOnibus.ImprimePassagemOnibus();

                /*if(PassagemOnibus.Retorna_TagPassagem()!="")
                    Cliente[posicao_atual].set_tag(PassagemOnibus.Retorna_TagPassagem());*/
            }
            break;
            /*Para o cruzeiro*/
            case 2:{
                system("cls");
                cout<<"####################"<<endl<< "AIRPLANES - PACOTE CRUZEIRO" <<endl<<"####################"<<endl;
                /*Cruzeiro(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta,
                 AnoDeVolta, TipoDeViagem, Origem, Destino, Turno, int Cabine, int PacoteLuaDeMel)*/
                int Destino = Regiao;
                Cruzeiro PassagemCruzeiro(DiaDeIda, MesDeIda, AnoDeIda, DiaDeVolta, MesDeVolta, AnoDeVolta, TipoDeViagem, Origem, Destino, TipoDePassagem, 2);
                ger.AgendandoPassagemCruzeiro(PassagemCruzeiro);
                PassagemCruzeiro.ImprimePassagemCruzeiro();

                /*if(PassagemCruzeiro.Retorna_TagPassagem()!="")
                    Cliente[posicao_atual].set_tag(PassagemCruzeiro.Retorna_TagPassagem());*/

            }
            break;

        }
    }
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

/*A main utiliza o sistema de menus que passara interios referente a região e a cidade,
esses inteiros são tratados dentro desse método para gerar a posição de um vetor  que está
presente na classe "gerenciador de passagens", desta forma, a agência consegue utilizar o
decodificador, para gerar o inteiro de destino passando para os construtores da classe seguinte,
evitando a criação de objetos na agência e na main*/

int AgenciaDeViagens::DecodificadorDeDestino(int Regiao, int Cidade){

    int CentroOeste[4] = {4, 5, 6, 10};
    int Nordeste[9] = {0, 9, 11, 13, 15, 19, 22, 23, 25};
    int Norte[7] = {1, 3, 12, 14, 16, 18, 20};
    int Sudeste[4] = {2, 21, 24, 26};
    int Sul[3] = {7, 8, 17};

	switch(Regiao){
		case 0:{
            return CentroOeste[Cidade];
		}
		break;
		case 1:{
            return Nordeste[Cidade];
        }
		break;
		case 2:{
			return Norte[Cidade];
		}
		break;
		case 3:{
            return Sudeste[Cidade];
		}
		break;
		case 4:{
			return Sul[Cidade];
		}
		break;
    }
}

void AgenciaDeViagens::ProcurarPassagemParaCancelamento(){

    string Tag;
    cout<<"Por favor insira a Tag da passagem\n->";
    cin>>Tag;

    ger.CancelarPassagem(Tag);

}

void AgenciaDeViagens::VenderPassagem(int x){


    switch(x){
        case 0:{
            ger.VenderPassagemAviao();
        }
        break;

        case 1:{
            ger.VenderPassagemOnibus();
        }
        break;

        case 2:{
            ger.VenderPassagemCruzeiro();
        }
        break;
    }
}

void AgenciaDeViagens::ImprimirPassagensPendentes(int x, string tag){

    switch(x){
        case 0:{
            ger.ImprimirPassagensPendentesAviao(tag);
        }
        break;

        case 1:{
            ger.ImprimirPassagensPendentesOnbius(tag);
        }
        break;

        case 2:{
            ger.ImprimirPassagensPendentesCruzeiro(tag);
        }
        break;
    }


}

void AgenciaDeViagens::ImprimirPassagensVendidas(int x, string tag){

    switch(x){
        case 0:{
            ger.ImprimirPassagensVendidasAviao(tag);
        }
        break;

        case 1:{
            ger.ImprimirPassagensVendidasOnibus(tag);
        }
        break;

        case 2:{
            ger.ImprimirPassagensVendidasCruzeiro(tag);
        }
        break;
    }
}

void AgenciaDeViagens::ImprimaPassagemPendente(){
    int tipo;
    string tag;

    system("cls");
    cout<<" Digite 0 Para Exibir as Passagens de Avião"
        <<"\n Digite 1 Para Exibir as Passagens de Onibus"
        <<"\n Digite 2 Para Exibir as Passagens de Cruzeiro\n->";
    cin>>tipo;

    cout<<"\nDigite a Tag da passagem/n->";
    cin>>tag;

    ImprimirPassagensPendentes(tipo, tag);


}

void AgenciaDeViagens::ImprimaPassagemVendida(){
    int tipo;
    string tag;

    system("cls");
    cout<<" Digite 0 Para Exibir as Passagens de Avião"
        <<"\n Digite 1 Para Exibir as Passagens de Onibus"
        <<"\n Digite 2 Para Exibir as Passagens de Cruzeiro\n\n->";
    cin>>tipo;

    cout<<"\nDigite a Tag da passagem/n->";
    cin>>tag;

    ImprimirPassagensVendidas(tipo, tag);

}

void AgenciaDeViagens::CancelarPassagens(){
    string Tag;

    system("cls");
    cout<<"Digite a Tag da passagem/n->";
    cin>>Tag;

    ger.CancelarPassagem(Tag);

}

bool AgenciaDeViagens::verifica_data_ida(int dia, int mes, int ano, int hora) const{

    time_t tempo_final, t;

    time(&t);

    tm* tempo_final_info=localtime(&tempo_final);

    tempo_final_info->tm_year=ano-1900;
    tempo_final_info->tm_mon=mes-1;
    tempo_final_info->tm_mday=dia;
    tempo_final_info->tm_hour=hora;

    tempo_final=mktime(tempo_final_info);

    float dif=difftime(tempo_final, t)/3600;

    if(dif<48){
        return false;
    }
    else{
        return true;
    }
}

bool const AgenciaDeViagens::VerificadorDeDataPossivel(int Dia, int Mes, int Ano){
    switch(Mes){
        case 1:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;
        }
        break;
        case 2:{
            if(Ano%4==0){
                if((Dia > 29)||(Dia < 0))
                    return false;
                else
                    return true;
            }
            else{
                if((Dia > 28)||(Dia < 0))
                    return false;
                else
                    return true;
            }
        }
        break;
        case 3:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;
        }
        break;
        case 4:{
            if((Dia > 30)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 5:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 6:{
            if((Dia > 30)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 7:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 8:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 9:{
            if((Dia > 30)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 10:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 11:{
            if((Dia > 30)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
        case 12:{
            if((Dia > 31)||(Dia < 0))
                return false;
            else
                return true;

        }
        break;
    }
}
AgenciaDeViagens::AgenciaDeViagens(){

    string Email, Senha, Nome, Data, Endereco, Telefone, TelefoneF, Documento;
    int Salario, Trava;
    string nada;

    /*Bloco para recuperar os funcionários gravados*/
    fstream ArquivoFuncionarios;
    ArquivoFuncionarios.open("ArquivoFuncionarios.txt", ios::in);

    if(ArquivoFuncionarios){
        ArquivoFuncionarios >> Trava;
        for(int i=0;i<Trava;i++){
            ArquivoFuncionarios>>Email;
            ArquivoFuncionarios>>Senha;
            ArquivoFuncionarios>>nada;
            getline(ArquivoFuncionarios,Nome);
            ArquivoFuncionarios>>Data;
            ArquivoFuncionarios>>nada;
            getline(ArquivoFuncionarios,Endereco);
            ArquivoFuncionarios>>Telefone;
            ArquivoFuncionarios>>TelefoneF;
            ArquivoFuncionarios>>Documento;
            ArquivoFuncionarios>>Salario;

            /*Para recuperar os funcionários*/
            Usuario Recuperador(Email, Senha, Nome, Data, Endereco, Telefone, TelefoneF, Documento,
            Salario);

            Funcionario.push_back(Recuperador);
        }
    }

    ArquivoFuncionarios.close();

    /*Bloco para recuperar os funcionários gravados*/
    fstream ArquivoCliente;
    ArquivoCliente.open("ArquivoCliente.txt", ios::in);

    if(ArquivoCliente){
        ArquivoCliente >> Trava;
        for(int i=0;i<Trava;i++){
            ArquivoCliente>>Email;
            ArquivoCliente>>Senha;
            ArquivoCliente>>nada;
            getline(ArquivoCliente,Nome);
            ArquivoCliente>>Data;
            ArquivoCliente>>nada;
            getline(ArquivoCliente,Endereco);
            ArquivoCliente>>Telefone;
            ArquivoCliente>>TelefoneF;
            ArquivoCliente>>Documento;

            /*Para recuperar os funcionários*/
            Usuario Recuperador(Email, Senha, Nome, Data, Endereco, Telefone, TelefoneF, Documento,
            0);

            Cliente.push_back(Recuperador);
        }
    }

    ger.RecuperadorDePassagens();

}
AgenciaDeViagens::~AgenciaDeViagens(){

    /*Bloco para gravar funcionarios cadastrados*/
    fstream ArquivoFuncionarios;
    ArquivoFuncionarios.open("ArquivoFuncionarios.txt", ios::out);

    if(ArquivoFuncionarios){
        ArquivoFuncionarios<<Funcionario.size()<<endl;
        for(int i=0;i<Funcionario.size();i++){
            ArquivoFuncionarios<<Funcionario[i].get_email()<<endl;
            ArquivoFuncionarios<<Funcionario[i].get_senha()<<endl;
            ArquivoFuncionarios<<endl;
            ArquivoFuncionarios<<"A ";
            ArquivoFuncionarios<<Funcionario[i].get_nome_completo()<<endl;
            ArquivoFuncionarios<<Funcionario[i].get_data_nascimento()<<endl;
            ArquivoFuncionarios<<endl;
            ArquivoFuncionarios<<"A ";
            ArquivoFuncionarios<<Funcionario[i].get_endereco()<<endl;
            ArquivoFuncionarios<<Funcionario[i].get_telefone()<<endl;
            ArquivoFuncionarios<<Funcionario[i].get_telefone_familiar()<<endl;
            ArquivoFuncionarios<<Funcionario[i].get_documento()<<endl;
            ArquivoFuncionarios<<Funcionario[i].get_salario()<<endl;
        }
    }

    ArquivoFuncionarios.close();

    /*Bloco para gravar clientes cadastrados*/
    fstream ArquivoCliente;
    ArquivoCliente.open("ArquivoCliente.txt", ios::out);

    if(ArquivoCliente){
        ArquivoCliente<<Cliente.size()<<endl;
        for(int i=0;i<Cliente.size();i++){
            ArquivoCliente<<Cliente[i].get_email()<<endl;
            ArquivoCliente<<Cliente[i].get_senha()<<endl;
            ArquivoCliente<<endl;
            ArquivoCliente<<"A ";
            ArquivoCliente<<Cliente[i].get_nome_completo()<<endl;
            ArquivoCliente<<Cliente[i].get_data_nascimento()<<endl;
            ArquivoCliente<<endl;
            ArquivoCliente<<"A ";
            ArquivoCliente<<Cliente[i].get_endereco()<<endl;
            ArquivoCliente<<Cliente[i].get_telefone()<<endl;
            ArquivoCliente<<Cliente[i].get_telefone_familiar()<<endl;
            ArquivoCliente<<Cliente[i].get_documento()<<endl;
        }
    }

    ArquivoFuncionarios.close();

    ger.GravadorDePassagens();

    ger.Desalocando();

    for(int i = 0; i<Cliente.size(); i++){
        Cliente.erase(Cliente.begin());
    }
    for(int i = 0; i<Passagens.size(); i++){
        Passagens.erase(Passagens.begin());
    }
    for(int i = 0; i<Funcionario.size(); i++){
        Funcionario.erase(Funcionario.begin());
    }


}

