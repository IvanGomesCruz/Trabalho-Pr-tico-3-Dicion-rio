#include "AVLTree.hpp"
AVLTree::AVLTree(){
    this->root =NULL;
}
int AVLTree::height(AVLNode* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->leftChild),height(node->rightChild));
}

int AVLTree::balanceFactor(AVLNode *node) {
    if (node == NULL) return 0;
    return node->rightChild->height - node->leftChild->height;
}


void rightRotate(AVLNode* node){
    node->parent->leftChild = node->rightChild;
    node->rightChild = node->parent;
    node->parent->parent->leftChild = node;
    AVLNode* aux = node->parent;
    node->parent = node->parent->parent;
    aux->parent = node;
    if(aux->leftChild != NULL){
        aux->leftChild->parent = aux;
    }
}

void leftRotate(AVLNode* node){
    node->parent->rightChild = node->leftChild;
    node->leftChild = node->parent;
    AVLNode* aux = node->parent;
    node->parent = node->parent->parent;
    aux->parent = node;
    if(aux->rightChild != NULL){
        aux->rightChild->parent = aux;
    }

}

void AVLTree::append(AVLNode* &p, Word* item){
    if(p==NULL){
        p = new AVLNode(item);
        p->height=AVLTree::height(p);
        return;
    }
    int key = item->getKeyT();
    if(key < p->key){
        append(p->leftChild, item);
        p->leftChild->parent = p;
        p->height=AVLTree::height(p);
    }
    else{
        append(p->rightChild, item);
        p->rightChild->parent = p;
        p->height=AVLTree::height(p);
    }
    

}


void AVLTree::balancear(AVLNode* &p,int key){
        int balance = balanceFactor(p->parent);
        if (balance > 1 && key < p->leftChild->key){
        rightRotate(p);
    }
// Right Right Case
    if(balance < -1 && key > p->rightChild->key){
        leftRotate(p);
    }  

// Left Right Case
    if(balance > 1 && key > p->leftChild->key){
        leftRotate(p->leftChild);
        rightRotate(p);
    }
// Right Left Case
    if(balance < -1 && key < p->rightChild->key){
        rightRotate(p->rightChild);
        leftRotate(p);
    }

}