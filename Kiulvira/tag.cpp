#include "tag.hpp"

Tag::Tag(std::string name, QColor colour) {
    this->name = name;
    this->colour = colour;
}

std::string Tag::getName(){
    return this->name;
}

QColor Tag::getColour(){
    return this->colour;
}
