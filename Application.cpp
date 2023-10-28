//
// Created by tiagomonteiro on 10/18/23.
//

#include "Application.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

        Block block(saved[2], stof(saved[3]), stof(saved[4]), saved[5]);
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
} //................................END OF THE CONSTRUCTOR....................................//

void Application::printStudentSchedule(std::string name) { //Kinda complex by now but gives us the schedule of a student
    std::set<Block> res;
    for (auto student: students)
        if (student.getName() == name)
            for (auto studentClass: student.getStudentSchedule())
                for (auto ucClasses: schedules)
                    if (studentClass == ucClasses.getClassForUc())
                        for (auto block : ucClasses.getUcClassSchedule())
                            res.insert(block);
    for(auto block : res)
    {
        float begin = block.getStartHour();
        float duration = block.getDuration();
        std::cout << block.getDay() << " " << block.getStartHour() << "-" <<begin+duration << " "<< block.getType() <<std::endl;
    }
}

void Application::printClassSchedule(std::string aClass)
{
    std::set<Block> res;
   for(auto schedule: schedules)
       if(schedule.getClassForUc().getUcClass() == aClass)
           for(auto block:schedule.getUcClassSchedule()) res.insert(block);

   for(auto block : res)
   {
       float begin = block.getStartHour();
       float duration = block.getDuration();
       std::cout << block.getDay() << " " << block.getStartHour() << "-" <<begin+duration << " "<< block.getType() <<std::endl;
   }

}
void Application::studentsInClass(std::string aClass){ //prints all the students in a class
    std::set<std::string> studentsList;

    for (auto student:students)
    {
        bool belongs = false;
        std::vector<std::string>UC;
        for(auto schedule: student.getStudentSchedule())
        {
            if(schedule.getUcClass() == aClass)
            {
                belongs = true;
                UC.push_back(schedule.getUcCode());
            }
        }
        if (belongs)
        {
            std::cout << student.getName() << " is on " << aClass << " for ";
            for(auto uc: UC)
            {
                std::cout << uc << " ";
            }
            std::cout<<std::endl;
        }
    }
}
void Application::studentsInUC(std::string UC)
{
    for(auto student:students)
    {
        for(auto schedule:student.getStudentSchedule())
        {
            if(schedule.getUcCode() == UC)
                std::cout << student.getName() <<" is on " << UC << " (" <<  schedule.getUcClass() << ")" << std::endl;
        }
    }
}

void Application::studentsInYear(int year) {
    for (auto student: students) {
        std::vector<std::string> UCs;
        for (auto schedule: student.getStudentSchedule()) {
            std::string studentYear = schedule.getUcClass().substr(0, 1);
            if (stoi(studentYear) == year) {
                UCs.push_back(schedule.getUcCode());
            }
        }
        if (!UCs.empty()) {
            std::cout << student.getName() << " is on " << year;
            if (year == 1) std::cout << "st year";
            else if (year == 2) std::cout << "nd year";
            else if (year == 3) std::cout << "rd year";
            else std::cout << "th year";
            std::cout << " for the following UCs: ";
            for (auto UC: UCs) {
                std::cout << UC << " ";
            }
            std::cout << std::endl;
        }
    }
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
    std::cout << "UC " << UC << " for class " << aCLass << " has " << count << " students" << std::endl;
}


void Application::consultOcupationOfUCs(int order,std::string UC ,int key)  //prints the number of students of each UC
{
    if(!key) //TOTAL
    {
        std::map<std::string,int> studentsPerUC; //DEFAULT IS BY UC
        for(auto UC:existingUCs) studentsPerUC.try_emplace(UC,0);
        for(auto UC: existingUCs)
            for(auto student:students)
                for(auto schedule: student.getStudentSchedule())
                    if(UC == schedule.getUcCode()) studentsPerUC[schedule.getUcCode()] ++;

        std::vector<std::pair<int, std::string>> sortedValues;
        for (const auto &entry : studentsPerUC) {
            sortedValues.emplace_back(entry.second, entry.first);
        }
        if (order == 2) { //ASCENDING
            std::sort(sortedValues.begin(), sortedValues.end());
        } else if (order == 3) { //DESCENDING
            std::sort(sortedValues.rbegin(), sortedValues.rend());
        }
        for (const auto &pair : sortedValues) {
            std::cout << pair.second << ": " << pair.first << std::endl;
        }
    }
    else //PARTIAL
    {
            int count = 0;
            for(auto student:students)
            {
                for(auto schedule: student.getStudentSchedule())
                {
                    if(schedule.getUcCode() == UC) count++;
                }
            }
            std::cout << UC << ": " << count<<std::endl;
    }
}

void Application::consultOcupationOfClasses(int order, std::string aClass, int key) {
    if (!key) {
        std::map<std::string, int> studentsPerClass; // DEFAULT IS BY UC
        for (auto UC : existingClasses) studentsPerClass.try_emplace(UC, 0);

        for (auto student : students) {
            for (auto schedule : student.getStudentSchedule()) {
                if (studentsPerClass.find(schedule.getUcClass()) != studentsPerClass.end()) {
                    studentsPerClass[schedule.getUcClass()]++;
                }
            }
        }
        std::vector<std::pair<int, std::string>> sortedValues;
        for (const auto &entry : studentsPerClass) {
            sortedValues.emplace_back(entry.second, entry.first);
        }

        if (order == 2) { // ASCENDING
            std::sort(sortedValues.begin(), sortedValues.end());
        } else if (order == 3) { // DESCENDING
            std::sort(sortedValues.rbegin(), sortedValues.rend());
        }

        for (const auto &pair : sortedValues) {
            std::cout << pair.second << ": " << pair.first << std::endl;
        }
    } else { // PARTIAL
        int count = 0;
        for (auto student : students) {
            for (auto schedule : student.getStudentSchedule()) {
                if (schedule.getUcClass() == aClass) {
                    count++;
                }
            }
        }
        std::cout << aClass << ": " << count << std::endl;
    }
}

void Application::consultOcupationofYear(int order, std::string year ,int key)
{
    if (!key) {
        std::map<std::string, int> studentsPerYear {{"1", 0}, {"2", 0}, {"3", 0}}; // Initialize with zero for years 1, 2, and 3

        for (auto student : students) {
            std::set<std::string> attendedYears; // Using a set to keep track of attended years for a student

            for (auto schedule : student.getStudentSchedule()) {
                std::string studentYear = schedule.getUcClass().substr(0, 1);
                attendedYears.insert(studentYear); // Collect attended years for a student
            }
            for ( auto attendedYear : attendedYears) {
                studentsPerYear[attendedYear]++; // Increment the count for each attended year
            }
        }

        std::vector<std::pair<int, std::string>> sortedValues;
        for (const auto &entry : studentsPerYear) {
            sortedValues.emplace_back(entry.second, entry.first);
        }

        if (order == 2) { // ASCENDING
            std::sort(sortedValues.begin(), sortedValues.end());
        } else if (order == 3) { // DESCENDING
            std::sort(sortedValues.rbegin(), sortedValues.rend());
        }

        for (const auto &pair : sortedValues) {
            std::cout << pair.second << ": " << pair.first << std::endl;
        }
    }


    else //Partial
    {
        int count = 0;
        for(auto student:students)
        {
            for(auto schedule:student.getStudentSchedule())
            {
                auto studentYear = schedule.getUcClass().substr(0,1);
                if(studentYear == year)
                {
                    count++;
                    break;
                }
            }

        }
        std::cout << year << ": " << count << std::endl;
    }
}
