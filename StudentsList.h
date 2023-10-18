//
// Created by tiagomonteiro on 10/18/23.
//

#ifndef SCHEDULE_PROJECT_STUDENTSLIST_H
#define SCHEDULE_PROJECT_STUDENTSLIST_H


#include <set>
#include "ClassForUc.h"
#include "Student.h"
#include "ScheduleUC.h"

class StudentsList {
public:
    StudentsList();
    const std::set<Student> &getStudents() const;
    const std::set<ScheduleUC> &getSchedules() const;


private:
    std::set<Student> students;
    std::set<ScheduleUC> schedules;


};


#endif //SCHEDULE_PROJECT_STUDENTSLIST_H
