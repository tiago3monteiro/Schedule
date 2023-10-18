//
// Created by tiagomonteiro on 10/18/23.
//

#ifndef SCHEDULE_PROJECT_STUDENTSLIST_H
#define SCHEDULE_PROJECT_STUDENTSLIST_H


#include <set>
#include "ClassForUc.h"
#include "Student.h"

class StudentsList {
public:
    StudentsList();


private:
    std::set<Student> students;
public:
    const std::set<Student> &getStudents() const;


};


#endif //SCHEDULE_PROJECT_STUDENTSLIST_H
