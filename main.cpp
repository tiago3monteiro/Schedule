#include <iostream>
#include <string>
#include "Application.h"



//just making some tests on how to collect the data


int main()
{
    Application application;
    std::string name = "Vasco";
    std::string UC = "L.EIC005";
    std::string aClass = "1LEIC08";
    application.printClassSchedule(aClass);
    //application.consultStudents(aClass);
    //application.consultStudents(aClass);
    //application.consultOcupationOfUCs();
    //application.consultOcupationOfClassesPerUC(UC,aClass);


    return 0;

}

