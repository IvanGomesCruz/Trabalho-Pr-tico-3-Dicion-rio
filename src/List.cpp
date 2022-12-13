#include "List.hpp"

List::List(){
    this->_frist = nullptr;
    this->_last = nullptr;
}

void List::push(ElementList *element){
// Descricao: Método que adiciona um novo elemento a lista
// Entrada: ElementList*
// Saida: void
    if(this->_last == nullptr && this->_frist == nullptr){
    //Caso seja o primeiro elemento adicionado, ele será o primeiro e o último.
        this->_frist = element;
        this->_last = element;
        return;
    }
    //Caso não seja o primiro ele deve ser adicionado ao next do ultimo e deve entrar como novo ultimo elemento
    this->_last->_next = element;
    element->_previous = this->_last;
    this->_last = element;
    return;
}
ElementList* List::find(string ID){
// Descricao: Método que encontra o usuário que possui a ID recebida na entrada.
// Entrada: unsigned int 
// Saida: ElementList*
    ElementList* aux= this->_frist;
    while (aux != nullptr)
    //Enquanto aux não for o final do vetor ele segue a busca
    {
        if(aux->getObject()->getKeyT() == ID){
            //Para a execução do método e retorna o ponteiro para o Elemento, caso o encontre
            return aux;
        }
        aux = aux->_next;
    }
    //Retorna null caso o método chege no fim da lista e não encontre
    return NULL;

}

void List::remove(ElementList* element){
// Descricao: Método que remove um determinado elemento dada sua ID
// Entrada: unsigned int
// Saida: void

    if(element == this->_frist){
        //Caso seja o primeiro elemento da lista deve-se colocar o proximo como novo primeiro e colocar o valor nullptr no previous do novo primeiro
        if(element!=this->_last){
            this->_frist= element->_next;
            element->_next->_previous = nullptr;
        }
        else{
            this->_frist = nullptr;
            this->_last = nullptr;
        }
            delete(element);
            element = nullptr;
            return;
    }
    if(element==this->_last){
        //Caso seja o último deve-se colocar o valor de nullptr no anterior a ele e atualizar o valor de último para um ponteiro para o anterior ao removido
        element->_previous->_next = nullptr;
        this->_last = element->_previous;
        delete(element);
        element= nullptr;
        return;
    }
    //Caso não seja nem o primeiro nem o último, devemos fazer o next do anterior apontar para o next do a ser removido e o previous do  next do a ser removido apontar para o anterior a ele.
    element->_previous->_next = element->_next;
    element->_next->_previous = element->_previous;
    delete(element);
    element=nullptr;
}

void List::clear(){
// Descricao: Função recursiva que remove todos os elementos da lista
// Entrada: 
// Saida: 
    if(this->isEmpty()){
        return;
    }
    ElementList* aux = this->_frist;
    this->_frist = aux->_next;
    delete(aux);
    this->clear();
}
bool List::isEmpty(){
// Descricao: função que verifica se a lista esta vazia
// Entrada:  
// Saida: bool
    if(this->_frist == nullptr && this->_last==nullptr){
        return true;
    }
    return false;
}