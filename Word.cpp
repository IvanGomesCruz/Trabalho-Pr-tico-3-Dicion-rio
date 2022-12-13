#include "Word.hpp"

Word::Word(string type, string word){

    this->_type = type;
    this->_word = word;
    this->numMeanings =0;

}

void Word::print(){
    ConfigSaida* output = ConfigSaida::getInstancia();
    output->print(this->_word);
    output->print(" (");
    output->print(this->_type);
    output->print(")");
    output->print("\n");
    this->meanings.print();
}

void Word::appendMeaning(string line){

    this->meanings.append(line);
    numMeanings +=1;
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

string Word::getKeyT(){
    return getWord().append(" "+getType());
}

string Word::getMeaning(){
    if(numMeanings != 0){
        return this->meanings._frist->getStr();
    }
}