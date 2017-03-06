#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <set>

class Data {
private:
    std::string name;
    Data* parent;
    std::set<Tag> tags;

public:
    Data(string name, Data* parent);
    Data(string name);

    bool addTag(Tag tag);
    bool removeTag(Tag tag);


    std::string getName();
    std::string getPath();
    Data* getParent();
    std::set<Tag> getTags();
};

#endif // DATA_HPP
