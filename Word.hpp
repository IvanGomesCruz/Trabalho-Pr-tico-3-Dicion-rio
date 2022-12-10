#include <iostream>
#include <string>
#include "ListString.hpp"
using namespace std;
class Word
{
private:
    string _type;
    string _word;
    ListString _meanings;

public:
    Word(string type, string word);
    void print();
    void appendMeaning(string line);
    bool operator ==(Word word2);
    string getWord();
    string getType();
};

