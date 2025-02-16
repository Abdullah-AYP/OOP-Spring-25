#include <iostream>
using namespace std;

class FitnessTracker {
public:
    string userName;
    int dailyGoal;
    int stepsTaken;
    double caloriesBurned;

    FitnessTracker(string name, int stepGoal) {
        userName = name;
        dailyGoal = stepGoal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }
    void logSteps(int steps) {
        stepsTaken = stepsTaken+steps;
        caloriesBurned = caloriesBurned + (steps * 0.04); 
    }
    void displayProgress() {
        cout << "\nUser: " << userName << endl;
        cout << "Steps Taken: " << stepsTaken << " / " << dailyGoal << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;
        if (stepsTaken >= dailyGoal)
            cout << "Goal Achieved!\n";
        else
            cout << "Keep Trying!\n";
    }
};
int main() {
 FitnessTracker tracker("Laiba", 2000);
 tracker.logSteps(2501);
 tracker.displayProgress();
 return 0;
}
