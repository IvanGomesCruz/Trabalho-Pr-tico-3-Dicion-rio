
#include "Dicionario.hpp"

Dicionario* Dicionario::instancia = nullptr;

Dicionario::Dicionario(){
    ConfigEntrada* entrada = ConfigEntrada::getInstancia();
    if(entrada->t == "arv"){
        this->dicionario = new AVLTree();
    }
    else{
        this->dicionario = new HashTable();    }
}
Dicionario* Dicionario::criaDic(){
    if(instancia == nullptr){
        instancia = new Dicionario();
    }
    return instancia;
}
void Dicionario::insereDic(Word* word){
    dicionario->append(word);
}
void Dicionario::pesquisaDic(string key){
    dicionario->search(key);
}
void Dicionario::imprimeDic(){
    dicionario->print();
}
void Dicionario::removeDic(string key){
    dicionario->remove(key);
}
void Dicionario::destroiDic(Dicionario * dic){
    delete(dicionario);
}

void Dicionario::atualizaDic(){
    dicionario->removeWithMeaning();
}