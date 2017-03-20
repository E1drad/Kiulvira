#ifndef TAGHANDLER_HPP
#define TAGHANDLER_HPP

#include <algorithm>
#include <vector>
#include "data2.hpp"
#include "tag.hpp"
#include <iostream>
#include <QString>

class TagHandler {
private:
    Tag* tag;
    std::vector<Data*> datasAssociated;

public:
    TagHandler(QString name, QColor colour);
    TagHandler(QString name);
    Tag* getTag();
    ~TagHandler();
    std::vector<Data*> getDatasAssociated();
    bool associateData(Data* data);
    void disassociateData(Data* data);
    int getSizeDataAssociated();
    QString getTagName();
};

#endif // TAGHANDLER_HPP
