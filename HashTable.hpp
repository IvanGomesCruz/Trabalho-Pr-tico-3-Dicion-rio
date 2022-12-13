#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include "Word.hpp"
#include "List.hpp"
#include "OrdenedListString.hpp"
#define TipoItem Word*
#define TipoChave string


class HashTable
{
public:

     ElementList* Pesquisa(TipoChave chave);
    void Insere(TipoItem item);
    void Remove(TipoChave chave);
    static const int M = 7;
    List Tabela[M];
    OrdenedListString ListChave;
    void PrintOrdenado();
    void RemoveWithMeaning();
private:
    int Hash(TipoChave Chave);

};
#endif