#ifndef CONFIGENTRADA_H
#define CONFIGENTRADA_H
#include <iostream>
#include <string>
using namespace std;
class ConfigEntrada
{
private:
    ConfigEntrada(string entrada);
    static ConfigEntrada* instancia;
    string identificaFlag(string entrada,string flag);
public:
    string i;
    string o;
    static ConfigEntrada* getInstancia();
    static ConfigEntrada* getInstancia(string entrada);
};



#endif