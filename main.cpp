#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Student.h"
#include "StudentsList.h"
#include "Student.h"


using namespace std;
//just making some tests on how to collect the data


int main()
{
    StudentsList students;

    for(auto student:students.getStudents())
    {
        cout << student.getName() << endl;
        for(auto StudentSchedule: student.getStudentSchedule())
        {
            cout << StudentSchedule << " ";

        }

    }
    cout << "-----------------------------------------------------" << endl;
    for(auto ucSchedules: students.getSchedules())
    {
        cout << ucSchedules.getClassForUc().getUcClass() << "->" << ucSchedules.getClassForUc().getUcCode() << endl;
        for (auto info: ucSchedules.getUcClassSchedule())
        {
            cout << info << " ";

        }


    }

    return 0;

}

