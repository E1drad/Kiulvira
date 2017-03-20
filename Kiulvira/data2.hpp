#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <vector>
#include "tag.hpp"
#include <algorithm>

class Data {
protected:
    std::string name;
    Data* parent;
    std::vector<Tag*> tags;

public:
    Data(std::string name, Data* parent);
    Data(std::string name);
    ~Data();
    void addTag(Tag* tag);
    void removeTag(Tag* tag);

    std::string getName();
    std::string getPath();
    Data* getParent();
    std::vector<Tag*> getTags();
};

#endif // DATA_HPP
