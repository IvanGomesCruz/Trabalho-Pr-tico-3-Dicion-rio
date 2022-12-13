#ifndef LISTSTRING_H
#define LISTSTRING_H

#include <iostream>
#include <string>
#include "Node.hpp"
#include "ConfigSaida.hpp"
using namespace std;

class ListString
{
protected:
    Node* _last;
private:
    int size;

public:
    Node* _frist;
    ListString();
    ~ListString();
    void print();
    void append(string line);
    bool isEmpty();
};
#endif