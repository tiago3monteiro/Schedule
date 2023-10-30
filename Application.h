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
    std::set<Block> printStudentSchedule(std::string name, int key = 0); //Consult the schedule of a given student if key = 0 it prints if key = 1 just return the values
    std::set<Block> printClassSchedule(std::string aClass, int key = 0); //Consult the schedule of a given class if key = 0 it prits if key = 1 just return the values
    std::set<Block> printClassForUCSchedule(ClassForUc classforuc, int key = 0); //Consult the schedule of a given class if key = 0 it prits if key = 1 just return the values

    void studentsInClass(std::string aClass); //Consult the students within a given class (also prints for which UCs they are on it)
    void studentsInUC(std::string UC); //Consult the students in a given UC
    void studentsInYear(std::string year); //Consult the students in a given Year
    int consultOcupationOfClassesPerUC(std::string UC, std::string aCLass,int key = 0); //consult the number of students on a class for a UC

    void consultOcupationOfClasses(int order, std::string aClass = "default",int key=0); //Consult the number of students of a class, also sorts it
    void consultOcupationOfUCs(int order, std::string UC = "default",int key=0);  //Consult the number of students of a UC, also sorts it
    void consultOcupationofYear(int order, std::string = "default",int key=0);  //Consult the number of students of a year , also sorts it

    void consultStudentDetails(std::string info); //Consult basic details about the student
    void moreThanN(int n); // Consult the number of students registered in at least n UCs;

    bool addUC(std::string name, std::string UC,std::string aClass ="default", int key =2); //Adds a UC from a student schedule
    bool removeUC(std::string name, std::string UC); //Removes a UC from a student schedule


private:
    std::set<Student> students;
    std::set<ScheduleUC> schedules;
    std::set<std::string>existingUCs;
    std::set<std::string>existingClasses;
    const static int CAP = 30;

};


#endif //SCHEDULE_PROJECT_APPLICATION_H
