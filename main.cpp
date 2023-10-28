#include <iostream>
#include <string>
#include "Application.h"



//just making some tests on how to collect the data


int main() {
    Application application;

    int key;
    while (true) {
        std::cout << "1, Print a schedule:" << std::endl;
        std::cout << "2. Consult the students within:" << std::endl;
        std::cout << "3. Consult ocupation:" << std::endl;
        std::cout << "4. Another statistics:" << std::endl;
        std::cin >> key;
        switch (key) {
            case 1: //Print a Schedule:
            {
                std::cout << "1.Print a Student's Schedule" << std::endl;
                std::cout << "2.Print a Class' Schedule" << std::endl;
                std::cin >> key;
                switch (key) {
                    case 1: {
                        std::cout << "Please insert name of the student: ";
                        std::string name;
                        std::cin >> name;
                        application.printStudentSchedule(name);
                        break;
                    }

                    case 2: {
                        std::cout << "Please insert the class: ";
                        std::string aClass;
                        std::cin >> aClass;
                        application.printClassSchedule(aClass);
                        break;
                    }

                    default:
                        break;

                }
                default:
                    break;

                case 2: //Print Students within a class, a UC or Year
                {
                    std::cout << "1.Class" << std::endl;
                    std::cout << "2.UC" << std::endl;
                    std::cout << "3.Year" << std::endl;
                    std::cin >> key;
                    switch (key) {
                        case 1: {
                            std::cout << "Please insert the class: ";
                            std::string aClass;
                            std::cin >> aClass;
                            application.studentsInClass(aClass);
                            break;
                        }

                        case 2: {
                            std::cout << "Please insert the UC: ";
                            std::string UC;
                            std::cin >> UC;
                            application.studentsInUC(UC);
                            break;
                        }

                        case 3: {
                            std::cout << "Please insert the Year: ";
                            int year;
                            std::cin >> year;
                            application.studentsInYear(year);
                            break;
                        }

                        default:
                            break;
                    }
                }
                case 3: //Consult the class/year/UC occupation (sorting by UC, ascending or descending order, …)
                {
                    std::cout << "1.Class" << std::endl;
                    std::cout << "2.UC" << std::endl;
                    std::cout << "3.Year" << std::endl;
                    std::cin >> key;
                    switch (key) {
                        case 1: {
                            std::cout << "Please insert the class: ";
                            std::string aClass;
                            std::cin >> aClass;
                            //application.consultOcupationOfClassesPerUC(aClass);
                            break;
                        }

                        case 2: {
                            std::string UC;
                            std::cout << "1. Partial" << std::endl;
                            std::cout << "2. Total" << std::endl;
                            std::cin >> key;
                            if(key == 1)
                            {
                                std::cout << "Please insert the UC: ";
                                std::cin >> UC;
                                application.consultOcupationOfUCs(0,UC,1);
                            }
                            else
                            {
                                std::cout << "1. Sort by UC: "<< std::endl;
                                std::cout << "2. Sort in ascending order: " << std::endl;
                                std::cout << "3. Sort in descending order: " << std::endl;
                                int order;
                                std::cin >> order;
                                application.consultOcupationOfUCs(order);

                            }



                            break;
                        }

                        case 3: {
                            std::cout << "Please insert the Year: ";
                            int year;
                            std::cin >> year;
                            application.studentsInYear(year);
                            break;
                        }

                        default:
                            break;
                    }
                }
            }
        }

    }
    return 0;
}
