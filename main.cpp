#include <iostream>
#include <string>
#include <ctime>
#include "cryptex_boss.h"

using namespace std;

// Unlock condition
bool isCryptexUnlocked(bool game1Done,
                       bool game2Done,
                       bool game3Done)
{
    return game1Done && game2Done && game3Done;
}

int main()
{
    srand(time(0)); // seed random once

    bool crosswordDone = false;
    bool wordleDone = false;
    bool louvreDone = false;

    int choice;
    string mode;

    while (true)
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "        ODYSSEY ARCHIVE           " << endl;
        cout << "==================================" << endl;

        cout << "1. Crossword" << endl;
        cout << "2. Wordle" << endl;
        cout << "3. Louvre App" << endl;

        if (isCryptexUnlocked(crosswordDone,
                              wordleDone,
                              louvreDone))
        {
            cout << "4. Curator's Cryptex" << endl;
        }
        else
        {
            cout << "4. Curator's Cryptex (LOCKED)" << endl;
        }

        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Select an option: ";

        cin >> choice;
        cin.ignore();

        if (choice == 0)
        {
            cout << "Exiting program..." << endl;
            break;
        }

        if (choice == 1)
        {
            cout << "Crossword completed." << endl;
            crosswordDone = true;
        }
        else if (choice == 2)
        {
            cout << "Wordle completed." << endl;
            wordleDone = true;
        }
        else if (choice == 3)
        {
            cout << "Louvre App completed." << endl;
            louvreDone = true;
        }
        else if (choice == 4)
        {
            if (isCryptexUnlocked(crosswordDone,
                                  wordleDone,
                                  louvreDone))
            {
                cout << endl;
                cout << "Select difficulty (easy / medium / hard): ";

                getline(cin, mode);

                runCryptexBoss(mode);
            }
            else
            {
                cout << endl;
                cout << "Cryptex is locked." << endl;
                cout << "Complete the other archives first." << endl;
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
