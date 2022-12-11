#include"AVLNode.hpp"

AVLNode::AVLNode(Word* word){
    this->content = word;
    this->key = content->getKeyT();
    this->leftChild = NULL;
    this->rightChild = NULL;
}
int AVLNode::getKey(){
    return key;
}