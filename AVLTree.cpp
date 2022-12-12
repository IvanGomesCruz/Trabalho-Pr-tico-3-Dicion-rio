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
int balance =height(node->rightChild) -
AVLTree::height(node->leftChild);
return balance;
}


void AVLTree::rightRotate(AVLNode* node){
    if(node->parent == this->root){
        this->root = node;
    }
    node->parent->leftChild = node->rightChild;
    node->rightChild = node->parent;
    if(node->key > node->parent->key){
        node->parent->parent->rightChild = node;
    }
    
    AVLNode* aux = node->parent;
    node->parent = node->parent->parent;
    aux->parent = node;
    if(aux->leftChild != NULL){
        aux->leftChild->parent = aux;
    }
}

void AVLTree::leftRotate(AVLNode* node){
    if(node->parent == this->root){
        this->root = node;
    }
    node->parent->rightChild = node->leftChild;
    node->leftChild = node->parent;
    if(node->key < node->parent->key){
        node->parent->parent->leftChild = node;
    }
    cout<<"chego"<<endl;
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
    }
    else{
        append(p->rightChild, item);
        p->rightChild->parent = p;
    }

    p->height=AVLTree::height(p);
    balancear(p,key);
    
}


void AVLTree::balancear(AVLNode* p,int key){
    int balance = balanceFactor(p->parent);


    if (balance > 1 && key < p->key){
        cout<<"caso 1"<<endl;
        cout<<"L - "<<p->key<<endl;
       leftRotate(p);
       cout<<"R - "<<p->parent->key<<endl;
        rightRotate(p);
        return;
    }

    if(balance < -1 && key > p->key){
        leftRotate(p->rightChild);
        //rightRotate(p);
        return;
    }  


    if(balance > 1 && key > p->key){
        cout<<"Caso 1"<<endl;
        leftRotate(p);
        return;
    }

    if(balance < -1 && key < p->key){

        rightRotate(p);
        return;
    }
    
}

AVLNode* AVLTree::find(int key){
    return search(this->root,key);
}

AVLNode* AVLTree::search(AVLNode* node, int key){
    if(node != NULL){
        if(node->getKey() == key){
            return node;
        }
        if(key > node->getKey()){
            return search(node->rightChild,key);
        }
        else{
            return search(node->leftChild,key);
        }
    }
    return NULL;

}