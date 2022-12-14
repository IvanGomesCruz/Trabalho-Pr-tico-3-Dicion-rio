#include "OrdenedListString.hpp"

void OrdenedListString::append(string line){
    if(this->_frist == NULL){
        this->_frist = new Node(line);
        this->_last = this->_frist;
        return;
    }
    Node* aux =this->_frist;
    Node* previus=NULL;
    while(aux!=NULL){
            if(!stringComp(aux->getStr(),line,0)){
                break;
            }
            previus = aux;
            aux=aux->next;
    }
    
    if(aux == this->_frist){
            this->_frist = new Node(line);
            this->_frist->next = aux;
            return;
    }
    previus->next = new Node(line);
    previus->next->next = aux;


}

bool OrdenedListString::stringComp(string frist, string second, long unsigned int i) {

  if ((int)frist[i] < (int)second[i]) {
    return true;
  } else if ((int)frist[i] > (int)second[i]) {
    return false;
  } else {
    if (i == frist.size() - 1) {
      return true;
    } else if (i != frist.size() - 1 && i == second.size() - 1) {
      return false;
    }
    return stringComp(frist, second, i + 1);
  }
}

void OrdenedListString::print(){
    
    if(this->isEmpty()){
        return;
    }
    Node* aux = this->_frist;
    ConfigSaida* output= ConfigSaida::getInstancia();
    while(aux != NULL){
        output->print(aux->getStr());
        output->print("\n");
        aux = aux->next;
    }
}