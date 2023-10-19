#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Student.h"
#include "StudentsList.h"



//just making some tests on how to collect the data


int main()
{

    StudentsList application;
    std::cout << "Student: ";
    std::string name;
    std::cin >>  name;
    std::cin.ignore(10);
    std::cin.clear();
    for(auto student: application.getStudents())
    {
        if (student.getName() == name)
        {
            student.printSchedule();
            auto schedules = application.getSchedules();
            std::cout << "Schedule aluno ";
            std::cout<< student.getStudentSchedule()[0].getUcClass() << " "<< student.getStudentSchedule()[0].getUcCode()<< std::endl ;
            for(auto schedule: schedules)
            {
                if(schedule.getClassForUc()== student.getStudentSchedule()[0])
                {
                    std::cout << "if";
                    schedule.printSchedule();
                }
            }

        }


    }











    return 0;

}

