//
// Created by tiagomonteiro on 10/18/23.
//

#ifndef SCHEDULE_PROJECT_APPLICATION_H
#define SCHEDULE_PROJECT_APPLICATION_H


#include <set>
#include "ClassForUc.h"
#include "Student.h"
#include "ScheduleUC.h"

class Application {
public:
    Application();
    const std::set<Student> &getStudents() const;
    const std::set<ScheduleUC> &getSchedules() const;
    void printStudentSchedule(std::string name) ;


private:
    std::set<Student> students;
    std::set<ScheduleUC> schedules;


};


#endif //SCHEDULE_PROJECT_APPLICATION_H
