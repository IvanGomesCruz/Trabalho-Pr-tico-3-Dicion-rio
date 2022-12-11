#ifndef LISTSTRING_H
#define LISTSTRING_H

#include <iostream>
#include <string>
#include "Node.hpp"
#include "ConfigSaida.hpp"
using namespace std;

class ListString
{
private:
    Node* _frist;
    Node* _last;
    int size;

public:
    ListString();
    ~ListString();
    void print();
    void append(string line);
    bool isEmpty();
};
#endif