#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();

public:
    Game(int max);
    ~Game();
    void play();
};

#endif
