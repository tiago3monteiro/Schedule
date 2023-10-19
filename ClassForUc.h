//
// Created by tiagomonteiro on 10/18/23.
//

#ifndef SCHEDULE_PROJECT_CLASSFORUC_H
#define SCHEDULE_PROJECT_CLASSFORUC_H


#include <string>
#include <list>
#include "Block.h"

class ClassForUc {
public:

    ClassForUc(std::string ucCode, std::string ucClass);
    const std::string &getUcCode() const;
    const std::string &getUcClass() const;
    bool operator == (ClassForUc obj) const { return this->getUcClass() == obj.getUcClass() && this->getUcCode() == obj.getUcCode();}

private:
    std::string ucCode;
    std::string ucClass;

};





#endif //SCHEDULE_PROJECT_CLASSFORUC_H
