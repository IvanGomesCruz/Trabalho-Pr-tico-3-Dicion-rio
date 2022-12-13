#include "ElementList.hpp"
class List
{
private:
    ElementList* _last;
public:
    List();
    ElementList* _frist;
    ElementList* find(string ID);
    void push(ElementList *element);
    void remove(ElementList* element);
    void clear();
    bool isEmpty();
};


