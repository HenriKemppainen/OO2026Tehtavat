#include <iostream>
#include "chef.h"
#include "italianchef.h"


using namespace std;

int main()
{
    int salad;
    int soup;
    string kokki1;
    cout << "Syota kokin nimi: ";
    cin >> kokki1;
    std::cin.ignore(1000, '\n');
    Chef kokki(kokki1);
    cout << "Syota salaattitarvikkeiden maara" << endl;
    std::cout << kokki.getName() << " with ";
    std::cin >> salad;
    std::cin.ignore(1000, '\n');
    std::cout << "items can make salad " << kokki.makeSalad(salad) << " portions" << std::endl;

    cout << "Syota soppatarvikkeiden maara" << endl;
    std::cout << kokki.getName() << " with ";
    std::cin >> soup;
    std::cin.ignore(1000, '\n');
    std::cout << "items can make soup " << kokki.makeSalad(soup) << " portions" << std::endl;

    string kokki2;
    cout << "Syota italialaisen kokin nimi: ";
    cin >> kokki2;
    std::cin.ignore(1000, '\n');
    ItalianChef italiankokki(kokki2);
    std::cout << "Syotä salasana: ";
    std::string password;
    std::cin >> password;

    int flour;
    int water;

    std::cout << "jauhojen maara ";
    std::cin >> flour;
    std::cin.ignore(1000, '\n');


    std::cout << "veden maara ";
    std::cin >> water;
    std::cin.ignore(1000, '\n');

    italiankokki.askSecret(password,flour,water);
}
