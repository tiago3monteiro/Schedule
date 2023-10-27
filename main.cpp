#include <iostream>
#include <string>
#include "Application.h"



//just making some tests on how to collect the data


int main() {
    Application application;

    int key;
    while (true) {
        std::cout << "1, Print a Schedule" << std::endl;
        std::cout << "2. Consult the students within:" << std::endl;
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
                            std::string year;
                            std::cin >> year;
                            application.studentsInUC(UC);
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
