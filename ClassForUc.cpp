//
// Created by tiagomonteiro on 10/18/23.
//

#include "ClassForUc.h"

ClassForUc::ClassForUc(std::string ucClass , std::string ucCode)
{
    this->ucClass = ucClass;
    this->ucCode = ucCode;
}

const std::string &ClassForUc::getUcCode() const {
    return ucCode;
}

const std::string &ClassForUc::getUcClass() const {
    return ucClass;
}

ClassForUc::ClassForUc() {
    this->ucCode = "default";
    this->ucClass = "default";
}

bool ClassForUc::operator < (ClassForUc obj) const
{
    if(this->getUcCode() < obj.getUcCode()) return true;
    else if(this->getUcCode() > obj.getUcCode()) return false;
    return this->ucClass < obj.getUcClass();

}