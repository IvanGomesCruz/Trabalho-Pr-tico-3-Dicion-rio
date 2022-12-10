#include "Node.hpp"

Node::Node(string meaning)
{
    this->_meaning = meaning;
    next = NULL;
}

Node::~Node()
{
    delete(next);
}
string Node::getMeaning(){
    return _meaning;
}