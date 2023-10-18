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
    friend std::ostream& operator<<(std::ostream& os, const ClassForUc& obj) {
        os << obj.getUcCode() << std::string("->") << obj.getUcClass();
        return os;
    }



private:
    std::string ucCode;
    std::string ucClass;

};





#endif //SCHEDULE_PROJECT_CLASSFORUC_H
