#ifndef AVLN
#define AVLN


#include <iostream>
#include <string>
#include "Word.hpp"

using namespace std;
class AVLNode
{
public:
Word* content;
int key;
int height;
AVLNode* leftChild;
AVLNode* rightChild;
AVLNode* parent;
AVLNode(Word* word);
int getKey();
};

#endif



