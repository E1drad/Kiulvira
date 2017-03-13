#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "data.hpp"
#include <vector>

class Directory : public Data {
private:
    std::vector<Data> content;

public:
    Directory(std::string name, Data* parent);
    Directory(std::string name);
};

#endif // DIRECTORY_HPP
