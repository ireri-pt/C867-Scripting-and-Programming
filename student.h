//
//  student.h
//  C867_ipete
//
//  Created by Ireri Petersen on 7/14/23.
//

#ifndef student_h
#define student_h

#include <iostream>
using namespace std;
#include <vector>

#include "degree.h"

// Create Student class
class Student {
public:
    // Constructor:
    Student(
        string studentID = "[studentid]",
        string firstName = "[firstname]",
        string lastName = "[lastname]",
        string emailAddress = "[emailaddress]",
        int age = 0,
        vector<int> daysInCourse = {0, 0, 0},
        DegreeProgram degreeProg = NONE
    );
    
    // Destructor:
    ~Student();
    
    // Accessors:
    string GetStudentID() const;
    string GetStudentFirstName() const;
    string GetStudentLastName() const;
    string GetStudentEmail() const;
    int GetStudentAge() const;
    vector<int> GetDaysInCourse() const;
    DegreeProgram GetDegreeProgram() const;
    
    // print individual student information
    void Print();
    
    // Mutators:
    void SetStudentID(string inputID);
    void SetStudentFirstName(string firstName);
    void SetStudentLastName(string lastName);
    void SetStudentEmail(string emailAddress);
    void SetStudentAge(int age);
    void SetDaysInCourse(vector<int> daysInCourse);
    void SetDegreeProgram(DegreeProgram degreeProg);
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    vector<int> daysInCourse;
    DegreeProgram degreeProg;
};

#endif
