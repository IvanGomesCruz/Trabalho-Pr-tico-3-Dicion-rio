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
string key;
int height;
AVLNode* leftChild;
AVLNode* rightChild;
AVLNode(Word* word);
string getKey();
};

#endif



