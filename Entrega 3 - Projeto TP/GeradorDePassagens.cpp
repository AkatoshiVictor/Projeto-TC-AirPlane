#include "GeradorDePassagens.h"

void GeradorDePassagens::Define_Regiao(int Regiao){
    this->Regiao=Regiao;
}

void GeradorDePassagens::Define_Cidade(int Cidade){
    this->Cidade=Cidade;
}

int GeradorDePassagens::Retorna_Regiao(){
    return Regiao;
}

int GeradorDePassagens::Retorna_Cidade(){
    return Cidade;
}

void GeradorDePassagens::AgendandoPassagemOnibus(Onibus x){
    PassagensOnibus.push_back(x);
}

void GeradorDePassagens::AgendandoPassagemAviao(Aviao x){
    PassagensAviao.push_back(x);
    cout<<"tamanho: "<<PassagensAviao.size();
}

void GeradorDePassagens::AgendandoPassagemCruzeiro(Cruzeiro x){
    PassagensCruzeiro.push_back(x);
    cout<<"tamanho: "<<PassagensCruzeiro.size();
}

void GeradorDePassagens::CancelarPassagem(string tag){

    string confirme;
    int controle;

    if(tag[0]=='A'){
        for(unsigned i(0); i<PassagensVendidasAviao.size(); i++){
            if(tag == PassagensVendidasAviao[i].Retorna_TagPassagem()){

                controle++;

                time_t tempo_final, t;

                time(&t);//HORARIO DO PC

                tm* tempo_final_info=localtime(&tempo_final);

                tempo_final_info->tm_year=PassagensVendidasAviao[i].get_ano_de_ida()-1900; //ANO 2021
                tempo_final_info->tm_mon=PassagensVendidasAviao[i].get_mes_de_ida()-1; //MêS 09
                tempo_final_info->tm_mday=PassagensVendidasAviao[i].get_dia_de_ida(); //DIA 26
                tempo_final_info->tm_hour=PassagensVendidasAviao[i].get_Horario(); //12 HRS

                tempo_final=mktime(tempo_final_info);

                float dif=difftime(tempo_final, t)/3600;

                if(dif>=48){
                    PassagensVendidasAviao[i].ImprimePassagemAviao();
                    cout<<"\nConfirma o cancelamento da passagem?[s/n]\n->";
                    cin>>confirme;
                    if(confirme=="s"||confirme=="S"||confirme=="n"||confirme=="N"){
                        PassagensVendidasAviao.erase(PassagensVendidasAviao.begin()+i);
                        system("cls");
                        cout<<"\nPassagem Cancelada!\n"<<endl;
                    }
                }
                else if(dif<48){
                    cout<<"\nEssa passagem não pode ser cancelada!"<<endl;
                }
            }
        }
        if(controle==0){
            cout<<"\nPassagem não encontrada!\n";
        }
    }
    else if(tag[0]=='O'){
        for(unsigned i(0); i<PassagensVendidasOnibus.size(); i++){
            if(tag == PassagensVendidasOnibus[i].Retorna_TagPassagem()){
                controle++;
                PassagensVendidasOnibus[i].ImprimePassagemOnibus();
                cout<<"\nConfirma o cancelamento da passagem?[s/n]\n->";
                cin>>confirme;
                if(confirme=="s"||confirme=="S"||confirme=="n"||confirme=="N"){
                    PassagensVendidasOnibus.erase(PassagensVendidasOnibus.begin()+i);
                    system("cls");
                    cout<<"\nPassagem Cancelada!\n"<<endl;
                }
            }
        }
        if(controle==0){
            cout<<"\nPassagem não encontrada!\n";
        }
    }
    else if(tag[0]=='C'){
        for(unsigned i(0); i<PassagensVendidasCruzeiro.size(); i++){
            if(tag == PassagensVendidasCruzeiro[i].Retorna_TagPassagem()){
                controle++;
                PassagensVendidasCruzeiro[i].ImprimePassagemCruzeiro();
                cout<<"\nConfirma o cancelamento da passagem?[s/n]\n->";
                cin>>confirme;
                if(confirme=="s"||confirme=="S"||confirme=="n"||confirme=="N"){
                    PassagensVendidasCruzeiro.erase(PassagensVendidasCruzeiro.begin()+i);
                    system("cls");
                    cout<<"\nPassagem Cancelada!\n"<<endl;
                }
            }
        }
        if(controle==0){
            cout<<"\nPassagem não encontrada!\n";
        }
    }
    else{
        cout<<"\nTag incompativel!\n";
    }

}

