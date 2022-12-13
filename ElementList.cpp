#include "ElementList.hpp"

ElementList::ElementList(Word* object){
    this->_object = object;
        this->_next = nullptr;
        this->_previous = nullptr;
}
Word* ElementList::getObject(){
// Descricao: Get de Object
// Entrada:  
// Saida: Word*
    return this->_object;
}
