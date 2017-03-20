#ifndef FILE_HPP
#define FILE_HPP

#include "data2.hpp"

class File : public Data {
private:

public:
    File(std::string name, Data* parent);
};

#endif // FILE_HPP
