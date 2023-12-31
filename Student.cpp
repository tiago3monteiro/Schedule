//
// Created by tiagomonteiro on 10/10/23.
//
#include <iostream>
#include <algorithm>
#include "Student.h"

Student::Student()
{
    this->name = "default";
    this->id = "default";


}

bool Student::operator < (const Student& student) const
{
    return this->name < student.name;
}

Student::Student(std::string id, std::string name, std::vector<ClassForUc> studentSchedule) {
    this->name = name;
    this->id = id;
    this->studentSchedule = studentSchedule;

}

const std::vector<ClassForUc> &Student::getStudentSchedule() const {
    return studentSchedule;
}

const std::string &Student::getName() const {
    return name;
}

const std::string &Student::getId() const {
    return id;
}

void Student::addClass(ClassForUc theClass) {
    studentSchedule.push_back(theClass);

}
void Student::printSchedule() const {
    for(auto classes: studentSchedule)
    {
        std::cout << classes.getUcClass() << "->" << classes.getUcCode() << std::endl;
    }

}
