//
// Created by tiagomonteiro on 10/18/23.
//

#include "Application.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

Application::Application() //sort data in the right containers
{
    std::ofstream clearFile("../log.txt", std::ios::trunc);
    std::ifstream in("students_classes.csv");  //Parsing of student info
    std::string line;
    std::getline(in, line, '\n');
    while (std::getline(in, line, '\n')) {
        line = line.substr(0, line.length() - 1); //you bastards I spent 1 day trying to figure out this
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> saved;
        while (std::getline(iss, word, ',')) saved.push_back(word);

        ClassForUc classes(saved[3], saved[2]);
        Student student(saved[0], saved[1], {classes});
        auto findStudent = students.find(student);

        if (findStudent != students.end()) //If the student is already in the set:
        {
            auto classesStudent = findStudent->getStudentSchedule();
            students.erase(findStudent);
            for (auto aula: classesStudent) //aula means class in portuguese
            {
                student.addClass(aula);
            }
        }
        students.insert(student);
    }

    std::ifstream in1("classes.csv"); //Parsing of classes info
    std::string line1;
    std::getline(in1, line1, '\n');
    while (std::getline(in1, line1, '\n')) {
        line1 = line1.substr(0, line1.length() - 1);
        std::istringstream iss(line1);
        std::string word;
        std::vector<std::string> saved;
        while (std::getline(iss, word, ',')) saved.push_back(word);

        Block block(saved[2], stof(saved[3]), stof(saved[4]), saved[5]);
        ClassForUc classes(saved[0], saved[1]);

        ScheduleUC scheduleUc(classes, {block});

        auto findClass = schedules.find(scheduleUc);

        if (findClass != schedules.end()) //If the schedule is already in the set:
        {
            auto classesUcClass = findClass->getUcClassSchedule();
            schedules.erase(findClass);
            for (auto block: classesUcClass) //aula means class in portuguese
            {
                scheduleUc.addBlock(block);
            }
        }
        schedules.insert(scheduleUc);
    }

    std::ifstream in2("classes_per_uc.csv"); //Parsing of classes info
    std::string line2;
    std::getline(in2, line2, '\n');
    while (std::getline(in2, line2, '\n'))
    {
        line2 = line2.substr(0, line2.length() - 1);
        std::istringstream iss(line2);
        std::string word;
        std::vector<std::string> saved;
        while (std::getline(iss, word, ',')) saved.push_back(word);
        existingUCs.insert(saved[0]);
        existingClasses.insert(saved[1]);
        ClassForUc comp(saved[1],saved[0]);
        existingCombinations.insert(comp);
    }
} //................................END OF THE CONSTRUCTOR....................................//

std::set<Block> Application::printStudentSchedule(std::string name,int key) //Kinda complex by now but gives us the schedule of a student
{
    std::set<Block> res;
    Student student;

    for (auto theStudent: students)  //Search for the student
    {
        if (theStudent.getName() == name) {
             student = theStudent;
            break;
        }
    }

    for (auto studentClass: student.getStudentSchedule())
        for (auto ucClasses: schedules)
            if (studentClass == ucClasses.getClassForUc())
                for (auto block : ucClasses.getUcClassSchedule())
                {
                    res.insert(block);
                }

    for(auto block : res)
    {
        float begin = block.getStartHour();
        float duration = block.getDuration();
        if(!key)std::cout << block.getDay() << " " << block.getStartHour() << "-" <<begin+duration << " "<< block.getType() <<std::endl;
    }

    return res;


}
//.....................................................................................................................................//
std::set<Block> Application::printClassSchedule(std::string aClass, int key)
{
    std::set<Block> res;

    for(auto schedule: schedules)
        if(schedule.getClassForUc().getUcClass() == aClass)
            for(auto block:schedule.getUcClassSchedule()) res.insert(block);

    for(auto block : res)
    {
        float begin = block.getStartHour();
        float duration = block.getDuration();
        if(!key) std::cout << block.getDay() << " " << block.getStartHour() << "-" <<begin+duration << " "<< block.getType() <<std::endl;
    }

    return res;

}
//.....................................................................................................................................//

