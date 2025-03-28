//
//  student.cpp
//  C867_ipete
//
//  Created by Ireri Petersen on 7/14/23.
//
#include <iostream>
using namespace std;
#include <vector>

#include "student.h"

// Constructor function:
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
    int age, vector<int> daysInCourse, DegreeProgram degreeProg) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse = daysInCourse;
    this->degreeProg = degreeProg;
}

// Accessor function definitions:
string Student::GetStudentID() const {
    return studentID;
}

string Student::GetStudentFirstName() const {
    return firstName;
}

string Student::GetStudentLastName() const {
    return lastName;
}

string Student::GetStudentEmail() const{
    return emailAddress;
}

int Student::GetStudentAge() const {
    return age;
}

vector<int> Student::GetDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProg;
}

// print function definition
void Student::Print() {
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    
    cout << "daysInCourse: " << "{";
    for (int i = 0; i < daysInCourse.size(); ++i) {
        if (i != daysInCourse.size() - 1) {
            cout << daysInCourse.at(i) << ", ";
        }
        else {
            cout << daysInCourse.at(i);
        }
        
    }
    
    cout << "}" << "\t";
    
    switch (degreeProg) {
        case 0:
            cout << "Degree Program: " << "SECURITY";
            break;
        case 1:
            cout << "Degree Program: " << "NETWORK";
            break;
        case 2:
            cout << "Degree Program: " << "SOFTWARE";
            break;
        case 3:
            cout << "Degree Program: " << "NONE";
            break;
    }
    cout << endl;
}


// Mutator function definitions:
void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::SetStudentFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::SetStudentLastName(string lastName) {
    this->lastName = lastName;
}

void Student::SetStudentEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::SetStudentAge(int age) {
    this->age = age;
}

void Student::SetDaysInCourse(vector<int> daysInCourse) {
    this->daysInCourse = daysInCourse;
}

void Student::SetDegreeProgram(DegreeProgram degreeProg) {
    this->degreeProg = degreeProg;
}

// Destructor function
Student::~Student() {}
