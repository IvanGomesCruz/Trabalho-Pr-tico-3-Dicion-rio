#ifndef DICIONARIO_H
#define DICIONARIO_H
#include "Word.hpp"
#include "HashTable.hpp"
#include "AVLTree.hpp"
#include "Method.hpp"
#include "ConfigEntrada.hpp"
#include "ConfigSaida.hpp"

class Dicionario
{
private:
    bool AVL;
    bool Hash;
    Method* dicionario;
    static Dicionario* instancia;
    Dicionario();
public:
    static Dicionario* criaDic();
    void insereDic(Word* word);  
    void pesquisaDic(string key);
    void imprimeDic();
    void removeDic(string key);
    void destroiDic(Dicionario * dic);
    void atualizaDic();
};





#endif