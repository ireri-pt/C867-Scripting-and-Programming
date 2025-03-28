//
//  main.cpp
//  C867_ipete
//
//  Created by Ireri Petersen on 7/13/23.
//

#include <iostream>
#include <string>
using namespace std;

// include necessary files
#include "degree.h"
#include "student.h"
#include "Roster.h"

int main() {
    // Output course title, programming language, student ID, and name
    cout << "Course: C867 (Scripting and Programming Applications)" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 002030046" << endl;
    cout << "Name: Ireri Petersen" << endl;
    cout << endl;
    
    // Create classRoster
    Roster classRoster;
    
    // studentData table
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Ireri,Petersen,ipete19@wgu.edu,25,30,59,35,SOFTWARE"};
    
    // Add each student to classRoster    
    classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.add("A5", "Ireri", "Petersen", "ipete19@wgu.edu", 25, 30, 59, 35, SOFTWARE);
    
    // All students
    classRoster.printAll();
    
    // Invalid emails
    classRoster.printInvalidEmails();
    cout << endl;
    
    // Average days in course
    cout << "Average days in course: " << endl;
    for (int i = 0; i < classRoster.classRosterArray.size(); ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray.at(i)->GetStudentID());
    }
    cout << endl;
    
    // Degree Program: SOFTWARE
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    // Remove: A3
    classRoster.remove("A3");
    cout << endl;
    
    // Print remaining students in roster
    classRoster.printAll();
    
    // Try removing A3 again
    classRoster.remove("A3");
    cout << endl;
    
    return 0;
}
