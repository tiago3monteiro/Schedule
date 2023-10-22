//
// Created by tiagomonteiro on 10/18/23.
//

#include "Application.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


const std::set<ScheduleUC> &Application::getSchedules() const {
    return schedules;
}
const std::set<Student> &Application::getStudents() const {
    return students;
}

Application::Application()
{
    std::ifstream in("students_classes.csv");  //Parsing of student info
    std::string line;

    std::getline(in, line, '\n');
    while (std::getline(in, line,'\n')) {
        line = line.substr(0,line.length()-1); //you bastards I spent 1 day trying to figure out this
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> saved;
        while(std::getline(iss,word,',')) saved.push_back(word);

        ClassForUc classes(saved[3],saved[2]);
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

    std::ifstream in1("classes.csv"); //Parsing of classes info
    std::string line1;
    std::getline(in1, line1, '\n');
    while (std::getline(in1, line1,'\n')) {
        line1 = line1.substr(0,line1.length()-1);
        std::istringstream iss(line1);
        std::string word;
        std::vector<std::string> saved;
        while(std::getline(iss,word,',')) saved.push_back(word);

        Block block(saved[2],saved[3],saved[4],saved[5]);
        ClassForUc classes(saved[0], saved[1]);

        ScheduleUC scheduleUc(classes, {block});

        auto findClass = schedules.find(scheduleUc);

        if( findClass != schedules.end()) //If the schedule is already in the set:
        {
            auto classesUcClass = findClass->getUcClassSchedule();
            schedules.erase(findClass);
            for(auto block: classesUcClass) //aula means class in portuguese
            {
                scheduleUc.addBlock(block);
            }
        }
        schedules.insert(scheduleUc);
    }
}

void Application::printStudentSchedule(std::string name)  { //Kinda complex by now

    for(auto student: this->students)
    {
        if(student.getName() == name)
        {
            for(auto studentClass: student.getStudentSchedule())
            {
                for(auto ucClasses : this->schedules)
                {
                    if(studentClass == ucClasses.getClassForUc())
                    {
                        ucClasses.printSchedule();

                    }
                }
            }
        }
    }
}