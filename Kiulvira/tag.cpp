#include "tag.hpp"

Tag::Tag(QString name, QColor colour) {
    this->name = name;
    this->colour = colour;
}

Tag::Tag(QString name) {
    this->name = name;
}

QString Tag::getName() {
    return this->name;
}

QColor Tag::getColour() {
    return this->colour;
}

bool Tag::operator==(const Tag& other) {
    return this->name == other.name;
}


Tag& Tag::operator=(Tag tag){
  std::swap(tag, *this);
  return *this;
}
