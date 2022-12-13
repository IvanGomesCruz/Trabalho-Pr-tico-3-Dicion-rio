#include "HashTable.hpp"
#include <iostream>
#include <string>

    HashTable::HashTable(int Max){
        this->M = Max;
        this->Tabela = new List[Max]();
    }

    ElementList* HashTable::find(TipoChave key){
        int hash = Hash(key);
        return this->Tabela[hash].find(key);
    }
    void HashTable::append(TipoItem item){
        string key = item->getKeyT();
        int hash = Hash(key);
        ElementList* aux = find(key);
        if(aux == NULL){
            ElementList* aux = new ElementList(item);
            this->Tabela[hash].push(aux);
            this->ListChave.append(aux->getObject()->getKeyT());
        }
        else{
            if(!item->meanings.isEmpty()){
                aux->getObject()->appendMeaning(item->getMeaning());
            }
        }
    }
    void HashTable::remove(TipoChave key){
        ElementList* element = find(key);
        if(element==NULL){
            return;
        }
        int hash= Hash(key);
        this->Tabela[hash].remove(element);
    }

    int  HashTable::Hash(TipoChave key){
        int aux =0;
        for(long unsigned int i=0;i<key.size();i++){
            aux+= key[i]*i;
        }
        return aux%M;
    }

    void HashTable::print(){
        Node* aux = this->ListChave._frist;
        ElementList* aux2;
        while(aux!=NULL){
            int hash = Hash(aux->getStr());
            aux2 =this->Tabela[hash].find(aux->getStr());
            if(aux2!=NULL){
                aux2->getObject()->print();
            }
            aux=aux->next;
        }
    }

     void HashTable::removeWithMeaning(){
        Node* aux = this->ListChave._frist;
        ElementList* aux2;
        while(aux!=NULL){
            int hash = Hash(aux->getStr());
            aux2 =this->Tabela[hash].find(aux->getStr());
            if(!aux2->getObject()->meanings.isEmpty()){
                this->Tabela[hash].remove(aux2);
            }
            aux=aux->next;
        }
    }
void HashTable::search(string key){
    ElementList* aux = find(key);
    aux->getObject()->print();
}

HashTable::~HashTable(){
    delete(Tabela);
}
    
