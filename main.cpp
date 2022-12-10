#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "ConfigEntrada.hpp"

using namespace std;


int main(int argv,char* argc[]) {
    string str;
    int i =1;
  while(i<argv){
    str.append(argc[i]);
    str.append(" ");
    i++;
  }
  //ConfigEntrada* entrada = ConfigEntrada::getInstancia(str);
  //std::ifstream myfile (entrada->i,std::fstream::in);

  
  //delete(entrada);
  return 0;
}