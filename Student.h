//
// Created by tiagomonteiro on 10/10/23.
//

#ifndef SCHEDULE_PROJECT_STUDENT_H
#define SCHEDULE_PROJECT_STUDENT_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "ClassForUc.h"


class Student {
public:
    Student(std::string id, std::string name, std::vector<ClassForUc> studentSchedule);
    bool operator< (const Student& student) const;
    const std::string &getId() const;
    const std::vector<ClassForUc> &getStudentSchedule() const;
    const std::string &getName() const;
    void addClass(ClassForUc theClass);
    void removeClass(ClassForUc theClass);
    void printSchedule();

private:
    std::string name;
    std::string id;
    std::vector<ClassForUc> studentSchedule;

};


#endif //SCHEDULE_PROJECT_STUDENT_H
