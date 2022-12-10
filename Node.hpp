#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    string _meaning;

public:
    Node* next;
    Node(string line);
    string getMeaning();
    ~Node();
};
