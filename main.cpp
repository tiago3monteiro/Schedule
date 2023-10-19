#include <iostream>

#include <string>

#include "Application.h"



//just making some tests on how to collect the data


int main()
{
    Application application;
    std::string name;
    name = "Vasco";


    for(auto student:application.getStudents())
    {
        if(student.getName() == name)
        {
            for(auto aClass: student.getStudentSchedule())
            {

                for(auto UC: application.getSchedules())
                {


                    if(UC.getClassForUc() == aClass ) UC.printSchedule();

                }
            }
        }
    }


    return 0;

}

