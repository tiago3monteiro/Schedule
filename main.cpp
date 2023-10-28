#include <iostream>
#include <string>
#include "Application.h"



//just making some tests on how to collect the data


int main() {
    Application application;

    int key;
    while (true) {
        std::cout << "¡...................................¡" << std::endl;
        std::cout << "|1.Print a schedule:                |" << std::endl;
        std::cout << "|2.Consult the students within:     |" << std::endl;
        std::cout << "|3.Consult ocupation:               |" << std::endl;
        std::cout << "|4.Another statistics:              |" << std::endl;
        std::cout << "!...................................!" << std::endl;
        std::cin >> key;
        //..................................................................................//
        switch (key)
        {
            case 1: //Print a Schedule:
            {
                std::cout << "¡....................................¡" << std::endl;
                std::cout << "|1.Print a Student's Schedule        |" << std::endl;
                std::cout << "|2.Print a Class' Schedule           |" << std::endl;
                std::cout << "¡....................................¡" << std::endl;
                std::cin >> key;
                switch (key) {
                    case 1: {
                        std::cout << "¡......................................¡" << std::endl;
                        std::cout << "|  Please insert name of the student:  |"<< std::endl;
                        std::cout << "¡......................................¡" << std::endl;
                        std::string name;
                        std::cin >> name;
                        application.printStudentSchedule(name);
                        break;
                    }

                    case 2: {
                        std::cout << "¡....................................¡" << std::endl;
                        std::cout << "|     Please insert the class:       |" << std::endl;
                        std::cout << "¡....................................¡" << std::endl;
                        std::string aClass;
                        std::cin >> aClass;
                        application.printClassSchedule(aClass);
                        break;
                    }

                    default:
                    {
                        std::cout << "¡....................................¡" << std::endl;
                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                        std::cout << "!....................................!" << std::endl;
                        break;
                    }


                }
                break;
            }
        //......................................................................//
            case 2: //Print Students within a class, a UC or Year
            {
                std::cout << "¡.................. ¡" << std::endl;
                std::cout << "|1.Class            |" << std::endl;
                std::cout << "|2.UC               |" << std::endl;
                std::cout << "|3.Year             |" << std::endl;
                std::cout << "|4.UC and Class     |" << std::endl;
                std::cout << "¡...................¡" << std::endl;
                std::cin >> key;
                switch (key) {
                    case 1: {
                        std::cout << "¡.......................... ¡" << std::endl;
                        std::cout << "| Please insert the class:  |" << std::endl;
                        std::cout << "¡...........................¡" << std::endl;
                        std::string aClass;
                        std::cin >> aClass;
                        application.studentsInClass(aClass);
                        break;
                    }

                    case 2: {
                        std::cout << "¡.......................... ¡" << std::endl;
                        std::cout << "|  Please insert the UC:    |" << std::endl;
                        std::cout << "¡...........................¡" << std::endl;
                        std::string UC;
                        std::cin >> UC;
                        application.studentsInUC(UC);
                        break;
                    }

                    case 3: {
                        std::cout << "¡.......................... ¡" << std::endl;
                        std::cout << "| Please insert the year:   |" << std::endl;
                        std::cout << "¡...........................¡" << std::endl;
                        int year;
                        std::cin >> year;
                        application.studentsInYear(year);
                        break;
                    }
                    case 4: {
                        std::cout << "¡.......................... ¡" << std::endl;
                        std::cout << "| Please insert the UC:     |" << std::endl;
                        std::cout << "¡...........................¡" << std::endl;
                        std::string UC;
                        std::cin >> UC;
                        std::cout << "¡.......................... ¡" << std::endl;
                        std::cout << "| Please insert the class:  |" << std::endl;
                        std::cout << "¡...........................¡" << std::endl;
                        std::string aClass;
                        std::cin >> aClass;
                        application.consultOcupationOfClassesPerUC(UC, aClass);
                        break;

                    }

                    default:
                        std::cout << "¡....................................¡" << std::endl;
                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                        std::cout << "!....................................!" << std::endl;
                        break;
                }
                break;
            } //........................................................//
            case 3: //Consult the class/year/UC occupation (sorting by UC, ascending or descending order, …)
            {
                std::cout << "¡...........................¡" << std::endl;
                std::cout << "|1.Class                    |" << std::endl;
                std::cout << "|2.UC                       |" << std::endl;
                std::cout << "|3.Year                     |" << std::endl;
                std::cout << "¡.......................... ¡" << std::endl;
                std::cin >> key;
                switch (key) {
                    case 1: {
                        std::string aClass;
                        std::cout << "¡........... ¡" << std::endl;
                        std::cout << "|1.Partial   |" << std::endl;
                        std::cout << "|2.Total     |" << std::endl;
                        std::cout << "¡............¡" << std::endl;
                        std::cin >> key;
                        if (key == 1) {
                            std::cout << "¡.......................... ¡" << std::endl;
                            std::cout << "| Please insert the class:  |" << std::endl;
                            std::cout << "¡...........................¡" << std::endl;
                            std::cin >> aClass;
                            application.consultOcupationOfClasses(0, aClass, 1);
                        } else {
                            std::cout << "¡...............................¡" << std::endl;
                            std::cout << "|1. Sort by class               |" << std::endl;
                            std::cout << "|2. Sort in ascending order:    |" << std::endl;
                            std::cout << "|3. Sort in descending order:   |" << std::endl;
                            std::cout << "¡...............................¡" << std::endl;
                            int order;
                            std::cin >> order;
                            application.consultOcupationOfClasses(order);

                        }
                        std::cout << "¡....................................¡" << std::endl;
                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                        std::cout << "!....................................!" << std::endl;
                        break;
                    }

                    case 2: {
                        std::string UC;
                        std::cout << "¡........... ¡" << std::endl;
                        std::cout << "|1.Partial   |" << std::endl;
                        std::cout << "|2.Total     |" << std::endl;
                        std::cout << "¡............¡" << std::endl;
                        std::cin >> key;
                        if (key == 1) {
                            std::cout << "¡.......................... ¡" << std::endl;
                            std::cout << "| Please insert the UC:     |" << std::endl;
                            std::cout << "¡...........................¡" << std::endl;
                            std::cin >> UC;
                            application.consultOcupationOfUCs(0, UC, 1);
                        } else {
                            std::cout << "¡...............................¡" << std::endl;
                            std::cout << "|1. Sort by UC:                 |" << std::endl;
                            std::cout << "|2. Sort in ascending order:    |" << std::endl;
                            std::cout << "|3. Sort in descending order:   |" << std::endl;
                            std::cout << "¡...............................¡" << std::endl;
                            int order;
                            std::cin >> order;
                            application.consultOcupationOfUCs(order);
                        }
                        std::cout << "¡....................................¡" << std::endl;
                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                        std::cout << "!....................................!" << std::endl;
                        break;
                    }

                    case 3: {
                        std::string year;
                        std::cout << "¡........... ¡" << std::endl;
                        std::cout << "|1.Partial   |" << std::endl;
                        std::cout << "|2.Total     |" << std::endl;
                        std::cout << "¡............¡" << std::endl;
                        std::cin >> key;
                        if (key == 1) {
                            std::cout << "¡.......................... ¡" << std::endl;
                            std::cout << "| Please insert the year:   |" << std::endl;
                            std::cout << "¡...........................¡" << std::endl;
                            std::cin >> year;
                            application.consultOcupationofYear(0, year, 1);
                        } else {
                            std::cout << "¡...............................¡" << std::endl;
                            std::cout << "|1. Sort by year:               |" << std::endl;
                            std::cout << "|2. Sort in ascending order:    |" << std::endl;
                            std::cout << "|3. Sort in descending order:   |" << std::endl;
                            std::cout << "¡...............................¡" << std::endl;
                            int order;
                            std::cin >> order;
                            application.consultOcupationofYear(order);
                        }
                        std::cout << "¡....................................¡" << std::endl;
                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                        std::cout << "!....................................!" << std::endl;
                        break;
                    }
                    default: break;
                }
                break;
            }//.............................................................................................//
            case 4:
            {
                std::cout << "¡....................................¡" << std::endl;
                std::cout << "|1.Print a Student's Schedule        |" << std::endl;
                std::cout << "|2.Print a Class' Schedule           |" << std::endl;
                std::cout << "¡....................................¡" << std::endl;
                std::cin >> key;



            }
        }
    }
    return 0;
}
