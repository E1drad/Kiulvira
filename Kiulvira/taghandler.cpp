#include "taghandler.hpp"

TagHandler::TagHandler(QString name, QColor colour){
    this->tag = new Tag(name, colour);
}

TagHandler::TagHandler(QString name){
    this->tag = new Tag(name);
}

Tag* TagHandler::getTag(){
    return this->tag;
}

TagHandler::~TagHandler(){
    delete this->tag;
    this->datasAssociated.clear();
}

std::vector<Data*> TagHandler::getDatasAssociated(){
    return this->datasAssociated;
}

bool TagHandler::associateData(Data* data){
    bool isAdd;
    if(std::find(this->datasAssociated.begin(), this->datasAssociated.end(), data)
            != this->datasAssociated.end()) {//data is already in the vector.
        std::cout << data->getName() << " is already associated to that tag" << std::endl;
        isAdd = false;
    } else {//data isn't in the vector
        this->datasAssociated.push_back(data);
        isAdd = true;
    }
    return isAdd;
}

void TagHandler::disassociateData(Data* data){
    this->datasAssociated.erase(
                std::remove(this->datasAssociated.begin(),
                            this->datasAssociated.end(), data), this->datasAssociated.end());
}

int TagHandler::getSizeDataAssociated(){
    return this->datasAssociated.size();
}


QString TagHandler::getTagName(){
    return this->tag->getName();
}
