#include "Word.hpp"

Word::Word(string type, string word){

    this->_type = type;
    this->_word = word;

}

void Word::print(){
    ConfigSaida* output = ConfigSaida::getInstancia();
    output->print(this->_word);
    output->print(" (");
    output->print(this->_type);
    output->print(")");
    output->print("\n");
    this->_meanings.print();
}

void Word::appendMeaning(string line){

    this->_meanings.append(line);

}

bool Word::operator ==(Word word){
    if(this->getWord() == word.getWord() && this->getType() == word.getType()){
        return true;
    }
    return false;
}

string Word::getWord(){
    return _word;
}
string Word::getType(){
    return _type;
}

int Word::getKeyT(){
    int c = getWord()[0]-96;
    return c;
}