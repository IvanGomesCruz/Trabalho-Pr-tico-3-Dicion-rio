#include "Node.hpp"

Node::Node(string str)
{
    this->_str = str;
    next = NULL;
}

Node::~Node()
{
    delete(next);
}
string Node::getStr(){
    return _str;
}