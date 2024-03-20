#include <iostream>
#include <string>
#include "roster.hpp"
using namespace std;
using std::endl;
using std::string;

int main(){
    cout << "Scripting and Programming - Applications (C867) | C++ | Student ID: 011225983 | Ryan Lee" << endl;
    cout << endl;
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ryan,Lee,rlee388@wgu.edu,25,30,35,50,SOFTWARE"
    };
    
    const int numStudents = 5;
    Roster classRoster;
    
    for (int i = 0; i < numStudents; i++){
        classRoster.parse(studentData[i]);
    }
    
    classRoster.printAll();
    cout << endl;
    
    cout << "Invalid email addresses:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    cout << "Average days in course:" << endl;
    for (int i = 0; i < numStudents; i++){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;
    
    cout << "Software students:" << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    classRoster.remove("A3");
    cout << endl;
    
    classRoster.printAll();
    cout << endl;
    
    classRoster.remove("A3");
    cout << endl;
    
    system("pause");
    return 0;
}
