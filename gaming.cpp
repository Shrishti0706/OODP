#include <iostream>
using namespace std;

class GamingAccount {
private:
    string playerName;
    int level;
    int experience;
    const int LEVEL_THRESHOLD = 100;

public:
    GamingAccount() : playerName("Unknown"), level(1), experience(0) {}

    GamingAccount(string name, int lvl, int exp) : playerName(name), level(lvl), experience(exp) {}

    void gainExperience(int points) {
        experience += points;
        while (experience >= LEVEL_THRESHOLD) {
            experience -= LEVEL_THRESHOLD;
            level++;
            cout << playerName << " leveled up to " << level << "!\n";
        }
    }

    void showStats() {
        cout << "Player: " << playerName << ", Level: " << level << ", Experience: " << experience << endl;
    }

    bool operator>(GamingAccount other) {
        if (level == other.level) {
            return experience > other.experience;
        }
        return level > other.level;
    }

    string getPlayerName() {
        return playerName;
    }
};

int main() {
    GamingAccount player1("Alice", 1, 50);
    GamingAccount player2("Bob", 2, 20);

    player1.gainExperience(60);
    player2.gainExperience(30);

    player1.showStats();
    player2.showStats();

    if (player1 > player2) {
        cout << player1.getPlayerName() << " is stronger than " << player2.getPlayerName() << "!\n";
    } else {
        cout << player2.getPlayerName() << " is stronger than " << player1.getPlayerName() << "!\n";
    }

    return 0;
}
