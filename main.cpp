#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "ConfigEntrada.hpp"
#include "Word.hpp"

using namespace std;

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
  std::ifstream myfile (entrada->i,std::fstream::in);
  string line;
  Word* word = nullptr;
  while(getline(myfile,line)){
    word = InputSplit(line);
    word->print();
    delete(word);
  }

  //Word word("name","Brasil");
 // word.print();
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