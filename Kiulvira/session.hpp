#ifndef SESSION_HPP
#define SESSION_HPP

#include <algorithm>
#include <QString>
#include <vector>
#include "data2.hpp"
#include "taghandler.hpp"
#include <string>
#include <utility>
#include <iostream>
#include <QModelIndex>

class Session {
private:
    std::vector< std::pair<std::vector<Data*>, QString> >  groupes;
    std::vector<TagHandler*> quickAccessTag;
    unsigned int maxNumberOfQATag;
    unsigned int maxNumberOfQAGroup;
    std::pair<std::vector<Data*>, QString>  selectGroupe;
public:
    Session();
    ~Session();
    bool createNewGroup(QString name);
    bool addTagToQA(TagHandler* tag);
    int getNumberOfExistingGroup();
    int getNumberOfQuickAccessTag();
    unsigned int getMaxNumberOfQATag();
    unsigned int getMaxNumberOfQAGroup();
    std::pair<std::vector<Data*>, QString> getSelectGroup();
    void setSelectGroup(std::pair<std::vector<Data*>, QString> groupe);
    std::vector< std::pair<std::vector<Data*>, QString> > getGroupes();
    int findGroupByName(const QString &groupName);
    bool add(const QModelIndex &toAdd, int i);
    TagHandler getTagHandler(QString string);
};

#endif // SESSION_HPP
