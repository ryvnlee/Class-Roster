#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
#ifndef student_hpp
#define student_hpp
#include <stdio.h>
#endif

using std::string;
using std::cout;
using std::endl;

class Student {
public:
    const static int daysInCourseSize = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[daysInCourseSize];
    DegreeProgram degreeProgram;
    
public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    ~Student();
    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    static void printHeader();
    
    void print();
};
