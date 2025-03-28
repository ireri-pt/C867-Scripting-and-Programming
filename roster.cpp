//
//  roster.cpp
//  C867_ipete
//
//  Created by Ireri Petersen on 7/14/23.
//
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cctype>

#include "degree.h"
#include "student.h"
#include "Roster.h"


// constructor
Roster::Roster() {}

// destructor
Roster::~Roster() {
    for (int i = 0; i < classRosterArray.size(); ++i) {
        delete classRosterArray.at(i);
    }
    
}

// Mutators:
void Roster::add(
         string studentID,
         string firstName,
         string lastName,
         string emailAddress,
         int age,
         int daysInCourse1, int daysInCourse2, int daysInCourse3,
         DegreeProgram degreeProg) {
    vector<int> daysInCourse{daysInCourse1, daysInCourse2, daysInCourse3};
    Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProg);
    classRosterArray.push_back(newStudent);
}

void Roster::remove(string studentID) {
    bool foundStudent = false;
    cout << "Remove: " << studentID << endl;
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (studentID == classRosterArray.at(i)->GetStudentID()) {
            foundStudent = true;
            delete classRosterArray.at(i);
            classRosterArray.erase(classRosterArray.begin() + i);
            cout << studentID << " was successfully removed." << endl;
        }
        
    }
    
    if (!foundStudent) {
        cout << studentID << " was not found." << endl;
    }
    
}

// Print functions:
void Roster::printAll() {
    cout << "All students:" << endl;
    for (int i = 0; i < classRosterArray.size(); ++i) {
        classRosterArray.at(i)->Print();
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    cout << "The average for " << studentID << " is ";
    int averageDaysTotal = 0;
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (studentID == classRosterArray.at(i)->GetStudentID()) {
            vector<int> avgDays = classRosterArray.at(i)->GetDaysInCourse();
            for (int ii = 0; ii < avgDays.size(); ++ii) {
                averageDaysTotal = averageDaysTotal + avgDays.at(ii);
            }
            cout << averageDaysTotal / avgDays.size() << endl;
        }
        
    }
    
}

void Roster::printInvalidEmails() {
    cout << "Invalid emails:" << endl;
    string currEmail;
    // valid email should include an at sign ('@') and period ('.') and should not include any spaces.
    for (int i = 0; i < classRosterArray.size(); ++i) {
        currEmail = classRosterArray.at(i)->GetStudentEmail();
        bool hasSpace = false;
        bool hasAtSign = false;
        bool hasPeriod = false;
        bool isValidEmail = false;
        
        for (int i = 0; i < currEmail.length(); ++i) {
            if (currEmail.at(i) == '@') {
                hasAtSign = true;
            }
            
            if (currEmail.at(i) == '.') {
                hasPeriod = true;
            }
            
            if (isspace(currEmail.at(i))) {
                hasSpace = true;
            }
            
            if (i == currEmail.length() - 1) {
                if (hasAtSign && hasPeriod && (!hasSpace)) {
                    isValidEmail = true;
                }
                else {
                    // isValidEmail = false;
                    cout << currEmail << endl;
                }
                
            }
            
        }
        
    }
    
}

void Roster::printByDegreeProgram(DegreeProgram degreeProg) {
    cout << "Degree program: ";
    
    if (degreeProg == SECURITY) {
        cout << "SECURITY" << endl;
    }
    else if (degreeProg == NETWORK) {
        cout << "NETWORK" << endl;
    }
    else if (degreeProg == SOFTWARE) {
        cout << "SOFTWARE" << endl;
    }
    else if (degreeProg == NONE) {
        cout << "NONE" << endl;
    }
    
    for (int i = 0; i < classRosterArray.size(); ++i) {
        if (classRosterArray.at(i)->GetDegreeProgram() == degreeProg) {
            classRosterArray.at(i)->Print();
        }
        
    }
    
}

