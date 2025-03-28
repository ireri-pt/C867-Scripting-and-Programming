//
//  Roster.h
//  C867_ipete
//
//  Created by Ireri Petersen on 7/24/23.
//

#ifndef Roster_h
#define Roster_h

#include <iostream>
using namespace std;
#include <vector>

#include "student.h"

class Roster {
public:
    // array of pointers for data provided in studentData table
    vector<Student*> classRosterArray;
    
    // constructor
    Roster();
    
    // destructor
    ~Roster();
    
    // Mutators:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprog);
    void remove(string studentID);
    
    // Print functions:
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProg);
    
};

#endif /* Roster_h */
