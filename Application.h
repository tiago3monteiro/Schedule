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

    void printStudentSchedule(std::string name);
    void consultStudents(std::string classOrUC);
  //  void consultOcupationOfUC()(std::string UC); for partial implementation
    void consultOcupationOfUCs();
    void consultOcupationOfClassesPerUC();
    void consultOcupationOfClassesPerUC(std::string aClass); //for partial implementation

private:
    std::set<Student> students;
    std::set<ScheduleUC> schedules;
    std::set<std::string>existingUCs;
    std::set<std::string>existingClasses;

};


#endif //SCHEDULE_PROJECT_APPLICATION_H
