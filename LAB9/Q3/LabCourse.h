#ifndef LABCOURSE_H
#define LABCOURSE_H
#include "Course.h"

class LabCourse : public Course {
public:
    LabCourse(string c, int cr) : Course(c, cr) {}
    void calculateGrade() {
        cout << "Calculating grade based on lab reports and attendance...\n";
    }
    void displayInfo() {
        cout << "Lab Course: " << courseCode << " | Credits: " << credits << "\n";
    }
};
#endif
