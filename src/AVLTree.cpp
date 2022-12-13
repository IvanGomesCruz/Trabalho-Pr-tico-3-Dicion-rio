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
int balance =height(node->rightChild) - AVLTree::height(node->leftChild);
return balance;
}


AVLNode* AVLTree::append(AVLNode* &p, Word* item){
    if(p==NULL){
        p = new AVLNode(item);
        p->leftChild = NULL;
        p->rightChild = NULL;
        p->height=AVLTree::height(p);
        return p;
    }
    string key = item->getKeyT();
    if(compareKey(p->key,key)){
        p->leftChild =append(p->leftChild, item);
    }
    else{
        p->rightChild =append(p->rightChild, item);
    }

    p->height=AVLTree::height(p);
    if(balanceFactor(p)==2 && balanceFactor(p->rightChild) == 1){
        p = rightRotate(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->leftChild) == -1){
        p = leftRotate(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->leftChild) == 1){
        p = leftRightRotate(p);
        
    }
    else if(balanceFactor(p)==2 && balanceFactor(p->rightChild) == -1){
        p = rightLeftRotate(p);
    }
    return p;
}
AVLNode* AVLTree::find(string key){
    return search(this->root,key);
}

AVLNode* AVLTree::search(AVLNode* node, string key){
    if(node != NULL){
        if(node->getKey() == key){
            return node;
        }
        if(compareKey(key,node->getKey())){
            return search(node->rightChild,key);
        }
        else{
            return search(node->leftChild,key);
        }
    }
    return NULL;

}
AVLNode* AVLTree::rightRotate(AVLNode* node){
    AVLNode* aux;
    AVLNode* next;
    aux = node;
    next = aux->rightChild;

    aux->rightChild = next->leftChild;
    next->leftChild = aux;
    return next;
}

AVLNode* AVLTree::leftRotate(AVLNode* node){
    AVLNode* aux;
    AVLNode* next;
    aux = node;
    next = aux->leftChild;

    aux->leftChild = next->rightChild;
    next->rightChild = aux;
    return next;
}

AVLNode* AVLTree::leftRightRotate(AVLNode* node){
    AVLNode* aux;
    AVLNode* next;
    AVLNode* aux2;
    aux = node;
    next = aux->leftChild;
    aux2 = node->leftChild->rightChild;

    aux->leftChild = aux2->rightChild;
    next->rightChild = aux2->leftChild;
    aux2->rightChild = aux;
    aux2->leftChild = next;
    return aux2;
}

AVLNode* AVLTree::rightLeftRotate(AVLNode* node){
    AVLNode* aux;
    AVLNode* next;
    AVLNode* aux2;
    aux = node;
    next = aux->rightChild;
    aux2 = node->rightChild->leftChild;

    aux->rightChild = aux2->leftChild;
    next->leftChild = aux2->rightChild;
    aux2->leftChild = aux;
    aux2->rightChild = next;
    return aux2;
}

bool AVLTree::compareKey(string key1,string key2){
    return !stringComp(key1,key2,0);
}

bool AVLTree::stringComp(string frist, string second, int i) {

  if ((int)frist[i] < (int)second[i]) {
    return true;
  } else if ((int)frist[i] > (int)second[i]) {
    return false;
  } else {
    if (i == frist.size() - 1) {
      return true;
    } else if (i != frist.size() - 1 && i == second.size() - 1) {
      return false;
    }
    return stringComp(frist, second, i + 1);
  }
}

AVLNode* AVLTree::remove(AVLNode* &p, string key){
    if(p->leftChild==NULL && p->rightChild==NULL){
        if(p==this->root){
            this->root = NULL;
        }
        delete p;
        return NULL;
    }

    
    AVLNode* aux;

    if(compareKey(p->key,key)){
        p->leftChild =remove(p->leftChild, key);
    }
    else if(compareKey(key,p->key)){
        p->rightChild =remove(p->rightChild, key);
    }
    else{
        if(p->leftChild != NULL){
            aux = lastLeftChild(p->leftChild);
            p->content = aux->content;
            p->key = aux->key;
            p->leftChild = remove(p->leftChild,aux->content->getKeyT());
        }
        else{
            aux = fristRightChild(p->rightChild);
            p->content = aux->content;
            p->key = aux->key;
            p->rightChild = remove(p->rightChild,aux->content->getKeyT());
        }
        
    }
    p->height=AVLTree::height(p);
    if(balanceFactor(p)==2 && balanceFactor(p->rightChild) == 1){
        p = rightRotate(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->leftChild) == -1){
        p = leftRotate(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->leftChild) == 1){
        p = leftRightRotate(p);
        
    }
    else if(balanceFactor(p)==2 && balanceFactor(p->rightChild) == -1){
        p = rightLeftRotate(p);
    }
    else if(balanceFactor(p)==2 && balanceFactor(p->rightChild) == 0){
        p = rightRotate(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->leftChild) == 0){
        p = leftRotate(p);
    }
    return p;
}

AVLNode* AVLTree::lastLeftChild(AVLNode* node){
    while(node->rightChild!=NULL){
        node=node->rightChild;
    }
    return node;

}
AVLNode* AVLTree::fristRightChild(AVLNode* node){
       while(node->leftChild!=NULL){
        node=node->leftChild;
    }
    return node;


}

void AVLTree::preOrder(AVLNode *root)
{ 
  if(root != NULL)
  {
    preOrder(root->leftChild); 
    root->content->print(); 
    preOrder(root->rightChild);  
    }
}

void AVLTree::removeWithMeaning(AVLNode *root)
{ 
  if(root != NULL)
  {
     if(!root->content->meanings.isEmpty()){
        root = remove(this->root,root->content->getKeyT());
    } 
    removeWithMeaning(root->leftChild); 
   
    removeWithMeaning(root->rightChild); 
  }
}
void AVLTree::deleteTree(AVLNode *root)
{ 
  if(root != NULL)
  {
    root = remove(this->root,root->content->getKeyT());
    removeWithMeaning(root->leftChild);
    removeWithMeaning(root->rightChild); 
  }
}

void AVLTree::search(string key){
    AVLNode* aux =search(this->root,key);
    aux->content->print();

}
void AVLTree::append(Word* item){
    AVLNode* node = find(item->getKeyT());
    if(node!=NULL){
      if(!item->meanings.isEmpty()){
        node->content->appendMeaning(item->getMeaning());
      }
    }
    else{
      append(root,item);
    }
}
void AVLTree::remove(string key){
    remove(this->root,key);
}
void AVLTree::print(){
    preOrder(this->root);
}

void AVLTree::removeWithMeaning(){
    removeWithMeaning(this->root);
}

AVLTree::~AVLTree(){
    delete(root);
}