int GeradorDePassagens::Retorna_distancia(string tipo, int x){
    if(tipo=="Avião"){
        PassagensAviao[x].Retorna_Distancia_Aviao();
    }else if(tipo=="Ônibus"){

    }
}

void GeradorDePassagens::VenderPassagemAviao(){
    if(PassagensAviao.size()>0){
        PassagensVendidasAviao.push_back(PassagensAviao[0]);
        PassagensAviao.pop_back();
        cout<<"\nVenda confirmada!\n";
    }
    else if(PassagensAviao.size() ==0){
        cout<<"\nNenhuma Passagem Agendada!\n";
    }
}

void GeradorDePassagens::VenderPassagemOnibus(){
    if(PassagensOnibus.size()>0){
        PassagensVendidasOnibus.push_back(PassagensOnibus[0]);
        PassagensOnibus.pop_back();
        cout<<"\nVenda confirmada!\n";
    }
    else if(PassagensOnibus.size() ==0){
        cout<<"\nNenhuma Passagem Agendada!\n";
    }
}

void GeradorDePassagens::VenderPassagemCruzeiro(){
    if(PassagensCruzeiro.size()>0){
        PassagensVendidasCruzeiro.push_back(PassagensCruzeiro[0]);
        PassagensCruzeiro.pop_back();
        cout<<"\nVenda confirmada!\n";
    }
    else if(PassagensCruzeiro.size() ==0){
        cout<<"\nNenhuma Passagem Agendada!\n";
    }
}

void GeradorDePassagens::ImprimirPassagensPendentesAviao(string tag){



    for(int i=0; i<PassagensAviao.size(); i++){
        cout<<"entrou: ";
        cout<<PassagensAviao.size()<<endl;
        cout<<"Loop: "<<i<<endl;
        cout<<"Tag: "<<PassagensAviao[i].Retorna_TagPassagem()<<endl;

        //cout<<"\n###############\nEU SOU O DOGRAS\n##############\n";
        //cout<<endl<<PassagensAviao[i].Retorna_TagPassagem()<<endl;

        if(tag == PassagensAviao[i].Retorna_TagPassagem()){
                cout<<"\n###############\nIF2\n##############\n";
            PassagensAviao[i].ImprimePassagemAviao();
            system("pause");
            break;
        }
    }


}

void GeradorDePassagens::ImprimirPassagensPendentesOnbius(string tag){

    if(PassagensOnibus.size()>=0){
        for(unsigned i(0); i<PassagensOnibus.size(); i++){
            if(tag == PassagensOnibus[i].Retorna_TagPassagem()){
                PassagensOnibus[i].ImprimePassagemOnibus();
                system("pause");
            }
        }
    }
}

void GeradorDePassagens::ImprimirPassagensPendentesCruzeiro(string tag){

    if(PassagensCruzeiro.size()>0){
        for(unsigned i(0); i<PassagensCruzeiro.size(); i++){
            if(tag == PassagensCruzeiro[i].Retorna_TagPassagem()){
                PassagensCruzeiro[i].ImprimePassagemCruzeiro();
                system("pause");
            }
        }
    }

}

