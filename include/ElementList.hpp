#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H

#include<iostream>
#include "Word.hpp"

using namespace std;
class ElementList
{
private:
    Word* _object;
    ElementList* _next;
    ElementList* _previous;
public:
    ElementList(Word* object);
    Word* getObject();

friend class List;
};


#endif