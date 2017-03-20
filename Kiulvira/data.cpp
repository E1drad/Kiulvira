#include "data2.hpp"

Data::Data(std::string name, Data* parent) {
    this->name = name;
    this->parent = parent;
}

Data::Data(std::string name) {
    this->name = name;
}

Data::~Data(){
    this->parent = nullptr;
    this->tags.clear();
}

/**
 * @brief addTag
 * @param tag
 */
void Data::addTag(Tag* tag) {
    this->tags.push_back(tag);
}

/**
 * @brief removeTag
 * @param tag
 */
void Data::removeTag(Tag* tag) {
    this->tags.erase(std::remove(this->tags.begin(), this->tags.end(), tag), this->tags.end());
}

std::string Data::getName() {
    return this->name;
}

std::string Data::getPath() {
    return this->parent->getParent()->getPath() + "/" + this->name;
}

Data* Data::getParent() {
    return this->parent;
}

std::vector<Tag*> Data::getTags() {
    return this->tags;
}