void GeradorDePassagens::ImprimirPassagensVendidasAviao(string tag){

    if(PassagensVendidasAviao.size()>0){
        for(unsigned i(0); i<PassagensVendidasAviao.size(); i++){
            if(tag == PassagensVendidasAviao[i].Retorna_TagPassagem()){
                PassagensVendidasAviao[i].ImprimePassagemAviao();
                system("pause");
            }
        }
    }

}

void GeradorDePassagens::ImprimirPassagensVendidasOnibus(string tag){

    if(PassagensVendidasOnibus.size()>0){
        for(unsigned i(0); i<PassagensVendidasOnibus.size(); i++){
            if(tag == PassagensVendidasOnibus[i].Retorna_TagPassagem()){
                PassagensVendidasOnibus[i].ImprimePassagemOnibus();
                system("pause");
            }
        }
    }

}

void GeradorDePassagens::ImprimirPassagensVendidasCruzeiro(string tag){

    if(PassagensVendidasCruzeiro.size()>0){
        for(unsigned i(0); i<PassagensVendidasCruzeiro.size(); i++){
            if(tag == PassagensVendidasCruzeiro[i].Retorna_TagPassagem()){
                PassagensVendidasCruzeiro[i].ImprimePassagemCruzeiro();
                system("pause");
            }
        }
    }

}

float GeradorDePassagens::PassaOFaturamentoTotal(){
    float Faturamento = 0;

    for(int i = 0; i < PassagensVendidasAviao.size(); i++){
        Faturamento = Faturamento + PassagensAviao[i].Retorna_PrecoDaPassagem();
    }

    for(int i = 0; i < PassagensVendidasOnibus.size(); i++){
        Faturamento = Faturamento + PassagensVendidasOnibus[i].Retorna_PrecoDaPassagem();
    }

    for(int i = 0; i < PassagensVendidasCruzeiro.size(); i++){
        Faturamento = Faturamento + PassagensVendidasCruzeiro[i].Retorna_PrecoDaPassagem();
    }

    return Faturamento;
}

/*Gravação e leitrua de arquivos*/