bool Application::ValidData(std::string name, std::string UC, std::string aClass, int year)
{

    if(existingUCs.find(UC) == existingUCs.end() && UC != "default")
    {
        std::cout << "NOT A VALID UC" << std::endl;
        return false;
    }

    if(existingClasses.find(aClass) == existingClasses.end() && aClass != "default")
    {
        std::cout << "NOT A VALID CLASS" << std::endl;
        return false;
    }

    if(year>0 && year<4)
    {
        std::cout << "NOT A VALID YEAR" <<std::endl;
        return false;

    }

    ClassForUc classforuc(aClass,UC);

    if(existingCombinations.find(classforuc) == existingCombinations.end() && aClass != "default" && UC != "default")
    {
        std::cout << "NOT A VALID CLASS FOR THAT UC" << std::endl;
        return false;
    }

    if(name == "default") return true;

    for(auto theStudent:students)
    {
        if(theStudent.getName() == name)
            return true;
    }

        std::cout << "That student does not exist"<<std::endl;
        return false;

}

//.....................................................................................................................................//
std::set<Block> Application::printClassForUCSchedule(ClassForUc classforuc,int key)
{
    std::set<Block> res;

    for(auto schedule:schedules)
        if(schedule.getClassForUc() == classforuc)
            for(auto block:schedule.getUcClassSchedule())
                res.insert(block);

    for(auto block:res)
    {
        float begin = block.getStartHour();
        float duration = block.getDuration();
        if(!key) std::cout << block.getDay() << " " << block.getStartHour() << "-" <<begin+duration << " "<< block.getType() <<std::endl;
    }

    return res;
}

