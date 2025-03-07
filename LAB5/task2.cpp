#include <iostream>
using namespace std;

class Student {
private:
    int id;
    char name[50];
    int* scores;
    int numScores;

public:
    Student(int id, const char* name, int numScores, int* scoresArray) {
        this->id = id;

        int i;
        for (i = 0; name[i] != '\0' && i < 49; i++) {
            this->name[i] = name[i];
        }
        this->name[i] = '\0';  

        this->numScores = numScores;
        
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = scoresArray[i];
        }
    }
    Student(const Student& other) {
        id = other.id;

        int i;
        for (i = 0; other.name[i] != '\0' && i < 49; i++) {
            name[i] = other.name[i];
        }
        name[i] = '\0';

        numScores = other.numScores;

        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
    }
    void display() {
        cout << "ID: " << id << "\nName: " << name << "\nScores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }
    ~Student() {
        delete[] scores;
    }
};
int main() {
    int scores1[] = {22,99,50,100,91,49};  
    Student s1(822, "Abdullah", 6, scores1);
    
    cout << "Original Student:\n";
    s1.display();
    Student s2 = s1;
    cout << "\nCopied Student:\n";
    s2.display();

    return 0;
}

