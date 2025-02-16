#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int maxN);
    ~Game();
    void play();

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
    void printGameResult();
    void startNewGame();
    char newGame;
};

#endif // GAME_H
