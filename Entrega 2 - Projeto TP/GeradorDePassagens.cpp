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
}

void GeradorDePassagens::CancelarPassagem(string tag){

    string confirme;
    int controle;

    if(tag[0]=='A'){
        for(unsigned i(0); i<PassagensVendidasAviao.size(); i++){
            if(tag == PassagensVendidasAviao[i].Retorna_TagPassagem()){
                controle++;
                PassagensVendidasAviao[i].ImprimePassagemAviao();
                cout<<"\nConfirma o cancelamento da passagem?[s/n]\n->";
                cin>>confirme;
                if(confirme=="s"||confirme=="S"||confirme=="n"||confirme=="N"){
                    PassagensVendidasAviao.erase(PassagensVendidasAviao.begin()+i);
                    system("cls");
                    cout<<"\nPassagem Cancelada!\n"<<endl;
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

void GeradorDePassagens::Retornar_passagens(){

    fstream Dadospassagens;
    Dadospassagens.open("DadosPassagens.txt", ios::out);

    if(Dadospassagens){
        Dadospassagens<<PassagensAviao.size();
        for(int i=0;i<PassagensAviao.size();i++){
            Dadospassagens<<PassagensAviao[i].Retorna_Tipo_de_viagem();
            //Dadospassagens<<PassagensAviao[i].get_Data_de_ida();
            //Dadospassagens<<PassagensAviao[i].get_Data_de_volta();
            Dadospassagens<<PassagensAviao[i].Retorna_Origem();
            Dadospassagens<<PassagensAviao[i].Retorna_Destino();
            Dadospassagens<<PassagensAviao[i].Retorna_Distancia_Aviao();
            Dadospassagens<<PassagensAviao[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensAviao[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensAviao[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensOnibus.size();
        for(int i=0;i<PassagensOnibus.size();i++){
            Dadospassagens<<PassagensOnibus[i].Retorna_Tipo_de_viagem();
            //Dadospassagens<<PassagensOnibus[i].get_Data_de_ida();
            //Dadospassagens<<PassagensOnibus[i].get_Data_de_volta();
            Dadospassagens<<PassagensOnibus[i].Retorna_Origem();
            Dadospassagens<<PassagensOnibus[i].Retorna_Destino();
            Dadospassagens<<PassagensOnibus[i].Retorna_Distancia_Onibus();
            Dadospassagens<<PassagensOnibus[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensOnibus[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensOnibus[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensCruzeiro.size();
        for(int i=0;i<PassagensCruzeiro.size();i++){
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Tipo_de_viagem();
            //Dadospassagens<<PassagensCruzeiro[i].get_Data_de_ida();
            //Dadospassagens<<PassagensCruzeiro[i].get_Data_de_volta();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Origem();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Destino();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_Distancia_Cruzeiro();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensCruzeiro[i].Retorna_TagPassagem();
        }
    }

    if(Dadospassagens){
        Dadospassagens<<PassagensVendidasAviao.size();
        for(int i=0;i<PassagensVendidasAviao.size();i++){
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Tipo_de_viagem();
            //Dadospassagens<<PassagensVendidasAviao[i].get_Data_de_ida();
            //Dadospassagens<<PassagensVendidasAviao[i].get_Data_de_volta();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Origem();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Destino();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_Distancia_Aviao();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensVendidasAviao[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensVendidasOnibus.size();
        for(int i=0;i<PassagensVendidasOnibus.size();i++){
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Tipo_de_viagem();
            //Dadospassagens<<PassagensVendidasOnibus[i].get_Data_de_ida();
            //Dadospassagens<<PassagensVendidasOnibus[i].get_Data_de_volta();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Origem();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Destino();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_Distancia_Onibus();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensVendidasOnibus[i].Retorna_TagPassagem();
        }

        Dadospassagens<<PassagensVendidasCruzeiro.size();
        for(int i=0;i<PassagensVendidasCruzeiro.size();i++){
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Tipo_de_viagem();
            //Dadospassagens<<PassagensVendidasCruzeiro[i].get_Data_de_ida();
            //Dadospassagens<<PassagensVendidasCruzeiro[i].get_Data_de_volta();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Origem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Destino();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_Distancia_Cruzeiro();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_TempoDeViagem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_PrecoDaPassagem();
            Dadospassagens<<PassagensVendidasCruzeiro[i].Retorna_TagPassagem();
        }
    }
    Dadospassagens.close();
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
    else{
        cout<<"\nNenhuma Passagem Agendada!\n";
    }
}

void GeradorDePassagens::VenderPassagemOnibus(){
    if(PassagensOnibus.size()>0){
        PassagensVendidasOnibus.push_back(PassagensOnibus[0]);
        PassagensOnibus.pop_back();
        cout<<"\nVenda confirmada!\n";
    }
    else{
        cout<<"\nNenhuma Passagem Agendada!\n";
    }
}

void GeradorDePassagens::VenderPassagemCruzeiro(){
    if(PassagensCruzeiro.size()>0){
        PassagensVendidasCruzeiro.push_back(PassagensCruzeiro[0]);
        PassagensCruzeiro.pop_back();
        cout<<"\nVenda confirmada!\n";
    }
    else{
        cout<<"\nNenhuma Passagem Agendada!\n";
    }
}

void GeradorDePassagens::ImprimirPassagensPendentesAviao(string tag){

    cout<<"entrou: ";
    cout<<PassagensAviao.size()<<endl;

    for(int i=0; i<PassagensAviao.size(); i++){

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

