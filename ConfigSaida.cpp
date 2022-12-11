#include "ConfigSaida.hpp"
ConfigSaida *ConfigSaida::instancia = nullptr;

ConfigSaida::~ConfigSaida() { 
  f_out.close(); 
  
}
ConfigSaida *ConfigSaida::getInstancia() { 
  return instancia; 
  }
ConfigSaida *ConfigSaida::getInstancia(string arquivo) {
  if (instancia == nullptr) {
    instancia = new ConfigSaida(arquivo);
  }
  return getInstancia();
}
ConfigSaida::ConfigSaida(string arquivo) {
  this->_arquivo = arquivo;
  f_out.open(_arquivo);
}
void ConfigSaida::print(string str){
  if(str == "\n"){
    f_out<<endl;
    return;
  }
  f_out<<str;
}