#include <iostream>
using namespace std;

const int MAX_LEVELS = 20;

class Level {
private:
    string name;
    string difficulty;
    string description;

public:
    Level(string levelN, string levelDiff, string levelDes) {
        name = levelN;
        difficulty = levelDiff;
        description = levelDes;
    }
    void displayInfo() {
        cout << name << " (Difficulty: " << difficulty << ") - " << description;
    }
    ~Level() {
        cout << "Level '" << name << "' is being destroyed" << endl;
    }
};
class VideoGame {
private:
    string title;
    string genre;
    Level* levels[MAX_LEVELS];
    int levelCount;

public:
    VideoGame(string gameT, string gameG) {
        title = gameT;
        genre = gameG;
        levelCount = 0;
    }
    Level* addLevel(string name, string difficulty, string description) {
        if (levelCount < MAX_LEVELS) {
            levels[levelCount] = new Level(name, difficulty, description);
            return levels[levelCount++];
        }
        return nullptr;
    }
    void displayDetails() {
        cout << "Game: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Game Levels:" << endl;
        
        if (levelCount == 0) {
            cout << "  No levels created yet" << endl;
        } else {
            for (int i = 0; i < levelCount; i++) {
                cout << "  " << (i + 1) << ". ";
                levels[i]->displayInfo();
                cout << endl;
            }
        }
        cout << endl;
    }
    ~VideoGame() {
        cout << "Game '" << title << "' is being destroyed along with its levels" << endl;
        for (int i = 0; i < levelCount; i++) {
            delete levels[i];
        }
    }
};
int main() {
    VideoGame IGI("Im Going In", "Adventure/Shooting");
    
    IGI.addLevel("Trainyard", "Easy", "Introduction to game mechanics");
    IGI.addLevel("Defend Priboi", "Medium", "Navigate through and save Priboi");
    IGI.addLevel("Nuclear Infiltration", "Hard", "Destroy the major nuclear plant");
    IGI.addLevel("Finding the Bomb", "Very Hard", "FInal Chapter");
    IGI.displayDetails();
    
    cout << "Program ending, game will be destroyed...\n" << endl;
    return 0;
}

