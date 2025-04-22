#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H
#include "Course.h"

class LectureCourse : public Course {
public:
    LectureCourse(string c, int cr) : Course(c, cr) {}
    void calculateGrade() {
        cout << "Calculating grade based on theory exams...\n";
    }
    void displayInfo() {
        cout << "Lecture Course: " << courseCode << " | Credits: " << credits << "\n";
    }
};
#endif
