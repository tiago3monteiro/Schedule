//
// Created by tiagomonteiro on 10/18/23.
//

#include "ClassForUc.h"

ClassForUc::ClassForUc(std::string ucCode, std::string ucClass)
{
    this->ucCode = ucCode;
    this->ucClass = ucClass;
}

const std::string &ClassForUc::getUcCode() const {
    return ucCode;
}

const std::string &ClassForUc::getUcClass() const {
    return ucClass;
}

