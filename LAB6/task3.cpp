#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}  

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Teacher : virtual public Person {
protected:
    string subject;
public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}  

    void displayDetails(){
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};
class Researcher : virtual public Person {
protected:
    string researchArea;
public:
    Researcher(string n, int a, string r) : Person(n, a), researchArea(r) {} 

    void displayDetails(){
        cout << "Name: " << name << ", Age: " << age << ", Research Area: " << researchArea << endl;
    }
};
class Professor : public Teacher, public Researcher {
private:
    int publications;
public:
    Professor(string n, int a, string s, string r, int p) : Person(n, a), Teacher(n, a, s), Researcher(n, a, r), publications(p) {}  

    void displayDetails(){
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << ", Research Area: " << researchArea << ", Publications: " << publications << endl;
    }
};
int main() {
    Professor p("Prof. Abdullah", 19, "Computer Science", "Data Science", 69);
    p.displayDetails();

    return 0;
}

