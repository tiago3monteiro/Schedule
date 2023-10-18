//
// Created by tiagomonteiro on 10/18/23.
//

#include "StudentsList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


const std::set<ScheduleUC> &StudentsList::getSchedules() const {
    return schedules;
}
const std::set<Student> &StudentsList::getStudents() const {
    return students;
}

StudentsList::StudentsList()
{
    std::ifstream in("students_classes.csv");
    std::string line;

    while (std::getline(in, line)) {

        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> saved;
        while(std::getline(iss,word,',')) saved.push_back(word);

        ClassForUc classes(saved[2],saved[3]);
        Student student(saved[0], saved[1], {classes});
        auto findStudent = students.find(student);

        if( findStudent != students.end()) //If the student is already in the set:
        {
            auto classesStudent = findStudent->getStudentSchedule();
            students.erase(findStudent);
            for(auto aula: classesStudent) //aula means class in portuguese
            {
                student.addClass(aula);

            }
        }
        students.insert(student);
    }

    std::ifstream in1("classes.csv");
    std::string line1;

    while (std::getline(in1, line1)) {

        std::istringstream iss(line1);
        std::string word;
        std::vector<std::string> saved;
        while(std::getline(iss,word,',')) saved.push_back(word);

        Block block(saved[2],saved[3],saved[4],saved[5]);
        ClassForUc classes(saved[0], saved[1]);
        ScheduleUC scheduleUc(classes, {block});

        auto findClass = schedules.find(scheduleUc);

        if( findClass != schedules.end()) //If the student is already in the set:
        {
            auto classesStudent = findClass->getUcClassSchedule();
            schedules.erase(findClass);
            for(auto block: classesStudent) //aula means class in portuguese
            {
                scheduleUc.addBlock(block);

            }
        }
        schedules.insert(scheduleUc);
    }

}
