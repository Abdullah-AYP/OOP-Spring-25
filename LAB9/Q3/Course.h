#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;
public:
    Course(string c, int cr) : courseCode(c), credits(cr) {}
    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;
};
#endif
