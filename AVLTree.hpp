
#include <iostream>
#include "AVLNode.hpp"
#include "Word.hpp"
#include <string>
using namespace std;

#define LEFT_LEFT 1
#define RIGHT_RIGHT 2
#define LEFT_RIGHT 3
#define RIGHT_LEFT 4

#ifndef AVLT
#define AVLT

class AVLTree
{
private:
public:
    AVLTree();

    AVLNode* root;
    static int height(AVLNode* node);
    static int balanceFactor(AVLNode *node);
    void append(AVLNode* &p, Word* item);
    void balancear(AVLNode* p,int key);
    void leftRotate(AVLNode* node);
    void rightRotate(AVLNode* node);

    //void remove(Word* item);
    AVLNode* find(int key);
    AVLNode* search(AVLNode* node, int key);

};



#endif
