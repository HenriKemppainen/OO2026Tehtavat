#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <ctime>


class Game
{
public:
    Game(int);
    ~Game();
    void play();

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();
protected:
};

#endif // GAME_H
