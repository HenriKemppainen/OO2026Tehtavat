#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>




Game::Game(int m)
{
    maxNumber = m;
    std::srand(time(0));
    std::cout << "GAME CONSTRUCTOR: object initialized with " << m << " as a maximum value" << std::endl ;
    randomNumber = (std::rand() % m)+1;
    numOfGuesses = 0;
    play();


}


Game::~Game()
{
    numOfGuesses = 0;
}


void Game::play()
{

    while(1)
    {
        std::cout << "Give your guess between 1-" << maxNumber << std::endl;
        std::cin >> playerGuess;
        std::cin.ignore(1000, '\n');
        numOfGuesses++;
        if(playerGuess == randomNumber)
        {
            printGameResult();
            break;

        }

        else if (playerGuess < randomNumber)
        {
            std::cout << "Your Guess is too small" << std::endl;
        }
        else if (playerGuess > randomNumber)
        {
            std::cout << "Your Guess is too big" << std::endl;
        }
    }
}




void Game::printGameResult()
{
    std::cout << "Your guess is right " << randomNumber;
    std::cout << " with " << numOfGuesses << " guesses" << std::endl;
}
