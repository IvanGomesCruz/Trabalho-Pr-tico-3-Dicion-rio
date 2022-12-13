#include "HashTable.hpp"
#include <iostream>
#include <string>


    ElementList* HashTable::Pesquisa(TipoChave chave){
        int hash = Hash(chave);
        return this->Tabela[hash].find(chave);
    }
    void HashTable::Insere(TipoItem item){
        string chave = item->getKeyT();
        int hash = Hash(chave);
        ElementList* find = Pesquisa(chave);
        if(find == NULL){
            ElementList* aux = new ElementList(item);
            this->Tabela[hash].push(aux);
            this->ListChave.append(aux->getObject()->getKeyT());
        }
        else{
            if(!item->meanings.isEmpty()){
                find->getObject()->appendMeaning(item->getMeaning());
            }
        }
    }
    void HashTable::Remove(TipoChave chave){
        ElementList* find = Pesquisa(chave);
        if(find==NULL){
            return;
        }
        int hash= Hash(chave);
        this->Tabela[hash].remove(find);
    }
    int  HashTable::Hash(TipoChave chave){
        int aux =0;
        for(int i=0;i<chave.size();i++){
            aux+= chave[i]*i;
        }
        return aux%M;
    }

    void HashTable::PrintOrdenado(){
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

     void HashTable::RemoveWithMeaning(){
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

    
