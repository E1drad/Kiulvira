#include "directory.hpp"

Directory::Directory(std::string name, Data* parent):Data::Data(name,parent) {

}

Directory::Directory(std::string name):Data::Data(name) {

}
