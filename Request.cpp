//
// Created by tiagomonteiro on 10/31/23.
//

#include "Request.h"

Request::Request(int type, std::string name, std::string UC, std::string aClass, int key, int undo )
{
    this->type = type;
    this->UC = UC;
    this->aClass = aClass;
    this->name = name;
    this->key = key;
    this->undo = undo;
}

int Request::getType() const {
    return type;
}

const std::string &Request::getUc() const {
    return UC;
}

const std::string &Request::getAClass() const {
    return aClass;
}

const std::string &Request::getName() const {
    return name;
}

int Request::getKey() const {
    return key;
}

int Request::getUndo() const {
    return undo;
}

