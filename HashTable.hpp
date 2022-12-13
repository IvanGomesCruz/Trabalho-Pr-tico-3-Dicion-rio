#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include "Word.hpp"
#include "List.hpp"
#include "OrdenedListString.hpp"
#include "Method.hpp"
#define TipoItem Word*
#define TipoChave string


class HashTable: public Method
{
public:

    void append(TipoItem item);
    void remove(TipoChave key);
    void print();
    void removeWithMeaning();
    void search(TipoChave key);
private:
    ElementList* find(TipoChave key);
    static const int M = 7;
    List Tabela[M];
    OrdenedListString ListChave;
    int Hash(TipoChave key);
  friend class Dicionario;
};
#endif