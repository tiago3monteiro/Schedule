#include <iostream>
#include <string>
#include <limits>
#include "Application.h"





//just making some tests on how to collect the data


int main() {

    Application application;
    int key = -1;
    while (key)
    {
        std::cout << "¡.......................................¡" << std::endl;
        std::cout << "|1.Print a schedule:                    |" << std::endl;
        std::cout << "|2.Consult the students that belong to: |" << std::endl;
        std::cout << "|3.Consult occupation by:               |" << std::endl;
        std::cout << "|4.Another statistics:                  |" << std::endl;
        std::cout << "|5.Requests:                            |" << std::endl;
        std::cout << "|0.Leave                                |" << std::endl;
        std::cout << "!.......................................!" << std::endl;
        std::cin >> key;
        //..................................................................................//
            switch (key)
            {


                case 1: //Print a Schedule:
                {
                    int key1 = -1;
                    while(key1)
                    {
                        std::cout << "¡...........................................¡" << std::endl;
                        std::cout << "|1.Print a Student's Schedule               |" << std::endl;
                        std::cout << "|2.Print a Class' Schedule                  |" << std::endl;
                        std::cout << "|3.Print a class for a UC' Schedule         |" << std::endl;
                        std::cout << "|0.Leave                                    |" << std::endl;
                        std::cout << "¡...........................................¡" << std::endl;
                        std::cin >> key1;
                        switch (key1)
                        {
                            case 1: {
                                std::cout << "¡......................................¡" << std::endl;
                                std::cout << "|  Please insert name of the student:  |" << std::endl;
                                std::cout << "¡......................................¡" << std::endl;
                                std::string name;
                                std::cin >> name;
                                if(application.ValidData(name)) application.printStudentSchedule(name);
                                break;
                            }

                            case 2: {
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "|     Please insert the class:       |" << std::endl;
                                std::cout << "¡....................................¡" << std::endl;
                                std::string aClass;
                                std::cin >> aClass;
                                if(application.ValidData("default","default",aClass)) application.printClassSchedule(aClass);
                                break;
                            }

                            case 3: {
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "|     Please insert the UC:          |" << std::endl;
                                std::cout << "¡....................................¡" << std::endl;
                                std::string UC;
                                std::cin >> UC;
                                if(!application.ValidData("default",UC,"default")) break;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "|     Please insert the class:       |" << std::endl;
                                std::cout << "¡....................................¡" << std::endl;
                                std::string aClass;
                                std::cin >> aClass;
                                if(application.ValidData("default",UC,aClass)) application.printClassForUCSchedule({aClass,UC});
                                break;
                            }

                            case 0: break;

                            default:
                                std::cout << "¡..........................¡" << std::endl;
                                std::cout << "| CHOOSE A VALID KEY!      |" << std::endl;
                                std::cout << "¡..........................¡" << std::endl;
                                break;
                        }
                    }
                    break;
                }
                    //......................................................................//
                case 2: //Print Students within a class, a UC or Year
                {
                    int key2 = -1;
                    while(key2)
                    {
                        std::cout << "¡..............................................¡" << std::endl;
                        std::cout << "|1.Class                                       |" << std::endl;
                        std::cout << "|2.UC                                          |" << std::endl;
                        std::cout << "|3.Year                                        |" << std::endl;
                        std::cout << "|4.UC and Class                                |" << std::endl;
                        std::cout << "|0.Leave                                       |" << std::endl;
                        std::cout << "¡..............................................¡" << std::endl;
                        std::cin >> key2;
                        switch (key2) {
                            case 1: {
                                std::cout << "¡.......................... ¡" << std::endl;
                                std::cout << "| Please insert the class:  |" << std::endl;
                                std::cout << "¡...........................¡" << std::endl;
                                std::string aClass;
                                std::cin >> aClass;
                                if(application.ValidData("default","default",aClass)) application.studentsInClass(aClass);
                                break;
                            }

                            case 2: {
                                std::cout << "¡.......................... ¡" << std::endl;
                                std::cout << "|  Please insert the UC:    |" << std::endl;
                                std::cout << "¡...........................¡" << std::endl;
                                std::string UC;
                                std::cin >> UC;
                                if(application.ValidData("default",UC,"default")) application.studentsInUC(UC);
                                break;
                            }

                            case 3: {
                                std::cout << "¡.......................... ¡" << std::endl;
                                std::cout << "| Please insert the year:   |" << std::endl;
                                std::cout << "¡...........................¡" << std::endl;
                                std::string year;
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
                                if(!application.ValidData("default",UC,"default")) break;
                                std::cout << "¡.......................... ¡" << std::endl;
                                std::cout << "| Please insert the class:  |" << std::endl;
                                std::cout << "¡...........................¡" << std::endl;
                                std::string aClass;
                                std::cin >> aClass;
                                if(application.ValidData("default",UC,aClass)) application.studentsInClassForUC(UC, aClass);
                                break;
                            }

                            case 0: break;
                            default:
                            {
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "|     Please insert a valid key!     |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                break;
                            }
                        }

                    }

                    break;
                }
                    //.....................................................................................................................//
                case 3: //Consult the class/year/UC occupation (sorting by UC, ascending or descending order, …)
                {
                    int key3 = -1;
                    while(key3)
                    {
                        std::cout << "¡..............................................¡" << std::endl;
                        std::cout << "|1.Class                                       |" << std::endl;
                        std::cout << "|2.UC                                          |" << std::endl;
                        std::cout << "|3.Year                                        |" << std::endl;
                        std::cout << "|4.UC and Class                                |" << std::endl; //to implement DONT FORGETTTTTTTTTT
                        std::cout << "|0.Leave                                       |" << std::endl;
                        std::cout << "¡..............................................¡" << std::endl;
                        std::cin >> key3;
                        switch (key3)
                        {
                            case 1:
                            {
                                int key4 = -1;
                                while(key4)
                                {
                                    std::string aClass;
                                    std::cout << "¡........... ¡" << std::endl;
                                    std::cout << "|1.Partial   |" << std::endl;
                                    std::cout << "|2.Total     |" << std::endl;
                                    std::cout << "|0.Leave     |" << std::endl;
                                    std::cout << "¡............¡" << std::endl;
                                    std::cin >> key4;

                                    if (key4 == 1) {
                                        std::cout << "¡.......................... ¡" << std::endl;
                                        std::cout << "| Please insert the class:  |" << std::endl;
                                        std::cout << "¡...........................¡" << std::endl;
                                        std::cin >> aClass;
                                        if(application.ValidData("default","default",aClass)) application.consultOcupationOfClasses(0, aClass, 1);
                                        break;
                                    }

                                    else if(key4 == 2)
                                    {
                                        std::cout << "¡...............................¡" << std::endl;
                                        std::cout << "|1. Sort by class               |" << std::endl;
                                        std::cout << "|2. Sort in ascending order:    |" << std::endl;
                                        std::cout << "|3. Sort in descending order:   |" << std::endl;
                                        std::cout << "¡...............................¡" << std::endl;
                                        int order;
                                        std::cin >> order;
                                        application.consultOcupationOfClasses(order);
                                        break;
                                    }
                                    else if(key4 == 0) break;
                                    else
                                    {
                                        std::cout << "¡....................................¡" << std::endl;
                                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                                        std::cout << "!....................................!" << std::endl;

                                    }
                                }

                                break;
                            }

                            case 2:
                            {
                                int key5 = -1;
                                while(key5)
                                {
                                    std::string UC;
                                    std::cout << "¡........... ¡" << std::endl;
                                    std::cout << "|1.Partial   |" << std::endl;
                                    std::cout << "|2.Total     |" << std::endl;
                                    std::cout << "|0.Leave     |" << std::endl;
                                    std::cout << "¡............¡" << std::endl;
                                    std::cin >> key5;


                                    if (key5 == 1)
                                    {
                                        std::cout << "¡.......................... ¡" << std::endl;
                                        std::cout << "| Please insert the UC:     |" << std::endl;
                                        std::cout << "¡...........................¡" << std::endl;
                                        std::cin >> UC;
                                        if(application.ValidData("default",UC,"default"))application.consultOcupationOfUCs(0, UC, 1);
                                        break;
                                    }

                                    else if(key5 == 2)
                                    {
                                        std::cout << "¡...............................¡" << std::endl;
                                        std::cout << "|1. Sort by UC:                 |" << std::endl;
                                        std::cout << "|2. Sort in ascending order:    |" << std::endl;
                                        std::cout << "|3. Sort in descending order:   |" << std::endl;
                                        std::cout << "¡...............................¡" << std::endl;
                                        int order;
                                        std::cin >> order;
                                        application.consultOcupationOfUCs(order);
                                        break;
                                    }
                                    else if(key5 == 0) break;

                                    else
                                    {
                                        std::cout << "¡....................................¡" << std::endl;
                                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                                        std::cout << "!....................................!" << std::endl;
                                    }
                                }

                                break;
                            }

                            case 3:
                            {
                                int key6 = -1;
                                while(key6)
                                {
                                    std::string year;
                                    std::cout << "¡........... ¡" << std::endl;
                                    std::cout << "|1.Partial   |" << std::endl;
                                    std::cout << "|2.Total     |" << std::endl;
                                    std::cout << "|0.Leave     |" << std::endl;
                                    std::cout << "¡............¡" << std::endl;
                                    std::cin >> key6;
                                    if (key6 == 1)
                                    {
                                        std::cout << "¡.......................... ¡" << std::endl;
                                        std::cout << "| Please insert the year:   |" << std::endl;
                                        std::cout << "¡...........................¡" << std::endl;
                                        std::cin >> year;
                                        application.consultOcupationofYear(0, year, 1);
                                        break;
                                    }
                                    else if(key6 == 2)
                                    {
                                        std::cout << "¡...............................¡" << std::endl;
                                        std::cout << "|1. Sort by year:               |" << std::endl;
                                        std::cout << "|2. Sort in ascending order:    |" << std::endl;
                                        std::cout << "|3. Sort in descending order:   |" << std::endl;
                                        std::cout << "¡...............................¡" << std::endl;
                                        int order;
                                        std::cin >> order;
                                        application.consultOcupationofYear(order);
                                        break;
                                    }
                                    else if(key6 == 0) break;
                                    else
                                    {
                                        std::cout << "¡....................................¡" << std::endl;
                                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                                        std::cout << "!....................................!" << std::endl;
                                    }
                                }
                                break;
                            }
                            case 4:
                            {
                                int key11 = -1;
                                while(key11)
                                {
                                    std::string year;
                                    std::cout << "¡........... ¡" << std::endl;
                                    std::cout << "|1.Partial   |" << std::endl;
                                    std::cout << "|2.Total     |" << std::endl;
                                    std::cout << "|0.Leave     |" << std::endl;
                                    std::cout << "¡............¡" << std::endl;
                                    std::cin >> key11; //key1
                                    switch(key11)
                                    {
                                        case 1:
                                        {
                                            int key12 = -1;
                                            while(key12)
                                            {
                                                std::cout << "¡.......................¡" << std::endl;
                                                std::cout << "|1. FIXED UC            |" << std::endl;
                                                std::cout << "|1. FIXED Class         |" << std::endl;
                                                std::cout << "|3. Specific Class+UC   |" << std::endl;
                                                std::cout << "|0. Leave               |" << std::endl;
                                                std::cout << "¡.......................¡" << std::endl;
                                                std::cin>>key12; //key2
                                                switch(key12)
                                                {
                                                    case 1:
                                                    {
                                                        std::string UC;
                                                        std::cout << "¡.......................... ¡" << std::endl;
                                                        std::cout << "| Please insert the UC:     |" << std::endl;
                                                        std::cout << "¡...........................¡" << std::endl;
                                                        std::cin >> UC;
                                                        if(application.ValidData("default",UC,"default"))
                                                        {
                                                            std::cout << "¡...............................¡" << std::endl;
                                                            std::cout << "|1. Sort by class:              |" << std::endl;
                                                            std::cout << "|2. Sort in ascending order:    |" << std::endl;
                                                            std::cout << "|3. Sort in descending order:   |" << std::endl;
                                                            std::cout << "¡...............................¡" << std::endl;
                                                            int order;
                                                            std::cin >> order;
                                                            application.consultOCupationofClassForUc(UC,"default",1,1,order);
                                                            key11 = 0;
                                                        }
                                                        break;

                                                    }

                                                    case 2:
                                                    {
                                                        std::string aClass;
                                                        std::cout << "¡.......................... ¡" << std::endl;
                                                        std::cout << "| Please insert the class:  |" << std::endl;
                                                        std::cout << "¡...........................¡" << std::endl;
                                                        std::cin >> aClass;
                                                        if(application.ValidData("default","default",aClass))
                                                        {
                                                            std::cout << "¡...............................¡" << std::endl;
                                                            std::cout << "|1. Sort by UC:                 |" << std::endl;
                                                            std::cout << "|2. Sort in ascending order:    |" << std::endl;
                                                            std::cout << "|3. Sort in descending order:   |" << std::endl;
                                                            std::cout << "¡...............................¡" << std::endl;
                                                            int order;
                                                            std::cin >> order;
                                                            application.consultOCupationofClassForUc("default",aClass,1,2,order);
                                                            key11 = 0;
                                                        }
                                                        break;

                                                    }

                                                    case 3:
                                                    {
                                                        std::string UC;

                                                        std::cout << "¡.......................... ¡" << std::endl;
                                                        std::cout << "| Please insert the UC:     |" << std::endl;
                                                        std::cout << "¡...........................¡" << std::endl;
                                                        std::cin >> UC;
                                                        std::string theClass;
                                                        std::cout << "¡.......................... ¡" << std::endl;
                                                        std::cout << "| Please insert the Class:  |" << std::endl;
                                                        std::cout << "¡...........................¡" << std::endl;
                                                        std::cin >> theClass;

                                                        if(application.ValidData("default",UC,theClass))
                                                            application.consultOCupationofClassForUc(UC,theClass,1,3);
                                                        key11 = 0;
                                                        break;
                                                    }
                                                    case 0:
                                                    {
                                                        key11=0;
                                                        break;
                                                    }
                                                    default:
                                                    {
                                                        std::cout << "¡....................................¡" << std::endl;
                                                        std::cout << "|     Please insert a valid key!     |" << std::endl;
                                                        std::cout << "!....................................!" << std::endl;
                                                    }

                                                }
                                            }

                                         break;
                                        }
                                        case 2:
                                        {
                                            application.consultOCupationofClassForUc("default","default",2);
                                            key11=0;
                                            break;
                                            //total
                                        }
                                        case 0: break;
                                        default:
                                        {
                                            std::cout << "¡....................................¡" << std::endl;
                                            std::cout << "|     Please insert a valid key!     |" << std::endl;
                                            std::cout << "!....................................!" << std::endl;
                                        }

                                    }
                                }



                            }
                            case 0: break;
                            default:
                            {
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "|     Please insert a valid key!     |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                break;
                            }
                        }
                    }

                    break;
                }//.............................................................................................//
                case 4:
                {
                    int key7 = -1;
                    while(key7)
                    {
                        std::cout << "¡...............................................................¡" << std::endl;
                        std::cout << "|1.Consult student details                                      |" << std::endl;
                        std::cout << "|2.Consult the number of students registered in at least n UCs  |" << std::endl;
                        std::cout << "|0.Leave                                                        |" << std::endl;
                        std::cout << "¡...............................................................¡" << std::endl;
                        std::cin >> key7;
                        switch(key7)
                        {
                            case 1:
                            {
                                std::string name;
                                std::cout << "¡..................................................¡" << std::endl;
                                std::cout << "| Please insert the name or ID of the student      |" << std::endl;
                                std::cout << "¡..................................................¡" << std::endl;
                                std::cin >> name;
                                application.consultStudentDetails(name);
                                break;

                            }
                            case 2:
                            {
                                int n;
                                std::cout << "¡..................................................¡" << std::endl;
                                std::cout << "| Please insert a number:                          |" << std::endl;
                                std::cout << "¡..................................................¡" << std::endl;
                                std::cin >> n;
                                application.moreThanN(n);
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
                    }
                    break;
                }//........................................................................................................//
                case 5:
                {
                    int key8 = -1;
                    while(key8)
                    {
                        std::cout << "¡...............................¡" << std::endl;
                        std::cout << "|1. Add UC                      |" << std::endl;
                        std::cout << "|2. Remove UC                   |" << std::endl;
                        std::cout << "|3. Switch class                |" << std::endl;
                        std::cout << "|4. Accept requests             |" << std::endl;
                        std::cout << "|5. Revert last request         |" << std::endl;
                        std::cout << "|0. Leave                       |" << std::endl;
                        std::cout << "¡...............................¡" << std::endl;
                        std::cin >> key8;
                        switch (key8)
                        {
                            case 1:  //Add UC -> type of Request 1
                            {
                                std::string name, UC, aCLass;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the student's name:  |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>name;
                                if(!application.ValidData(name,"default","default")) break;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the UC :             |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>UC;
                                if(!application.ValidData("default",UC,"default")) break;

                                int key9 = -1;
                                while(key9)
                                {
                                    std::cout << "¡....................................¡" << std::endl;
                                    std::cout << "| Do you have a desirable class?:    |" << std::endl;
                                    std::cout << "|1. Yes                              |" << std::endl;
                                    std::cout << "|2. No                               |" << std::endl;
                                    std::cout << "|0. Leave                            |" << std::endl;
                                    std::cout << "!....................................!" << std::endl;
                                    std::cin>>key9;
                                    switch(key9)
                                    {
                                        case 1:
                                        {
                                            std::cout << "¡....................................¡" << std::endl;
                                            std::cout << "| Please insert the class :          |" << std::endl;
                                            std::cout << "!....................................!" << std::endl;
                                            std::cin>> aCLass;
                                            if(application.ValidData(name,UC,aCLass))
                                            {
                                                Request newRequest(1,name,UC,aCLass,1,0); //THE VALUE PASSING IS 0?
                                                application.addRequest(newRequest);
                                                std::cout << "New request submitted for "<< name << " to add an UC"<<std::endl;
                                            }
                                            key9 =0;
                                            break;
                                        }
                                        case 2:
                                        {
                                            if(application.ValidData(name,UC,"default"))
                                            {
                                                Request newRequest(1,name,UC,"default",2);
                                                application.addRequest(newRequest);
                                                std::cout << "New request submitted for "<< name << " to add an UC"<<std::endl;
                                            }
                                            key9 = 0;
                                            break;
                                        }
                                        case 0: break;


                                        default:
                                        {
                                            std::cout << "¡....................................¡" << std::endl;
                                            std::cout << "|     Please insert a valid key!     |" << std::endl;
                                            std::cout << "!....................................!" << std::endl;
                                        }
                                    }
                                }
                                break;
                            }

                            case 2: //Remove UC
                            {

                                std::string name, UC;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the student's name:  |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>name;
                                if(!application.ValidData(name,"default","default")) break;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the UC :             |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>UC;
                                if(application.ValidData(name,UC,"default"))
                                {
                                    Request newRequest(2,name,UC);
                                    application.addRequest(newRequest);
                                    std::cout << "New request submitted for "<< name << " to remove an UC"<<std::endl;

                                }

                                break;
                            }
                            case 3:
                            {
                                std::string name, UC, newClass;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the student's name:  |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>name;
                                if(!application.ValidData(name,"default","default")) break;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the UC :             |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>UC;
                                if(!application.ValidData("default",UC,"default")) break;
                                std::cout << "¡....................................¡" << std::endl;
                                std::cout << "| Please insert the new class:       |" << std::endl;
                                std::cout << "!....................................!" << std::endl;
                                std::cin>>newClass;
                                if(application.ValidData(name,UC,newClass))
                                {
                                    Request newRequest(3,name,UC,newClass);
                                    application.addRequest(newRequest);
                                    std::cout << "New request submitted for "<< name << " to switch a class"<<std::endl;
                                }
                                break;
                            }
                            case 4:
                            {
                                int key10 = -1;
                                while(key10)
                                {
                                    std::cout << "¡...............................¡" << std::endl;
                                    std::cout << "|1. Check Requests              |" << std::endl;
                                    std::cout << "|2. Process all Requests        |" << std::endl;
                                    std::cout << "|3. Process first Request       |" << std::endl;
                                    std::cout << "|0. Leave                       |" << std::endl;
                                    std::cout << "¡...............................¡" << std::endl;
                                    std::cin >> key10;
                                    switch(key10)
                                    {
                                        case 1:
                                        {
                                            application.checkRequests();
                                            break;
                                        }
                                        case 2:
                                        {
                                            int value = 1;
                                            application.processRequests(1);
                                            break;
                                        }
                                        case 3:
                                        {
                                            int value = 2;
                                            application.processRequests(2);

                                        }
                                        case 0: break;
                                        default:
                                        {
                                            std::cout << "¡..........................¡" << std::endl;
                                            std::cout << "| CHOOSE A VALID KEY!      |" << std::endl;
                                            std::cout << "¡..........................¡" << std::endl;
                                        }
                                    }
                                }
                                break;
                            }
                            case 5:
                            {
                                application.reverseRequests();
                                break;
                            }
                            case 0: break;
                            default:
                                std::cout << "¡..........................¡" << std::endl;
                                std::cout << "| CHOOSE A VALID KEY!      |" << std::endl;
                                std::cout << "¡..........................¡" << std::endl;

                        }

                    }
                    break;
                }
                case 0:
                {
                    std::cout << "Program terminated" <<std::endl;
                    break;
                }
                default:
                    std::cout << "¡..........................¡" << std::endl;
                    std::cout << "| CHOOSE A VALID KEY!      |" << std::endl;
                    std::cout << "¡..........................¡" << std::endl;
                    break;
            }




    }
    return 0;
}