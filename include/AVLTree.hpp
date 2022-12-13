
#include <iostream>
#include <string>
#include "AVLNode.hpp"
#include "Word.hpp"
#include "Method.hpp"
using namespace std;

#define LEFT_LEFT 1
#define RIGHT_RIGHT 2
#define LEFT_RIGHT 3
#define RIGHT_LEFT 4

#ifndef AVLT
#define AVLT

class AVLTree:Method
{
private:

    AVLNode* root;
    static int height(AVLNode* node);
    static int balanceFactor(AVLNode *node);
    AVLNode* append(AVLNode* &p, Word* item);
    AVLNode* leftRotate(AVLNode* node);
    AVLNode* rightRotate(AVLNode* node);
    AVLNode* leftRightRotate(AVLNode* node);
    AVLNode* rightLeftRotate(AVLNode* node);

    AVLNode* remove(AVLNode* &p,string key);
    AVLNode* find(string key);
    AVLNode* search(AVLNode* node, string key);
    bool compareKey(string key1,string key2);
    bool stringComp(string frist, string second, long unsigned int i);

    AVLNode* lastLeftChild(AVLNode* node);
    AVLNode* fristRightChild(AVLNode* node);
    void removeWithMeaning(AVLNode *root);
    void deleteTree(AVLNode *root);
    void preOrder(AVLNode *root);

public:
    ~AVLTree();
    AVLTree();
    void search(string key);
    void append(Word* item);
    void remove(string key);
    void print();
    void removeWithMeaning();
friend class Dicionario;
};



#endif
