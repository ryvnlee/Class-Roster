#include "student.hpp"

Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseSize; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram){
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student(){}

string Student::getStudentID(){return this->studentID;}
string Student::getFirstName(){return this->firstName;}
string Student::getLastName(){return this->lastName;}
string Student::getEmail(){return this->email;}
int Student::getAge(){return this->age;}
int* Student::getDaysInCourse(){return this->daysInCourse;}
DegreeProgram Student::getDegreeProgram(){return this->degreeProgram;}

void Student::setStudentID(string ID){this->studentID = ID;}
void Student::setFirstName(string firstName){this->firstName = firstName;}
void Student::setLastName(string lastName){this->lastName = lastName;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){this->age = age;}
void Student::setDaysInCourse(int daysInCourse[]){
    for (int i = 0; i < daysInCourseSize; i++)this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram dp){this->degreeProgram = dp;}

void Student::print(){
    cout << this->getStudentID() << "\t";
    cout << "First name: " << this->getFirstName() << "\t";
    cout << "Last name: " << this->getLastName() << "\t";
    cout << "Age: " << this->getAge() << "\t";
    cout << "Days in course: {" << this->getDaysInCourse()[0] << ",";
    cout << this->getDaysInCourse()[1] << ",";
    cout << this->getDaysInCourse()[2] << "}\t";
    cout << "Degree program: " << degreeProgramStrings[this->getDegreeProgram()] << endl;
}
