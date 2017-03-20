#include "session.hpp"

Session::Session(){
    this->maxNumberOfQATag = 10;
    this->maxNumberOfQAGroup = 10;
}

Session::~Session(){
    this->groupes.clear();
    this->quickAccessTag.clear();
}

bool Session::createNewGroup(QString name){
    std::pair<std::vector<Data*>, QString> newGroup;
    newGroup = std::make_pair(std::vector<Data*>(), name);
    bool isAdd;
    if(this->groupes.size() < this->maxNumberOfQAGroup){
        if(std::find(this->groupes.begin(), this->groupes.end(), newGroup) != this->groupes.end()) {
            std::cout << "A groupe with this name already exist " << std::endl;
            isAdd = false;
        }else{
            this->groupes.push_back(newGroup);
            isAdd = true;
        }
    }else{
        isAdd = false;
    }
    return isAdd;
}

bool Session::addTagToQA(TagHandler* tag){
    bool isAdd;
    if(this->quickAccessTag.size() < this->maxNumberOfQATag){
        if(std::find(this->quickAccessTag.begin(), this->quickAccessTag.end(), tag) != this->quickAccessTag.end()) {
            std::cout << "A groupe with this name already exist " << std::endl;
            isAdd = false;
        }else{
            this->quickAccessTag.push_back(tag);
            this->tags.push_back(tag);
            isAdd = true;
        }
    }else{
        isAdd = false;
    }
    return isAdd;
}


int Session::getNumberOfExistingGroup(){
    return this->groupes.size();
}

int Session::getNumberOfQuickAccessTag(){
    return this->quickAccessTag.size();
}

unsigned int Session::getMaxNumberOfQAGroup(){
    return this->maxNumberOfQAGroup;
}

unsigned int Session::getMaxNumberOfQATag(){
    return this->maxNumberOfQATag;
}


std::pair<std::vector<Data*>, QString> Session::getSelectGroup(){
    return this->selectGroupe;
}

void Session::setSelectGroup(std::pair<std::vector<Data*>, QString> groupe){
    if(std::find(this->groupes.begin(), this->groupes.end(), groupe) != this->groupes.end()) {
        this->selectGroupe = groupe;
    }
}


std::vector< std::pair<std::vector<Data*>, QString> > Session::getGroupes(){
    return this->groupes;
}

int Session::findGroupByName(QString* &groupName){
    bool find;
    int i;
    i = 0;
    find = false;
    while(!find && i < this->groupes.size()){
        if(this->groupes.at(i).second == groupName){
            find = true;
        }else{
            i = i + 1;
        }
    }
    return i;
}

bool Session::add(const QModelIndex &toAdd, int i){

}
