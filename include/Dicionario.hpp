#ifndef DICIONARIO_H
#define DICIONARIO_H
#include "Word.hpp"
#include "HashTable.hpp"
#include "AVLTree.hpp"
#include "Method.hpp"
#include "ConfigEntrada.hpp"


class Dicionario
{
private:
    bool AVL;
    bool Hash;
    Method* dicionario;
    static Dicionario* instancia;
    Dicionario();
    Dicionario(int M);

public:
    static Dicionario* criaDic(int M);
    static Dicionario* criaDic();
    void insereDic(Word* word);  
    void pesquisaDic(string key);
    void imprimeDic();
    void removeDic(string key);
    void destroiDic(Dicionario * dic);
    void atualizaDic();
};





#endif