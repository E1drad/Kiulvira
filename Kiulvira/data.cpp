#include "data.hpp"

Data::Data(string name, Data* parent) {
    this->name = name;
    this->parent = parent;
}

Data::Data(string name) {
    this->name = name;
}

/**
 * @brief addTag
 * @param tag
 * @return true if the tag was added to the data
 */
bool Data::addTag(Tag tag) {
    return this->tags.insert(tag).second;
}

/**
 * @brief removeTag
 * @param tag
 * @return true if the tag was attached to this data
 */
bool Data::removeTag(Tag tag) {
    return (this->tags.erase(tag).second > 0);
}

std::string Data::getName() {
    return this->name;
}

std::string Data::getPath() {
    return this->parent->getParent().getPath() + "/" + this->name;
}

Data* Data::getParent() {
    return this->parent;
}

std::set<Tag> Data::getTags() {
    return this->tags;
}
