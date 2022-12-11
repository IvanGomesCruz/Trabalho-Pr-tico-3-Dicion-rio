#ifndef CONFIGSAIDA_H
#define CONFIGSAIDA_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ConfigSaida
{
private:
    string _arquivo;
    static ConfigSaida* instancia;
    ConfigSaida(string arquivo);
    std::ofstream f_out;
public:
    static ConfigSaida* getInstancia();
    static ConfigSaida* getInstancia(string arquivo);
    void print(string str);
    ~ConfigSaida();
};


#endif