//
// Created by tiagomonteiro on 10/10/23.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"
using namespace std;


bool Student::operator < (const Student& student) const
{
    return this->name < student.name;

}

Student::Student(std::string id, std::string name, std::vector<ClassForUc> studentSchedule) {
    this->name = name;
    this->id = id;
    this->studentSchedule = studentSchedule;

}

const vector<ClassForUc> &Student::getStudentSchedule() const {
    return studentSchedule;
}

const string &Student::getName() const {
    return name;
}

const string &Student::getId() const {
    return id;
}

void Student::addClass(ClassForUc theClass) {
    studentSchedule.push_back(theClass);

}