void GeradorDePassagens::GravadorDePassagens(){

    /*Bloco para gravar passagens não vendidas*/
    fstream ArquivoPassagensAviao;
    ArquivoPassagensAviao.open("ArquivoPassagensAviao.txt", ios::out);

    if(ArquivoPassagensAviao){
        ArquivoPassagensAviao<<PassagensAviao.size()<<endl;
        for(int i=0;i<PassagensAviao.size();i++){
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_Tipo_de_viagem()<<endl;
            ArquivoPassagensAviao<<endl;
            ArquivoPassagensAviao<<"A ";
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_Origem()<<endl;
            ArquivoPassagensAviao<<endl;
            ArquivoPassagensAviao<<"A ";
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_Destino()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_Distancia_Aviao()<<endl;
            ArquivoPassagensAviao<<endl;
            ArquivoPassagensAviao<<"A ";
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_TempoDeViagem()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_PrecoDaPassagem()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].Retorna_TagPassagem()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_dia_de_ida()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_mes_de_ida()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_ano_de_ida()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_Horario()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_dia_de_volta()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_mes_de_volta()<<endl;
            ArquivoPassagensAviao<<PassagensAviao[i].get_ano_de_volta()<<endl;
        }
    }
    ArquivoPassagensAviao.close();

    /*Bloco para gravar passagens de ônibus não vendidas*/
    fstream ArquivoPassagensOnibus;
    ArquivoPassagensOnibus.open("ArquivoPassagensOnibus.txt", ios::out);
    
    if(ArquivoPassagensOnibus){
        ArquivoPassagensAviao<<PassagensOnibus.size()<<endl;
        for(int i=0;i<PassagensOnibus.size();i++){
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_Tipo_de_viagem()<<endl;
            ArquivoPassagensOnibus<<endl;
            ArquivoPassagensOnibus<<"A ";
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_Origem()<<endl;
            ArquivoPassagensOnibus<<endl;
            ArquivoPassagensOnibus<<"A ";
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_Destino()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_Distancia_Onibus()<<endl;
            ArquivoPassagensOnibus<<endl;
            ArquivoPassagensOnibus<<"A ";
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_TempoDeViagem()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_PrecoDaPassagem()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].Retorna_TagPassagem()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_dia_de_ida()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_mes_de_ida()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_ano_de_ida()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_Horario()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_dia_de_volta()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_mes_de_volta()<<endl;
            ArquivoPassagensOnibus<<PassagensOnibus[i].get_ano_de_volta()<<endl;
        }
    }
    ArquivoPassagensOnibus.close();
    
    /*Bloco para gravação de passagens de cruziro*/
    fstream AqruivoPassagensCruzeiro;
    AqruivoPassagensCruzeiro.open("AqruivoPassagensCruzeiro.txt", ios::out);

    if(AqruivoPassagensCruzeiro){
        AqruivoPassagensCruzeiro<<PassagensCruzeiro.size()<<endl;
        for(int i=0;i<PassagensCruzeiro.size();i++){
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].Retorna_TagPassagem()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_dia_de_ida()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_mes_de_ida()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_ano_de_ida()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_dia_de_volta()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_mes_de_volta()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_ano_de_volta()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].get_Horario()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].Retorna_Origem()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].Retorna_Destino()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].Retorna_Distancia_Cruzeiro()<<endl;
            AqruivoPassagensCruzeiro<<PassagensCruzeiro[i].Retorna_PrecoDaPassagem()<<endl;
        }
    }
    AqruivoPassagensCruzeiro.close();

    /*Bloco para gravação de passagens vendidas de avião*/
    fstream ArquivoPassagensVendidasAviao;
    ArquivoPassagensVendidasAviao.open("ArquivoPassagensVendidasAviao.txt", ios::out);

    if(ArquivoPassagensVendidasAviao){
        ArquivoPassagensVendidasAviao<<PassagensVendidasAviao.size()<<endl;
        for(int i=0;i<PassagensVendidasAviao.size();i++){
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_Tipo_de_viagem()<<endl;
            ArquivoPassagensVendidasAviao<<endl;
            ArquivoPassagensVendidasAviao<<"A ";
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_Origem()<<endl;
            ArquivoPassagensVendidasAviao<<endl;
            ArquivoPassagensVendidasAviao<<"A ";
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_Destino()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_Distancia_Aviao()<<endl;
            ArquivoPassagensVendidasAviao<<endl;
            ArquivoPassagensVendidasAviao<<"A ";
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_TempoDeViagem()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_PrecoDaPassagem()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].Retorna_TagPassagem()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_dia_de_ida()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_mes_de_ida()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_ano_de_ida()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_Horario()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_dia_de_volta()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_mes_de_volta()<<endl;
            ArquivoPassagensVendidasAviao<<PassagensVendidasAviao[i].get_ano_de_volta()<<endl;
        }
    }
    ArquivoPassagensVendidasAviao.close();

    /*Bloco para gravação de passagens vendidas de ônibus*/
    fstream ArquivoPassagensVendidasOnibus;
    ArquivoPassagensVendidasOnibus.open("ArquivoPassagensVendidasOnibus.txt", ios::out);

    if(ArquivoPassagensVendidasOnibus){
        ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus.size()<<endl;
        for(int i=0;i<PassagensVendidasOnibus.size();i++){
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_Tipo_de_viagem()<<endl;
            ArquivoPassagensVendidasOnibus<<endl;
            ArquivoPassagensVendidasOnibus<<"A ";
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_Origem()<<endl;
            ArquivoPassagensVendidasOnibus<<endl;
            ArquivoPassagensVendidasOnibus<<"A ";
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_Destino()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_Distancia_Onibus()<<endl;
            ArquivoPassagensVendidasOnibus<<endl;
            ArquivoPassagensVendidasOnibus<<"A ";
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_TempoDeViagem()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_PrecoDaPassagem()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].Retorna_TagPassagem()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_dia_de_ida()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_mes_de_ida()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_ano_de_ida()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_Horario()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_dia_de_volta()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_mes_de_volta()<<endl;
            ArquivoPassagensVendidasOnibus<<PassagensVendidasOnibus[i].get_ano_de_volta()<<endl;
        }
    }
    ArquivoPassagensVendidasOnibus.close();

    /*Bloco para gravação de passagens de cruzeiro vendidas*/
    fstream AqruivoPassagensVendidasCruzeiro;
    AqruivoPassagensVendidasCruzeiro.open("AqruivoPassagensVendidasCruzeiro.txt", ios::out);

    if(AqruivoPassagensVendidasCruzeiro){
        AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro.size()<<endl;
        for(int i=0;i<PassagensVendidasCruzeiro.size();i++){
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].Retorna_TagPassagem()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_dia_de_ida()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_mes_de_ida()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_ano_de_ida()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_dia_de_volta()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_mes_de_volta()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_ano_de_volta()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].get_Horario()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].Retorna_Origem()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].Retorna_Destino()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].Retorna_Distancia_Cruzeiro()<<endl;
            AqruivoPassagensVendidasCruzeiro<<PassagensVendidasCruzeiro[i].Retorna_PrecoDaPassagem()<<endl;
        }
    }
    AqruivoPassagensCruzeiro.close();
}

