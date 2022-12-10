#include "ConfigEntrada.hpp"
ConfigEntrada* ConfigEntrada::instancia = nullptr;

ConfigEntrada* ConfigEntrada::getInstancia(){
    return instancia;
}

ConfigEntrada* ConfigEntrada::getInstancia(string entrada){
    if(instancia==nullptr){
        instancia = new ConfigEntrada(entrada);
    }
    return getInstancia();
}

ConfigEntrada::ConfigEntrada(string entrada)
{
    this->i = identificaFlag(entrada,"-i ");
    this->o = identificaFlag(entrada,"-o ");
    this->instancia = this;
}
string ConfigEntrada::identificaFlag(string str,string flag){
     size_t pos = str.find(flag);
     size_t aux ;
    if(pos != string::npos){
        pos+=flag.size();
        aux = str.find(" ",pos);
        return str.substr(pos,aux-pos);
    }
    else{
        return "0";
    }
}

