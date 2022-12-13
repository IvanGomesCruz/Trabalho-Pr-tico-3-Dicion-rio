
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
    AVLNode* append(AVLNode* &p, Word* item);
    AVLNode* leftRotate(AVLNode* node);
    AVLNode* rightRotate(AVLNode* node);
    AVLNode* leftRightRotate(AVLNode* node);
    AVLNode* rightLeftRotate(AVLNode* node);

    AVLNode* remove(AVLNode* &p,Word* item);
    AVLNode* find(string key);
    AVLNode* search(AVLNode* node, string key);
    bool compareKey(string key1,string key2);
    bool stringComp(string frist, string second, int i);

    AVLNode* lastLeftChild(AVLNode* node);
    AVLNode* fristRightChild(AVLNode* node);
    void removeWitchMeaning(AVLNode *root);
    void deleteTree(AVLNode *root);
    void preOrder(AVLNode *root);

};



#endif
