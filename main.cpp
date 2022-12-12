#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "ConfigEntrada.hpp"
#include "ConfigSaida.hpp"
#include "Word.hpp"
#include "AVLNode.hpp"
#include "AVLTree.hpp"

using namespace std;

Word* InputSplit(string input);
void preOrder(AVLNode *root)
{ 
  if(root ==NULL){
  }
  if(root != NULL)
  {
    cout << root->key << " "; 
    preOrder(root->leftChild); 
    preOrder(root->rightChild);  
    }
}
int main(int argv,char* argc[]) {
  string str;
  int i =1;
  while(i<argv){
    str.append(argc[i]);
    str.append(" ");
    i++;
  }
  ConfigEntrada* entrada = ConfigEntrada::getInstancia(str);
  ConfigSaida* output = ConfigSaida::getInstancia("output.txt");
  std::ifstream myfile (entrada->i,std::fstream::in);
  string line;
  Word* word = nullptr;
  AVLTree* tree = new AVLTree();
  while(getline(myfile,line)){

    word = InputSplit(line);
    tree->append(tree->root,word);
  }
  preOrder(tree->root);
  //cout<<endl;
  //char c;
  //cin>>c;
  //int a = c -96;
  //cout<<a<<endl;
  //AVLNode* finded = tree->find(a);
  //if(finded == NULL){
  //  cout<<"Não encontrado"<<endl;
  //}
  //else{
   // finded->content->print();
  //}
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