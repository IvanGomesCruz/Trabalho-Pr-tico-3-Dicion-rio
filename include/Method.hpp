#ifndef METHOD_H
#define METHOD_H
#include "Word.hpp"

    class Method
    {
    public:
    virtual void search(string key) = 0;
    virtual void append(Word* item) = 0;
    virtual void remove(string key) = 0;
    virtual void print() = 0;
    virtual void removeWithMeaning() = 0;
    };
    


#endif