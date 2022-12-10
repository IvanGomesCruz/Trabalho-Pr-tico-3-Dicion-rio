#include <iostream>
#include <string>
#include "Node.hpp"

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
