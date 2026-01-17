#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int max) {
    cout << "konstruktori kutsuttu" << endl;
    maxNumber = max;
    numOfGuesses = 0;
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    //cout << "maxNumber asetettu arvoon " << maxNumber << endl;
    //cout << "randomNumber arvottu: " << randomNumber << endl;
}

Game::~Game() {

}

void Game::play() {
    cout << "peli aloitettu" << endl;
    playerGuess = -1;
    do {
        cout << "Arvaa luku (1-" << maxNumber << "): ";
        cin >> playerGuess;
        numOfGuesses++;

        cout << "Pelaajan arvaus: " << playerGuess << endl;
        cout << "Arvauskerrat: " << numOfGuesses << endl;

        if (playerGuess < randomNumber) {
            cout << "Liian pieni" << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Liian suuri" << endl;
        } else {
            cout << "Oikein!" << endl;
        }

    } while (playerGuess != randomNumber);
    cout << "Peli loppui" << endl;
    printGameResult();
}

void Game::printGameResult() {
    cout << "Oikea luku oli: " << randomNumber << endl;
    cout << "Arvauksia yhteensa: " << numOfGuesses << endl;
}
