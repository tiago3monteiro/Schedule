//
// Created by tiagomonteiro on 10/18/23.
//

#include "Application.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

Application::Application() //sort data in the right containers
{
    std::ifstream in("students_classes.csv");  //Parsing of student info
    std::string line;

    std::getline(in, line, '\n');
    while (std::getline(in, line, '\n')) {
        line = line.substr(0, line.length() - 1); //you bastards I spent 1 day trying to figure out this
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> saved;
        while (std::getline(iss, word, ',')) saved.push_back(word);

        ClassForUc classes(saved[3], saved[2]);
        Student student(saved[0], saved[1], {classes});
        auto findStudent = students.find(student);

        if (findStudent != students.end()) //If the student is already in the set:
        {
            auto classesStudent = findStudent->getStudentSchedule();
            students.erase(findStudent);
            for (auto aula: classesStudent) //aula means class in portuguese
            {
                student.addClass(aula);
            }
        }
        students.insert(student);
    }

    std::ifstream in1("classes.csv"); //Parsing of classes info
    std::string line1;
    std::getline(in1, line1, '\n');
    while (std::getline(in1, line1, '\n')) {
        line1 = line1.substr(0, line1.length() - 1);
        std::istringstream iss(line1);
        std::string word;
        std::vector<std::string> saved;
        while (std::getline(iss, word, ',')) saved.push_back(word);

        Block block(saved[2], saved[3], saved[4], saved[5]);
        ClassForUc classes(saved[0], saved[1]);

        ScheduleUC scheduleUc(classes, {block});

        auto findClass = schedules.find(scheduleUc);

        if (findClass != schedules.end()) //If the schedule is already in the set:
        {
            auto classesUcClass = findClass->getUcClassSchedule();
            schedules.erase(findClass);
            for (auto block: classesUcClass) //aula means class in portuguese
            {
                scheduleUc.addBlock(block);
            }
        }
        schedules.insert(scheduleUc);
    }

    std::ifstream in2("classes_per_uc.csv"); //Parsing of classes info
    std::string line2;
    std::getline(in2, line2, '\n');
    while (std::getline(in2, line2, '\n')) {
        line2 = line2.substr(0, line2.length() - 1);
        std::istringstream iss(line2);
        std::string word;
        std::vector<std::string> saved;
        while (std::getline(iss, word, ',')) saved.push_back(word);
        existingUCs.insert(saved[0]);
        existingClasses.insert(saved[1]);

    }
}

void Application::printStudentSchedule(std::string name) { //Kinda complex by now but gives us the schedule of a student
    std::set<Block> res;                                                         //still need to sort the data by date
    for (auto student: students)
        if (student.getName() == name)
            for (auto studentClass: student.getStudentSchedule())
                for (auto ucClasses: schedules)
                    if (studentClass == ucClasses.getClassForUc())
                    {
                        for (auto block : ucClasses.getUcClassSchedule())
                        {
                            res.insert(block);
                        }

                        ucClasses.printSchedule();
                    }
}

void Application::printClassSchedule(std::string aClass)
{                                                           //still need to sort by date
    for(auto classes:schedules)
    {
        if(classes.getClassForUc().getUcClass() == aClass)  classes.printSchedule();
    }
}


void Application::consultStudents(std::string classOrUC){ //prints all the students in a certain UC or class
    std::set<std::string> studentsList;
    for (auto student: students)
        for (auto classes: student.getStudentSchedule())
            if (classes.getUcClass() == classOrUC || classes.getUcCode() == classOrUC) studentsList.insert(student.getName());

    for (auto student: studentsList) std::cout << student << std::endl;
}

void Application::consultOcupationOfUCs() //prints the number of students of each UC
{
    std::map<std::string,int> studentsPerUC;
    for(auto UC:existingUCs) studentsPerUC.try_emplace(UC,0);
    for(auto UC: existingUCs)
        for(auto student:students)
            for(auto schedule: student.getStudentSchedule())
                if(UC == schedule.getUcCode()) studentsPerUC[schedule.getUcCode()] ++;
    for(auto res: studentsPerUC) std::cout<< res.first <<": " <<res.second<<std::endl;
}

void Application::consultOcupationOfClassesPerUC(std::string UC, std::string aCLass) {
    int count = 0;
    ClassForUc key = {aCLass, UC};
    for (auto student: students)
        for (auto schedule: student.getStudentSchedule())
            if (schedule == key) {
                count++;
                std::cout << student.getName() << std::endl;
            }
            std::cout << "UC " << UC << " for class " << aCLass << " has " << count << " students";
}
