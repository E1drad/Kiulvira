#include "tag.hpp"

Tag::Tag(std::string name, QColor colour) {
    this->name = name;
    this->colour = colour;
}

std::string Tag::getName() {
    return this->name;
}

QColor Tag::getColour() {
    return this->colour;
}

bool Tag::operator==(const Tag& other) {
    return this->name == other.name && this->colour == other.colour;
}
