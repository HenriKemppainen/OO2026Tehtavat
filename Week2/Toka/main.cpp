#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    int count;
    std::cout << "Give max number" << std::endl;
    std::cin >> count;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    // Täällä luodaan uusi game-olio ja ajetaan peli
    Game uusipeli(count);
    return 0;
}
