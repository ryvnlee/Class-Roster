#include "roster.hpp"
#include "student.hpp"
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;
using std::string;
using std::cout;
using std::stoi;
using std::endl;

void Roster::parse(string studentData){
    long rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    long lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeProgramStrings = studentData.substr(lhs, rhs - lhs);
    
    DegreeProgram degreeProgram = SECURITY;
    if (degreeProgramStrings == "SECURITY"){
        degreeProgram = SECURITY;
    }
    else if (degreeProgramStrings == "NETWORK"){
        degreeProgram = NETWORK;
    }
    else if (degreeProgramStrings == "SOFTWARE"){
        degreeProgram = SOFTWARE;
    }
    
    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    int daysInCourse[Student::daysInCourseSize] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++index] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

void Roster::remove(string studentID){
    bool success = false;
    for (int i = 0; i <= Roster::index; i++){
        if (classRosterArray[i]->getStudentID() == studentID){
            success = true;
            if (i < numStudents - 1){
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::index--;
        }
    }
    if (success){
        cout << studentID << " has been removed" << endl;
        this->printAll();
    }
    else {
        cout << studentID << " was not found" << endl;
    }
}


void Roster::printAll(){
    for (int i = 0; i <= Roster::index; i++){
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i <= Roster::index; i++){
        if (classRosterArray[i]->getStudentID() == studentID){
            cout << studentID << " | ";
            cout << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3;
            cout << endl;
        }
    }
}

void Roster::printInvalidEmails(){
    bool invalid = false;
    for (int i = 0; i <= Roster::index; i++){
        string email = classRosterArray[i]->getEmail();
        string studentID = classRosterArray[i]->getStudentID();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos){
            invalid = true;
            cout << studentID << " | " << email << endl;
        }
        else if (!invalid){
            cout << "There are no invalid email addresses" << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for (int i = 0; i <= Roster::index; i++){
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

Roster::~Roster(){
    for (int i = 0; i < numStudents; i++){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
