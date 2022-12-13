#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "ConfigEntrada.hpp"
#include "ConfigSaida.hpp"
#include "Word.hpp"
#include "Dicionario.hpp"
using namespace std;

void PreencheDic();
int numLines();

Word* InputSplit(string input);
int main(int argv,char* argc[]) {
  string str;
  int i =1;
  while(i<argv){
    str.append(argc[i]);
    str.append(" ");
    i++;
  }
  ConfigEntrada* entrada = ConfigEntrada::getInstancia(str);
  ConfigSaida* output = ConfigSaida::getInstancia(entrada->o);
  Dicionario* dic = Dicionario::criaDic(numLines());
  PreencheDic();
  dic->imprimeDic();
  dic->atualizaDic();
  dic->imprimeDic();

  delete(entrada);
  return 0;
}

Word* InputSplit(string input){
  string type, applied;
  size_t pos = input.find(" ");
  size_t pos2;
  type = input.substr(0,pos);
  input.erase(0,pos+1);
  pos = input.find("[")+1;
  pos2 = input.find("]");
  applied = input.substr(pos,pos2-1);
  input.erase(0,pos2+2);
  Word* word = new Word(type,applied);
  if(!input.empty()){
    word->appendMeaning(input);
  }
  return word;
}

void PreencheDic(){
  ConfigEntrada* input = ConfigEntrada::getInstancia();
  std::ifstream myfile (input->i,std::fstream::in);
  string line;
  Word* word = nullptr;
  Dicionario* dic = Dicionario::criaDic();
  
  while(getline(myfile,line)){
    word = InputSplit(line);
    dic->insereDic(word);
  }

}

int numLines(){
  ConfigEntrada* input = ConfigEntrada::getInstancia();
  std::ifstream myfile (input->i,std::fstream::in);
  int numline=0;
  string line;
  while(getline(myfile,line)){
    numline++;
  }
  return numline;
}