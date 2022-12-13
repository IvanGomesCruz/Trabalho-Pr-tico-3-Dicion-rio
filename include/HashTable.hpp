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
    ~HashTable();
    void append(TipoItem item);
    void remove(TipoChave key);
    void print();
    void removeWithMeaning();
    void search(TipoChave key);
    HashTable(int Max);
private:
    ElementList* find(TipoChave key);
    int M;
    List* Tabela;
    OrdenedListString ListChave;
    int Hash(TipoChave key);
  friend class Dicionario;
};
#endif