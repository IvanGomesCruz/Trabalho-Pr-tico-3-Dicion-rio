#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "ConfigEntrada.hpp"
#include "ConfigSaida.hpp"
#include "Word.hpp"
#include "AVLNode.hpp"
#include "AVLTree.hpp"
#include "HashTable.hpp"
#include "ElementList.hpp"

using namespace std;

void Avl();
void Hash();
Word* InputSplit(string input);
void preOrder(AVLNode *root)
{ 
  if(root ==NULL){
  }
  if(root != NULL)
  {
    preOrder(root->leftChild); 
    cout << root->key << " "; 
    preOrder(root->rightChild);  
    }
}
int main(int argv,char* argc[]) {
  //string str;
  //int i =1;
  //while(i<argv){
    //str.append(argc[i]);
    //str.append(" ");
   // i++;
  //}
  //ConfigEntrada* entrada = ConfigEntrada::getInstancia(str);
  
  //delete(entrada);
   ConfigSaida* output = ConfigSaida::getInstancia("output.txt");
   //Avl();
   Hash();
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
void Hash(){
  ConfigSaida* output = ConfigSaida::getInstancia();
  std::ifstream myfile ("input.txt",std::fstream::in);
  string line;
  Word* word = nullptr;
  HashTable* hash = new HashTable();
  while(getline(myfile,line)){
    word = InputSplit(line);
    hash->Insere(word);
  }
  //hash->ListChave.print();
  hash->PrintOrdenado();
  hash->RemoveWithMeaning();
  hash->PrintOrdenado();
  //hash->Tabela[1]._frist->getObject()->print();
  //word = InputSplit("a [abstract]");
  //ElementList* finded = hash->Pesquisa(word->getKeyT());
  //if(finded==NULL){
   // return;
 // }
  
  //finded->getObject()->print();
  //tree->preOrder(tree->root);
  //tree->removeWitchMeaning(tree->root);
  //tree->preOrder(tree->root);
}
void Avl(){
  ConfigSaida* output = ConfigSaida::getInstancia();
  std::ifstream myfile ("input.txt",std::fstream::in);
  string line;
  Word* word = nullptr;
  AVLTree* tree = new AVLTree();
  while(getline(myfile,line)){

    word = InputSplit(line);
    AVLNode* node = tree->find(word->getKeyT());
    if(node!=NULL){
      if(!word->meanings.isEmpty()){
        node->content->appendMeaning(word->getMeaning());
      }
    }
    else{
      tree->append(tree->root,word);
    }
  }
  tree->preOrder(tree->root);
  tree->removeWitchMeaning(tree->root);
  tree->preOrder(tree->root);
}