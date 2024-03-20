#pragma once
#include "student.hpp"
#ifndef roster_hpp
#define roster_hpp
#include <stdio.h>
#endif

class Roster {
private:
    int index = -1;
    
public:
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    
    void parse(string studentData);
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    ~Roster();
};
