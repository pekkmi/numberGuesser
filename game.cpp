#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int maxN) {
    maxNumber = maxN;
    numOfGuesses = 0;
    srand(time(0));

}

Game::~Game() {

}

void Game::play() {

   // bool stayInLoop = true;
    randomNumber = (rand()%maxNumber)+1;
    playerGuess = 0;
    numOfGuesses = 0;

    while(true) {

        cout << "Try to guess a number i am thinkin of between 1 and " << maxNumber << endl;
        cin >> playerGuess; cout << endl;
        numOfGuesses++;
        if (playerGuess == randomNumber) {
            cout << "You are right! The number indeed was " << playerGuess << endl << endl;
          //  stayInLoop = false;
            break;
        } if (playerGuess < 0 || playerGuess > maxNumber) {
            cout << "Invalid input! Try again" << endl;
        }

        if (playerGuess < randomNumber) {
            cout << "The number i am thinkin of is larger than the one you guessed. Try again" << endl;
        } if (playerGuess > randomNumber) {
            cout << "The number i am thinking of is smaller than the one you guessed. Try again" << endl;
            }

    }
    printGameResult();
    startNewGame();
}

void Game::printGameResult() {
    cout << "#################################" << endl;
    cout << "HERE ARE THE RESULTS OF THE GAME:" << endl;
    cout << "You guessed the right number " << playerGuess << "." << endl;
    cout << "Amount of guesses used: " << numOfGuesses << "." << endl;
    cout << "#################################" << endl << endl;
}

void Game::startNewGame() {
    cout << "Do you want to play a new game? Y/N" << endl;
    cin >> newGame; cout << endl;

    if (newGame == 'y' || newGame == 'Y') {
        return Game::play();
    }else if (newGame == 'n' || newGame =='N') {
        return;
    }else {
        cout << "Invalid input. Choos Y/N!" << endl;
        return Game::startNewGame();
    }
}