//.....................................................................................................................................//
void Application::studentsInClass(std::string aClass) //prints all the students in a class
{
    std::set<std::string> studentsList;

    for (auto student:students)
    {
        bool belongs = false;
        std::vector<std::string>UC;
        for(auto schedule: student.getStudentSchedule())
        {
            if(schedule.getUcClass() == aClass)
            {
                belongs = true;
                UC.push_back(schedule.getUcCode());
            }
        }

        if (belongs)
        {
            std::cout << student.getName() << " is on " << aClass << " for ";
            for(auto uc: UC)
            {
                std::cout << uc << " ";
            }
            std::cout<<std::endl;
        }
    }

}
//.....................................................................................................................................//
void Application::studentsInUC(std::string UC)
{
        for(auto student:students)
            for(auto schedule:student.getStudentSchedule())
                if(schedule.getUcCode() == UC)
                    std::cout << student.getName() <<" is on " << UC << " (" <<  schedule.getUcClass() << ")" << std::endl;
}
//.....................................................................................................................................//
void Application::studentsInYear(std::string year)
{
    bool doIt = true;

    if(year < "1" || year >"3")
    {
        std::cout << "Not a valid year, please insert a number between 1 and 3" << std::endl;
        doIt = false;
    }

    if(doIt)
    {
        for (auto student: students)
        {
            std::vector<std::string> UCs;

            for (auto schedule: student.getStudentSchedule())
            {
                std::string studentYear = schedule.getUcClass().substr(0, 1);
                if(schedule.getUcClass() == "UP001") studentYear = "1"; //The teachers won't fool me
                if (studentYear == year)
                    UCs.push_back(schedule.getUcCode());
            }

            if (!UCs.empty())
            {
                std::cout << student.getName() << " is on " << year;
                if (year == "1") std::cout << "st year";
                else if (year == "2") std::cout << "nd year";
                else if (year == "3") std::cout << "rd year";
                else std::cout << "th year";
                std::cout << " for the following UCs: ";
                for (auto UC: UCs)
                {
                    std::cout << UC << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}
//.....................................................................................................................................//
int Application::studentsInClassForUC(std::string UC, std::string aClass, int key1) {
    int count = 0;
    ClassForUc key = {aClass, UC};

    for (auto student: students)
        for (auto schedule: student.getStudentSchedule())
            if (schedule == key) {
                count++;
                if(!key1)std::cout << student.getName() << std::endl;
            }
    if(!key1)std::cout << "UC " << UC << " for class " << aClass << " has " << count << " students" << std::endl;

    return count;

}
//.....................................................................................................................................//
void Application::consultOcupationOfUCs(int order,std::string UC ,int key)  //prints the number of students of each UC
{
    if(!key) //TOTAL
    {
        std::map<std::string,int> studentsPerUC; //DEFAULT IS BY UC
        for(auto UC:existingUCs) studentsPerUC.try_emplace(UC,0);
        for(auto UC: existingUCs)
            for(auto student:students)
                for(auto schedule: student.getStudentSchedule())
                    if(UC == schedule.getUcCode()) studentsPerUC[schedule.getUcCode()] ++;

        std::vector<std::pair<int, std::string>> sortedValues;

        for (const auto &entry : studentsPerUC)
            sortedValues.emplace_back(entry.second, entry.first);

        if(order > 0 && order < 4)
        {
            if (order == 2) //ASCENDING
                std::sort(sortedValues.begin(), sortedValues.end());

            else if (order == 3)  //DESCENDING
                std::sort(sortedValues.rbegin(), sortedValues.rend());

            for (const auto &pair : sortedValues)
                std::cout << pair.second << ": " << pair.first << std::endl;
        }
        else std::cout << "NOT A VALID KEY"<<std::endl;


    }
    else //PARTIAL
    {
        int count = 0;
        for(auto student:students)
        {
            for(auto schedule: student.getStudentSchedule())
            {
                if(schedule.getUcCode() == UC) count++;
            }
        }
        std::cout << UC << ": " << count<<std::endl;
    }

}

void Application::consultOcupationOfClasses(int order, std::string aClass, int key) {

    if (!key)
    {
        std::map<std::string, int> studentsPerClass; // DEFAULT IS BY UC
        for (auto UC : existingClasses) studentsPerClass.try_emplace(UC, 0);

        for (auto student : students)
            for (auto schedule : student.getStudentSchedule())
                if (studentsPerClass.find(schedule.getUcClass()) != studentsPerClass.end())
                    studentsPerClass[schedule.getUcClass()]++;

        std::vector<std::pair<int, std::string>> sortedValues;
        for (const auto &entry : studentsPerClass)
            sortedValues.emplace_back(entry.second, entry.first);

        if(order > 0 && order < 4)
        {
            if (order == 2) // ASCENDING
                std::sort(sortedValues.begin(), sortedValues.end());
            else if (order == 3)  // DESCENDING
                std::sort(sortedValues.rbegin(), sortedValues.rend());

            for (const auto &pair : sortedValues)
                std::cout << pair.second << ": " << pair.first << std::endl;

        }
        else std::cout << "NOT A VALID KEY"<<std::endl;


    }
    else // PARTIAL
    {
        int count = 0;
        for (auto student : students)
            for (auto schedule : student.getStudentSchedule())
                if (schedule.getUcClass() == aClass)
                    count++;
        std::cout << aClass << ": " << count << std::endl;

    }
}

void Application::consultOcupationofYear(int order, std::string year ,int key)
{
    if (!key)
    {
        std::map<std::string, int> studentsPerYear {{"1", 0}, {"2", 0}, {"3", 0}}; // Initialize with zero for years 1, 2, and 3

        for (auto student : students) {
            std::set<std::string> attendedYears; // Using a set to keep track of attended years for a student

            for (auto schedule : student.getStudentSchedule()) {
                std::string studentYear = schedule.getUcClass().substr(0, 1);
                attendedYears.insert(studentYear); // Collect attended years for a student
            }
            for ( auto attendedYear : attendedYears) {
                studentsPerYear[attendedYear]++; // Increment the count for each attended year
            }
        }

        std::vector<std::pair<int, std::string>> sortedValues;
        for (const auto &entry : studentsPerYear) {
            sortedValues.emplace_back(entry.second, entry.first);
        }

        if(order > 0 && order < 4)
        {
            if (order == 2) { // ASCENDING
                std::sort(sortedValues.begin(), sortedValues.end());
            }
            else if (order == 3) { // DESCENDING
                std::sort(sortedValues.rbegin(), sortedValues.rend());
            }

            for (const auto &pair : sortedValues) {
                std::cout << pair.second << ": " << pair.first << std::endl;
            }
        }
        else std::cout << "NOT A VALID KEY"<<std::endl;


    }
    else //Partial
    {
        bool doIt = true;
        if(year < "1" || year > "3")
        {
            std::cout << "Not a valid year, please insert a number between 1 and 3" << std::endl;
            doIt = false;
        }
        if(doIt)
        {
            int count = 0;
            for(auto student:students)
            {
                for(auto schedule:student.getStudentSchedule())
                {
                    auto studentYear = schedule.getUcClass().substr(0,1);
                    if(studentYear == year)
                    {
                        count++;
                        break;
                    }
                }
            }
            std::cout << year << ": " << count << std::endl;
        }
    }
} //......................................................................................................//

void Application::consultOCupationofClassForUc(std::string UC, std::string aClass,int key1, int key2, int order ) //consult the number of students on a class for a UC
{
    std::map<ClassForUc, int> res;
    if(key1 == 1) //Partial
    {
        switch(key2)
        {
            case 1: //UC
            {
                for(auto classforuc: existingCombinations) if(classforuc.getUcCode() == UC) res.try_emplace(classforuc, 0);
                for(auto student: students)
                {
                    for(auto schedule:student.getStudentSchedule())
                        if(schedule.getUcCode() == UC) res[schedule]++;

                }

                std::vector<std::pair<int, ClassForUc>> sortedValues;
                for (const auto &entry : res)
                    sortedValues.emplace_back(entry.second, entry.first);

                if(order > 0 && order < 4)
                {
                    if (order == 2) // ASCENDING
                        std::sort(sortedValues.begin(), sortedValues.end());
                    else if (order == 3)  // DESCENDING
                        std::sort(sortedValues.rbegin(), sortedValues.rend());

                    for (const auto &pair : sortedValues)
                        std::cout << pair.second.getUcCode()<< "->" << pair.second.getUcClass() << ": " << pair.first << std::endl;

                }
                else std::cout << "NOT A VALID KEY"<<std::endl;

                break;
            }
            case 2: //class
            {
                for(auto classforuc: existingCombinations) if(classforuc.getUcClass() == aClass) res.try_emplace(classforuc, 0);
                for(auto student: students)
                {
                    for(auto schedule:student.getStudentSchedule())
                        if(schedule.getUcClass() == aClass) res[schedule]++;

                }

                std::vector<std::pair<int, ClassForUc>> sortedValues;
                for (const auto &entry : res)
                    sortedValues.emplace_back(entry.second, entry.first);
                if(order > 0 && order < 4)
                {
                    if (order == 2) // ASCENDING
                        std::sort(sortedValues.begin(), sortedValues.end());
                    else if (order == 3)  // DESCENDING
                        std::sort(sortedValues.rbegin(), sortedValues.rend());

                    for (const auto &pair : sortedValues)
                        std::cout << pair.second.getUcCode()<< "->" << pair.second.getUcClass() << ": " << pair.first << std::endl;

                }
                else std::cout << "NOT A VALID KEY"<<std::endl;


                break;
            }
            case 3: //CLASS+UC
            {
                ClassForUc value(aClass,UC);
                int count = 0;
                for(auto student: students)
                {
                    for(auto schedule:student.getStudentSchedule())
                        if(schedule == value) count ++;
                }

                std::cout << UC << "->" << aClass << ": " << count << std::endl;
                break;
            }
        }
    }
    if (key1 == 2) //Total
    {
        for(auto classforuc: existingCombinations) res.try_emplace(classforuc, 0);
        for(auto student: students)
        {
            for(auto schedule:student.getStudentSchedule())
            {
                res[schedule]++;
            }

        }
        for(auto data: res)
        {
            std::cout << data.first.getUcCode() << "->"<< data.first.getUcClass()<<": " << data.second <<std::endl;
        }
    }
}


//.....................................................................................................................//
void Application::consultStudentDetails(std::string info)
{
    int countUC = 0;
    std::string name;
    std::map<std::string,int> yearInfo{{"1",0},{"2",0},{"3",0}};
    std::map<std::string,int> classInfo;
    bool found = false;
    Student student;
    for(auto theStudent:students)
    {
        if(theStudent.getName() == info || theStudent.getId() == info)
        {
            student = theStudent;
            std::cout << "Name: " << theStudent.getName() << std::endl; //Name
            std::cout << "ID: " << theStudent.getId() << std::endl; //ID
            theStudent.printSchedule();
            found = true;
            break;
        }
    }

    if(found)
    {
        for(auto schedule: student.getStudentSchedule())
        {
            auto it = classInfo.find(schedule.getUcClass());
            if(it != classInfo.end()) it->second++;
            else classInfo[schedule.getUcClass()] = 1;
            countUC++;
            auto classYear = schedule.getUcClass().substr(0,1);
            if(classYear == "1") yearInfo[classYear]++;
            else if(classYear == "2") yearInfo[classYear]++;
            else if (classYear == "3") yearInfo[classYear]++;
        }

        std::cout << name << " is on " << countUC << " UC(s)." <<std::endl;
        std::cout << name << " is on " ;
        for(auto aClass: classInfo)
            std::cout << aClass.first << " for " << aClass.second << " class(es), ";

        std::cout << std::endl;
        std::cout << name << " is on " ;
        for(auto year: yearInfo)
            std::cout << "year " << year.first << " for " << year.second << " class(es) ";

        std::cout<<std::endl;
    }
    else std::cout << "No student was found with that name or ID!"<<std::endl;
}
//....................................................................................................................//
void Application::moreThanN(int n)
{
    if(n > 0 && n<= 7)
    {
        std::map<std::string,int>UCs;
        for(auto student:students)
        {
            for(auto schedule:student.getStudentSchedule())
            {
                auto it = UCs.find(student.getName());
                if(it != UCs.end()) it->second++;
                else UCs[student.getName()] = 1;
            }
        }
        for(auto pair: UCs)
            if(pair.second >= n) std::cout << pair.first << std::endl;
    }
    else std::cout << "Please insert a number between 1 and 7!"<<std::endl;
}
//..................................................................................................................................//
bool Application::addUC(std::string name, std::string UC,std::string aClass, int key, int undo) //missing that code that checks balance!!
{
    std::ofstream logfile("../log.txt", std::ios::app);
    std::vector<ClassForUc>in;
    Student student;
    std::string id;
    int count = 0;

    for(auto theStudent: students)
    {
        if (theStudent.getName() == name)
        {
            student = theStudent;
            id = theStudent.getId();
            break;
        }
    }
    //logfile << name <<":" << std::endl;
    //std::cout << name <<":" << std::endl;

    for(auto schedule:student.getStudentSchedule())
    {
        if(schedule.getUcCode() == UC)
        {
            std::cout << name << " can't add " << UC << " because she/he is already in it"<<std::endl;
            return false;
        }
        count++;
    }

    if(count >=7)
    {
        std::cout << name << " has reached the maximum number of UCs" << std::endl;
        return false;
    }


    auto schedule = printStudentSchedule(name,1); //student schedule in blocks.

    if(key == 1) //A specific class
    {
        int membersBeforeChange =  studentsInClassForUC(UC,aClass,1); //to test balance

        if(studentsInClassForUC(UC, aClass, 1) >= CAP)
        {
            std::cout << "The maximum amount of students for the class" << aClass << " has been reached in UC "<< UC <<std::endl;
            return false;
        }

        auto addSchedule = printClassForUCSchedule({aClass,UC},1); //blocks trying to be added

        for(auto fixedBlock: schedule)
        {
            for(auto tryBlock:addSchedule)
            {
                if(fixedBlock.overlapping(tryBlock)) //I haven't done overlapping yet
                {
                    std::cout << name << " can't join class " << aClass << " in UC " << UC <<"because it will create overlaps on it's schedule "<<std::endl;
                    return false;
                }
            }
        }

        for(auto data:student.getStudentSchedule()) in.push_back(data);
        in.push_back({aClass,UC}); //schedule with the new class added

        students.erase(student);
        Student newStudent(id,name,in);  //we take out the previous data and add the new to the set
        students.insert(newStudent);

        int classTestedMembers = studentsInClassForUC(UC,aClass,1); //no. students with student in the new class

        std::vector<int> numberOfStudentsUC;
        for(auto theCLass:existingClasses) //last test before adding student is balance
        {
            if(studentsInClassForUC(UC,theCLass,1) !=0)
            {
                numberOfStudentsUC.push_back(studentsInClassForUC(UC,theCLass,1)); //creates a vector with the ocupation of all classes for that UC
            }                                                                                   //To check the balance of the classes
        }
        for(auto classes: numberOfStudentsUC)
        {
            if(abs(classTestedMembers-classes) >4)
            {
                if(abs(classTestedMembers-classes) > abs(membersBeforeChange-classes))
                {
                    students.erase(newStudent);                                         // and just put it back as it was
                    students.insert(student);
                    std::cout << name << " can't switch to " << aClass << " in "<< UC << " because the balance between class occupation is disturbed"<<std::endl;
                    return false; // If the difference is greater than 4, return false
                }
            }
        }
        logfile << UC << " on class " << aClass << " was successfully added to the "<< name << " schedule" <<std::endl;
        std::cout <<  UC << " on class " << aClass << " was successfully added to the "<< name << " schedule" <<std::endl;
        if(!undo)
        {
            Request undo(2,student.getName(),UC); //useful if we want to undo this process later
            requestsProcessed.push(undo);
        }

        return true;
    }
    //ANY CLASS THAT WORKS:

    for(auto classes: schedules)
    {
        int membersBeforeChange =  studentsInClassForUC(UC,aClass,1); //to test balance

        bool works = false;
        if(classes.getClassForUc().getUcCode() == UC)
        {
            works = true;
            if(studentsInClassForUC(UC, classes.getClassForUc().getUcClass(), 1) >= 30) continue;

            auto addSchedule = printClassForUCSchedule(classes.getClassForUc(),1);
            for(auto fixedBlock: schedule)
            {
                for(auto tryBlock:addSchedule)
                {
                    if(fixedBlock.overlapping(tryBlock))
                    {
                        works = false;
                        continue;
                    }
                    if(!works) break;
                }
                if(!works) break;
            }
        }

        if(works)
        {
            for(auto schedule:student.getStudentSchedule()) in.push_back(schedule);
            in.push_back({classes.getClassForUc().getUcClass(),UC});

            students.erase(student);
            Student newStudent(id,name,in);
            students.insert(newStudent);

            int classTestedMembers = studentsInClassForUC(UC,aClass,1); //no. students with student in the new class

            std::vector<int> numberOfStudentsUC;
            for(auto theCLass:existingClasses) //last test before adding student is balance
            {
                if(studentsInClassForUC(UC,theCLass,1) !=0)
                {
                    numberOfStudentsUC.push_back(studentsInClassForUC(UC,theCLass,1)); //creates a vector with the ocupation of all classes for that UC
                }                                                                                   //To check the balance of the classes
            }
            for(auto classes: numberOfStudentsUC)
            {
                if(abs(classTestedMembers-classes) >4)
                {
                    if(abs(classTestedMembers-classes) > abs(membersBeforeChange-classes)) //does it improve the balance or not?
                    {
                        students.erase(newStudent);                                         // and just put it back as it was
                        students.insert(student);
                        works = false;
                    }
                }
            }

            if(works)
            {
                std::cout <<  UC << " on class " << classes.getClassForUc().getUcClass() << " was successfully added to the "<< name << " schedule" <<std::endl;
                logfile << UC << " on class " << classes.getClassForUc().getUcClass() << " was successfully added to the "<< name << " schedule" <<std::endl;
                if(!undo)
                {
                    Request undoit(2,student.getName(),UC,"default",2,1);
                    requestsProcessed.push(undoit);
                }
                return true;
            }

        }
    }
    std::cout << "Sorry, no available classes for" << UC <<"that don't overlap " << name << " schedule" <<std::endl;
    return  false;




}
//...........................................................................................................................................................//
bool Application::removeUC(std::string name, std::string UC, int undo)
{
    std::ofstream logfile("../log.txt", std::ios::app);
    std::vector<ClassForUc> in;
    Student student;
    std::string id;
    std::string oldCLass;
    bool foundUC = false;

    for(auto theStudent: students)
        if(theStudent.getName() == name) {

            id = theStudent.getId();
            student = theStudent;
            break;
        }


    for(auto schedule: student.getStudentSchedule())
    {
        if(schedule.getUcCode() != UC)
            in.push_back(schedule);
        else
        {
            foundUC = true;
            oldCLass = schedule.getUcClass(); //for undo :)
        }
    }
    if(!foundUC)
    {
        std::cout << name << " does not have " << UC << " in his schedule" <<std::endl;

        return false;
    }


    students.erase(student);
    Student  newStudent(id,name,in);
    students.insert(newStudent);
    logfile << name  << " was removed from " <<  UC << std::endl;
    std::cout<< name  << " was removed from " <<  UC << std::endl;

    if(!undo) //UNDO = 0
    {
        Request undoit(1,student.getName(),UC,oldCLass,1,1);
        requestsProcessed.push(undoit);
    }


    if(in.empty()) //not really useful, I just thought it would be interesting
    {
        std::cout << name << " does not have any more UCs in his schedule"<<std::endl;
        return true;
    }
    return true;

}
//.....................................................................................................//
bool Application::switchClass(std::string name, std::string UC, std::string newClass, int undo)
{
    std::ofstream logfile("../log.txt", std::ios::app);
    std::string oldClass;
    Student studentCurrent;
    std::string id;
    std::vector<ClassForUc> in;
    bool foundUC = false;
    int membersBeforeChange =  studentsInClassForUC(UC,newClass,1); //to test balance


    if(studentsInClassForUC(UC, newClass, 1) >= CAP)
    {
        std::cout << name << "can't join" << newClass << "because the maximum amount of students for this class has been reached"<<std::endl;
        return false;
    }

    for(auto theStudent:students)
    {
        if(theStudent.getName() == name)
        {
            id = theStudent.getId();
            studentCurrent = theStudent;
            break;
        }
    }


    for(auto schedule: studentCurrent.getStudentSchedule())
    {
        if(schedule.getUcCode() == UC)
        {
            oldClass = schedule.getUcClass(); //for undoing
            foundUC = true;
        }
        else in.push_back(schedule); //a vector with the same classes the student used to have except the one that we want to change
    }
    if(!foundUC)
    {
        std::cout << name << " can't switch to " << newClass << " because he is not in "<< UC << std::endl;
        return false;
    }

    bool overlap = false;
    students.erase(studentCurrent);
    Student newStudent(id,name,in); //student with the new schedule
    students.insert(newStudent);

    auto addSchedule = printClassForUCSchedule({newClass,UC},1);
    auto schedule = printStudentSchedule(name,1);

    for(auto fixedBlock: schedule)
    {
        for(auto tryBlock:addSchedule)
        {
            if(fixedBlock.overlapping(tryBlock)) overlap = true;
        }
    }

    if(overlap)
    {
        students.erase(newStudent);
        students.insert(studentCurrent);
        std::cout << name << " can't be in " << newClass <<  " in " << UC <<" because it will create overlaps in his schedule" <<std::endl;
        return false;
    }

    students.erase(newStudent);
    in.push_back({newClass,UC}); //class that was missing
    Student newStudent1(id,name,in); //student with the new schedule

    students.insert(newStudent1); //Finally new student is on the students list
    int classTestedMembers = studentsInClassForUC(UC,newClass,1); //no. students with student in the new class

    std::vector<int> numberOfStudentsUC;
    for(auto theCLass:existingClasses) //last test before adding student is balance
    {
        if(studentsInClassForUC(UC,theCLass,1) !=0)
        {
            numberOfStudentsUC.push_back(studentsInClassForUC(UC,theCLass,1)); //creates a vector with the ocupation of all classes for that UC
        }                                                                                   //To check the balance of the classes
    }
    for(auto classes: numberOfStudentsUC)
    {
        if(abs(classTestedMembers-classes) >4)
        {
            if(abs(classTestedMembers-classes) > abs(membersBeforeChange-classes))
            {
                students.erase(newStudent);                                         // and just put it back as it was
                students.insert(studentCurrent);
                std::cout << name << " can't switch to " << newClass <<" in "<< UC <<" because the balance between class occupation is disturbed"<<std::endl;
                return false; // If the difference is greater than 4, return false
            }
        }
    }

    logfile << name << " class has been changed from " << oldClass << " to " << newClass << " on UC " << UC << std::endl;
    std::cout << name << " class has been changed from " << oldClass << " to " << newClass << " on UC " << UC << std::endl;

    if(!undo)
    {
        Request undoit(3,newStudent.getName(),UC,oldClass,2,1);
        requestsProcessed.push(undoit);
    }

    return true;
}

void Application::addRequest(Request request)
{
    requests.push(request);

}

bool Application::processRequests(int key) {

    if (requests.empty())
    {
        std::cout << "No requests to process" << std::endl;
        return false;
    }

    switch (key)
    {
        case 1:
        {
            while (!requests.empty())
            {
                Request request = requests.front();
                requests.pop();
                switch (request.getType())
                {
                    case 1: {
                        addUC(request.getName(), request.getUc(), request.getAClass(), request.getKey(),request.getUndo());
                        break;
                    }
                    case 2: {
                        removeUC(request.getName(), request.getUc(), request.getUndo());
                        break;
                    }
                    case 3: {
                        switchClass(request.getName(), request.getUc(), request.getAClass(), request.getUndo());
                        break;
                    }
                }
            }
            return true;
        }
        case 2:
        {
            Request request = requests.front();
            requests.pop();
            std::cout << request.getName() << " is trying to ";
            switch (request.getType()) {
                case 1: {
                    if (request.getKey() == 1)
                        std::cout << "add UC " << request.getUc() << " for class " << request.getAClass() << std::endl;
                    else std::cout << "add UC " << request.getUc() << " for any class" << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "remove UC " << request.getUc() << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "switch to class " << request.getAClass() << " in UC " << request.getUc() << std::endl;
                    break;
                }
            }
            int theKey = -1;
            while(theKey)
            {
                std::cout << "Do you want to accept this request?" << std::endl;
                std::cout << "¡............¡" << std::endl;
                std::cout << "|1.Yes       |" << std::endl;
                std::cout << "|2.No        |" << std::endl;
                std::cout << "¡............¡" << std::endl;

                std::cin >> theKey;
                if (theKey == 1) {
                    switch (request.getType()) {
                        case 1: //ADD UC
                        {
                            addUC(request.getName(), request.getUc(), request.getAClass(), request.getKey(),
                                  request.getUndo());
                            break;
                        }
                        case 2: {
                            removeUC(request.getName(), request.getUc(), request.getUndo());
                            break;
                        }
                        case 3: {
                            switchClass(request.getName(), request.getUc(), request.getAClass(), request.getUndo());
                            break;
                        }
                    }
                    return true;

                }

                else if(key == 2)
                {
                    std::cout << "Request to ";
                    switch (request.getType()) {
                        case 1: {
                                std::cout << "add UC " << request.getUc() << " in " << request.getName() << "denied"<<std::endl;
                            return false;
                        }
                        case 2: {
                            std::cout << "remove UC " << request.getUc() << " in " << request.getName() << "denied"<<std::endl;
                            return false;
                        }
                        case 3: {
                            std::cout << "switch to class " << request.getAClass() << " in UC " << request.getUc() << " in " << request.getName() << "denied"<<std::endl;
                            return false;
                        }


                    }
                }
                else std::cout <<"INSERT A VALID KEY" << std::endl;

            }

        }
    }
    return false;
}



void Application::checkRequests()
{
    bool exist = true;
    if(requests.empty())
    {
        std::cout << "No requests to process" <<std::endl;
        exist = false;
    }
    //auto show = requests;
    if(exist)
    {
        for(auto it = &requests.front(); it!= &requests.back()+1;it++)
        {
            std::cout << it->getName() << " is trying to " ;
            switch(it->getType())
            {
                case 1:
                {
                    if(it->getKey() == 1) std::cout << "add UC " << it->getUc() << " for class " << it->getAClass() <<std::endl;
                    else std::cout << "add UC " << it->getUc() << " for any class" <<std::endl;
                    break;
                }
                case 2:
                {
                    std::cout << "remove UC " << it->getUc() << std::endl;
                    break;
                }
                case 3:
                {
                    std::cout << "switch to class " << it->getAClass() <<" in UC " << it->getUc() <<std::endl;
                    break;
                }
                default: break;
                    break;
            }
        }

    }

}
bool Application::reverseRequests()
{
    std::ofstream logfile("log.txt");
    int key;
    if(requestsProcessed.empty())
    {
        std::cout << "No requests to revert" <<std::endl;
        return false;

    }
    Request request = requestsProcessed.top();
    requestsProcessed.pop();
    std::cout << request.getName() << " has ";
    switch (request.getType())
    {
        case 1:
        {

            std::cout << "removed " << request.getUc() << " from the schedule. ";
            break;

        }
        case 2:
        {
            std::cout << "added " << request.getUc() << " to the schedule. ";
            break;
        }
        case 3:
        {
            std::cout << "switched from class " << request.getAClass() << " in UC, "<< request.getUc();
            break;
        }

    }
    std::cout << "Do you wanna undo it? " << std::endl;
    std::cout << "¡...............................¡" << std::endl;
    std::cout << "|1. YES                         |" << std::endl;
    std::cout << "|2. NO                          |" << std::endl;
    std::cout << "¡...............................¡" << std::endl;
    std::cin >> key;
    switch (key)
    {
        case 1:
        {
            if(request.getType()==1)
            {
                if(addUC(request.getName(),request.getUc(),request.getAClass(),1,1)) return true;
                std::cout << "Conflicts were created, this action can't be undone" <<std::endl;
                return false;

            }
            if(request.getType() == 2)
            {
                if(removeUC(request.getName(),request.getUc(),1)) return true;
                std::cout << "Conflicts were created, this action can't be undone" <<std::endl;
                return false;

            }
            if(request.getType() == 3)
            {
                if(switchClass(request.getName(),request.getUc(),request.getAClass(),1)) return true;
                std::cout << "Conflicts were created, this action can't be undone" <<std::endl;
                return false;
            }

            break;
        }

        case 2:
        {
            std::cout << "No changes done" << std::endl;
            return false;

        }
        default: break;

    }

return false;
}

