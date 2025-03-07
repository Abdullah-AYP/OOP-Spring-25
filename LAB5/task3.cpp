#include <iostream>
using namespace std;

class Project;

class Employee {
private:
    string name;
    string designation;
    Project* projects[10];
    int projectCount;

public:
    Employee(string empN, string empD) {
        name = empN;
        designation = empD;
        projectCount = 0;
    }
    void assignToProject(Project* project);
    void displayInfo();
    
    string getName(){
         return name;
         }
    string getDesignation(){
         return designation;
         }
};
class Project {
private:
    string title;
    string deadline;
    Employee* employees[50];
    int employeeCount;

public:
    Project(string projT, string projD) {
        title = projT;
        deadline = projD;
        employeeCount = 0;
    }
    void addEmployee(Employee* employee) {
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i] == employee) {
                return; 
            }
        }
        if (employeeCount < 50) {
            employees[employeeCount++] = employee;
        }
    }
    void displayDetails() {
        cout << "Project: " << title << ", Deadline: " << deadline << endl;
        cout << "Assigned Employees:" << endl;

        if (employeeCount == 0) {
            cout << "  No employees assigned yet" << endl;
        } else {
            for (int i = 0; i < employeeCount; i++) {
                cout << "  - " << employees[i]->getName() << " (" 
                     << employees[i]->getDesignation() << ")" << endl;
            }
        }
        cout << endl;
    }
    string getTitle(){ 
        return title;}
    string getDeadline(){ 
        return deadline;}
};
void Employee::assignToProject(Project* project) {
    for (int i = 0; i < projectCount; i++) {
        if (projects[i] == project) {
            return; 
        }
    }
    if (projectCount < 10) {
        projects[projectCount++] = project;
        project->addEmployee(this);
    }
}
void Employee::displayInfo() {
    cout << "Employee: " << name << ", Designation: " << designation << endl;
    cout << "Assigned Projects:" << endl;

    if (projectCount == 0) {
        cout << "  No projects assigned yet" << endl;
    } else {
        for (int i = 0; i < projectCount; i++) {
            cout << "  - " << projects[i]->getTitle() << " (Deadline: " 
                 << projects[i]->getDeadline() << ")" << endl;
        }
    }
    cout << endl;
}
int main() {
   
    Employee abdullah("Abdullah", "Data Scientist");
    Employee hassan("Hassan Ahmed", "Software Developer");
    Employee faiiz("Faiiz Farhad", "Project Manager");
    
    Project research("Research Project", "2025-03-30");
    Project app("Mobile App Development", "2025-06-30");
 
    abdullah.assignToProject(&research);
    abdullah.assignToProject(&app);  
    faiiz.assignToProject(&research);
    hassan.assignToProject(&app);
 
    cout << "==== EMPLOYEE INFORMATION ====" << endl;
    abdullah.displayInfo();
    hassan.displayInfo();
    faiiz.displayInfo();
    
    cout << "==== PROJECT DETAILS ====" << endl;
    research.displayDetails();
    app.displayDetails();
    
    return 0;
}

