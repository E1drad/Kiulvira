#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "data.hpp"
#include <set>

class Directory : public Data {
private:
    std::set<Data> content;

public:
    Directory(string name, Data* parent);
    Directory(string name);
};

#endif // DIRECTORY_HPP
