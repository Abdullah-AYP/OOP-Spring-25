#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
private:
    string playlist[69]; 
    int songCount;
    string currentlyPlaying;

public:
    MusicPlayer() {
        songCount = 0;
        currentlyPlaying = "None";
    }
    void addSong(const string &song) {
        if (songCount < 69) {
            playlist[songCount] = song;
            songCount++;
            cout << "Song added: " << song << endl;
        } else {
            cout << "Playlist is full!" << endl;
        }
    }
    void removeSong(const string &song) {
        bool found = false;
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == song) {
                found = true;
                for (int j = i; j < songCount - 1; j++) {
                    playlist[j] = playlist[j + 1];
                }
                songCount--;
                cout << "Song removed: " << song << endl;
                break;
            }
        }
        if (!found) {
            cout << "Song not found in playlist." << endl;
        }
    }
    void playSong(const string &song) {
        bool found = false;
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == song) {
                found = true;
                currentlyPlaying = song;
                cout << "Now playing: " << song << endl;
                break;
            }
        }
        if (!found) {
            cout << "Song not found in playlist." << endl;
        }
    }
    void displayPlaylist() {
        if (songCount == 0) {
            cout << "Playlist is empty." << endl;
        } else {
            cout << "Playlist: " << endl;
            for (int i = 0; i < songCount; i++) {
                cout << i + 1 << ". " << playlist[i] << endl;
            }
        }
    }
};
int main() {
    MusicPlayer player;
    int choice;
    string song;

    do {
        cout << "\n1. Add Song\n2. Remove Song\n3. Play Song\n4. Display Playlist\n5. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter song to add: ";
                getline(cin, song);
                player.addSong(song);
                break;

            case 2:
                cout << "Enter song to remove: ";
                getline(cin, song);
                player.removeSong(song);
                break;

            case 3:
                cout << "Enter song to play: ";
                getline(cin, song);
                player.playSong(song);
                break;

            case 4:
                player.displayPlaylist();
                break;

            case 5:
                cout << "Exiting Music Player......" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

