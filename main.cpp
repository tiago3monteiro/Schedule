#include <iostream>
#include <string>
#include "Application.h"



//just making some tests on how to collect the data


int main()
{
    Application application;
    std::string name = "Vasco";
    std::string UC = "L.EIC005";
    std::string aClass = "1LEIC02";
    //application.printStudentSchedule(name);
    application.consultStudents(aClass);




    return 0;

}

