#include <iostream>
#include <string>
#include "Application.h"



//just making some tests on how to collect the data


int main()
{
    Application application;
    int key;
    while(true)
    {
        std::cout<< "1, Print a Schedule" << std::endl;
        std::cout<< "2. Print Ocupation" << std::endl;
        std::cin >> key;
        switch(key)
        {
            case 1: //Print a Schedule:
            {
                std::cout<< "1.Print a Student's Schedule" << std::endl;
                std::cout<<"2.Print a Class' Schedule" <<std::endl;
                std::cin >> key;
                switch(key)
                {
                    case 1:
                    {
                        std::cout << "Please insert name of the student: ";
                        std::string name;
                        std::cin >> name;
                        application.printStudentSchedule(name);
                        break;
                    }

                    case 2:
                    {
                        std::cout << "Please insert the class : ";
                        std::string aClass;
                        std::cin >> aClass;
                        application.printClassSchedule(aClass);
                        break;
                    }

                    default:
                        break;

                }
                default: break;
            }
            case 2:
            {
                std::cout<< "1.Print Student that belong to a Class"<< std::endl;
                std::cout<<"2.Print a Class' Schedule" <<std::endl;


            }



        }
    }




    return 0;

}

