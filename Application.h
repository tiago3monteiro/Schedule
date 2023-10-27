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

    void printStudentSchedule(std::string name); //Consult the schedule of a given student
    void printClassSchedule(std::string aClass); //Consult the schedule of a given class
    void studentsInClass(std::string aClass); //Consult the students within a given class (also prints for which UCs they are on it)
    void studentsInUC(std::string UC); //Consult the students in a given UC
    void studentsInYear(std::string year); //Consult the students in a given Year

    void consultOcupationOfUCs();//Consult the number of students of a UC
    void consultOcupationOfClassesPerUC(std::string UC, std::string aCLass); //consult the number of students on a class for a UC
  //  void consultOcupationOfClassesPerUC(std::string aClass); //for partial implementation
    //  void consultOcupationOfUC()(std::string UC); for partial implementation

private:
    std::set<Student> students;
    std::set<ScheduleUC> schedules;
    std::set<std::string>existingUCs;
    std::set<std::string>existingClasses;

};


#endif //SCHEDULE_PROJECT_APPLICATION_H
