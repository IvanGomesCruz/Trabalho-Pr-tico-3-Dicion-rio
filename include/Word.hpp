#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include "ListString.hpp"
#include "ConfigSaida.hpp"
using namespace std;
class Word
{
private:
    string _type;
    string _word;

public:
    ListString meanings;
    int numMeanings;
    Word(string type, string word);
    void print();
    void appendMeaning(string line);
    bool operator ==(Word word2);
    string getWord();
    string getType();
    string getKeyT();
    string getMeaning();
};


#endif