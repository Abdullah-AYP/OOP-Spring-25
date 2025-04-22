#include "LectureCourse.h"
#include "LabCourse.h"

int main()
{
    LectureCourse c1("CS1004", 3);
    LabCourse c2("CL1004", 1);

    Course* baseptr;

    baseptr = &c1;
    baseptr->displayInfo();
    baseptr->calculateGrade();
    
    baseptr = &c2;
    baseptr->displayInfo();
    baseptr->calculateGrade();
    
    
    return 0;
}