void GeradorDePassagens::RecuperadorDePassagens(){

    /*Definição de variáveis usadas para a recuperação das informações gravadas nos txt*/
    string TipoDeViagem, Origem, Destino, Tempo, TagPassagem;
    float Preco;
    int DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora, Trava, Distancia;
    string nada;


    /*Bloco recuperador de passagens vendidas de avião*/
    fstream ArquivoPassagensVendidasAviao;
    ArquivoPassagensVendidasAviao.open("ArquivoPassagensVendidasAviao.txt", ios::in);

    if(ArquivoPassagensVendidasAviao){
        ArquivoPassagensVendidasAviao >> Trava;
        for(int i=0;i<Trava;i++){
            ArquivoPassagensVendidasAviao >> TipoDeViagem;
            ArquivoPassagensVendidasAviao >> nada;
            cin.ignore();
            getline(ArquivoPassagensVendidasAviao, Origem);
            ArquivoPassagensVendidasAviao >> nada;
            cin.ignore();
            getline(ArquivoPassagensVendidasAviao, Destino);
            ArquivoPassagensVendidasAviao >> Distancia;
            ArquivoPassagensVendidasAviao >> nada;
            cin.ignore();
            getline(ArquivoPassagensVendidasAviao, Tempo);
            ArquivoPassagensVendidasAviao >> Preco;
            ArquivoPassagensVendidasAviao >> TagPassagem;
            ArquivoPassagensVendidasAviao >> DiaI;
            ArquivoPassagensVendidasAviao >> MesI;
            ArquivoPassagensVendidasAviao >> AnoI;
            ArquivoPassagensVendidasAviao >> Hora;
            ArquivoPassagensVendidasAviao >> DiaV;
            ArquivoPassagensVendidasAviao >> MesV;
            ArquivoPassagensVendidasAviao >> AnoV;

            Aviao ObjAviaoRecuperador(TipoDeViagem, Origem, Destino, Tempo, TagPassagem, 
            Preco, Distancia, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora);

            PassagensVendidasAviao.push_back(ObjAviaoRecuperador);

        }
    }
    ArquivoPassagensVendidasAviao.close();

    /*Bloco para passagens de avião que não foram vendidas*/
    fstream ArquivoPassagensAviao;
    ArquivoPassagensAviao.open("ArquivoPassagensAviao.txt", ios::in);

    if(ArquivoPassagensAviao){
        ArquivoPassagensAviao >> Trava;
        for(int i=0;i<Trava;i++){
            ArquivoPassagensAviao >> TipoDeViagem;
            ArquivoPassagensAviao >> nada;
            cin.ignore();
            getline(ArquivoPassagensAviao, Origem);
            ArquivoPassagensAviao >> nada;
            cin.ignore();
            getline(ArquivoPassagensAviao, Destino);
            ArquivoPassagensAviao >> Distancia;
            ArquivoPassagensAviao >> nada;
            cin.ignore();
            getline(ArquivoPassagensAviao, Tempo);
            ArquivoPassagensAviao >> Preco;
            ArquivoPassagensAviao >> TagPassagem;
            ArquivoPassagensAviao >> DiaI;
            ArquivoPassagensAviao >> MesI;
            ArquivoPassagensAviao >> AnoI;
            ArquivoPassagensAviao >> Hora;
            ArquivoPassagensAviao >> DiaV;
            ArquivoPassagensAviao >> MesV;
            ArquivoPassagensAviao >> AnoV;

            Aviao ObjAviaoRecuperador(TipoDeViagem, Origem, Destino, Tempo, TagPassagem, 
            Preco, Distancia, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora);

            PassagensAviao.push_back(ObjAviaoRecuperador);

        }
    }
    ArquivoPassagensAviao.close();

    /*Bloco para passagens de onibus que não foram vendidas*/
    fstream ArquivoPassagensVendidasOnibus;
    ArquivoPassagensVendidasOnibus.open("ArquivoPassagensVendidasOnibus.txt", ios::in);

    if(ArquivoPassagensVendidasOnibus){
        ArquivoPassagensVendidasOnibus >> Trava;
        for(int i=0;i<Trava;i++){
            ArquivoPassagensVendidasOnibus >> TipoDeViagem;
            ArquivoPassagensVendidasOnibus >> nada;
            cin.ignore();
            getline(ArquivoPassagensVendidasOnibus, Origem);
            ArquivoPassagensVendidasOnibus >> nada;
            cin.ignore();
            getline(ArquivoPassagensVendidasOnibus, Destino);
            ArquivoPassagensVendidasOnibus >> Distancia;
            ArquivoPassagensVendidasOnibus >> nada;
            cin.ignore();
            getline(ArquivoPassagensVendidasOnibus, Tempo);
            ArquivoPassagensVendidasOnibus >> Preco;
            ArquivoPassagensVendidasOnibus >> TagPassagem;
            ArquivoPassagensVendidasOnibus >> DiaI;
            ArquivoPassagensVendidasOnibus >> MesI;
            ArquivoPassagensVendidasOnibus >> AnoI;
            ArquivoPassagensVendidasOnibus >> Hora;
            ArquivoPassagensVendidasOnibus >> DiaV;
            ArquivoPassagensVendidasOnibus >> MesV;
            ArquivoPassagensVendidasOnibus >> AnoV;

            Onibus ObjOnibusRecuperador(TipoDeViagem, Origem, Destino, Tempo, TagPassagem, 
            Preco, Distancia, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora);

            PassagensOnibus.push_back(ObjOnibusRecuperador);

        }
    }
    ArquivoPassagensVendidasOnibus.close();

    /*Bloco para passagens de onibus que não foram vendidas*/
    fstream ArquivoPassagensOnibus;
    ArquivoPassagensOnibus.open("ArquivoPassagensOnibus.txt", ios::in);

    if(ArquivoPassagensOnibus){
        ArquivoPassagensOnibus >> Trava;
        for(int i=0;i<Trava;i++){
            ArquivoPassagensOnibus >> TipoDeViagem;
            ArquivoPassagensOnibus >> nada;
            cin.ignore();
            getline(ArquivoPassagensOnibus, Origem);
            ArquivoPassagensOnibus >> nada;
            cin.ignore();
            getline(ArquivoPassagensOnibus, Destino);
            ArquivoPassagensOnibus >> Distancia;
            ArquivoPassagensOnibus >> nada;
            cin.ignore();
            getline(ArquivoPassagensOnibus, Tempo);
            ArquivoPassagensOnibus >> Preco;
            ArquivoPassagensOnibus >> TagPassagem;
            ArquivoPassagensOnibus >> DiaI;
            ArquivoPassagensOnibus >> MesI;
            ArquivoPassagensOnibus >> AnoI;
            ArquivoPassagensOnibus >> Hora;
            ArquivoPassagensOnibus >> DiaV;
            ArquivoPassagensOnibus >> MesV;
            ArquivoPassagensOnibus >> AnoV;

            Onibus ObjOnibusRecuperador(TipoDeViagem, Origem, Destino, Tempo, TagPassagem, 
            Preco, Distancia, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora);

            PassagensOnibus.push_back(ObjOnibusRecuperador);

        }
    }
    ArquivoPassagensOnibus.close();


    /*Bloco recuperador de passagens de cruzeiro não vendidaas*/
    fstream AqruivoPassagensCruzeiro;
    AqruivoPassagensCruzeiro.open("AqruivoPassagensCruzeiro.txt", ios::in);

    if(AqruivoPassagensCruzeiro){
        AqruivoPassagensCruzeiro >> Trava;
        for(int i=0;i<Trava;i++){
            AqruivoPassagensCruzeiro >> TagPassagem;
            AqruivoPassagensCruzeiro >> DiaI;
            AqruivoPassagensCruzeiro >> MesI;
            AqruivoPassagensCruzeiro >> AnoI;
            AqruivoPassagensCruzeiro >> DiaV;
            AqruivoPassagensCruzeiro >> MesV;
            AqruivoPassagensCruzeiro >> AnoV;
            AqruivoPassagensCruzeiro >> Hora;
            AqruivoPassagensCruzeiro >> Origem;
            AqruivoPassagensCruzeiro >> Destino;
            AqruivoPassagensCruzeiro >> Preco;
            AqruivoPassagensCruzeiro >> Distancia;

            Cruzeiro Recuperador(TagPassagem, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora, Origem, Destino, Preco, Distancia);

            PassagensCruzeiro.push_back(Recuperador);

        }
    }
    ArquivoPassagensOnibus.close();

    /*Bloco recuperador de passagens de cruzeiro não vendidaas*/
    fstream AqruivoPassagensVendidasCruzeiro;
    AqruivoPassagensVendidasCruzeiro.open("AqruivoPassagensVendidasCruzeiro.txt", ios::in);

    if(AqruivoPassagensVendidasCruzeiro){
        AqruivoPassagensVendidasCruzeiro >> Trava;
        for(int i=0;i<Trava;i++){
            AqruivoPassagensVendidasCruzeiro >> TagPassagem;
            AqruivoPassagensVendidasCruzeiro >> DiaI;
            AqruivoPassagensVendidasCruzeiro >> MesI;
            AqruivoPassagensVendidasCruzeiro >> AnoI;
            AqruivoPassagensVendidasCruzeiro >> DiaV;
            AqruivoPassagensVendidasCruzeiro >> MesV;
            AqruivoPassagensVendidasCruzeiro >> AnoV;
            AqruivoPassagensVendidasCruzeiro >> Hora;
            AqruivoPassagensVendidasCruzeiro >> Origem;
            AqruivoPassagensVendidasCruzeiro >> Destino;
            AqruivoPassagensVendidasCruzeiro >> Preco;
            AqruivoPassagensVendidasCruzeiro >> Distancia;

            Cruzeiro Recuperador(TagPassagem, DiaI, MesI, AnoI, DiaV, MesV, AnoV, Hora, Origem, Destino, Preco, Distancia);

            PassagensVendidasCruzeiro.push_back(Recuperador);

        }
    }
    ArquivoPassagensOnibus.close();

}

