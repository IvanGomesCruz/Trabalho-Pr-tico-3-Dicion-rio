#include "ListString.hpp"


ListString::ListString()
{
    this->_frist = NULL;
    this->_last = NULL;
}

ListString::~ListString()
{
    delete(this->_frist);
    this->_frist = NULL;
    this->_last = NULL;
}

void ListString::print(){
    if(this->isEmpty()){
        return;
    }
    Node* aux = this->_frist;
    int num =1;
    while(aux != NULL){
        cout<<num<<". "<<aux->getMeaning()<<endl;
        aux = aux->next;
        num++;
    }
}
void ListString::append(string line){
    if(this->_frist == NULL){
        this->_frist = new Node(line);
        this->_last = this->_frist;
        return;
    }
    Node* aux = new Node(line);
    this->_last->next = aux;
    this->_last = aux;
}

bool ListString::isEmpty(){
    if(this->_frist == NULL){
        return true;
    }
    return false;
}