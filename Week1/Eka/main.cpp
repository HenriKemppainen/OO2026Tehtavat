#include <iostream>

#include <cstdlib>
#include <ctime>



int game(int maxnum)
{
    int arvaus;
    int arvausten_maara = 0;
    int etsittava_luku = (std::rand() % maxnum)+1;
    while(1)
    {
        std::cout << "Arvaus: ";
        std::cin >> arvaus;
        std::cin.ignore(1000, '\n');
        arvausten_maara++;
        if(arvaus == etsittava_luku)
        {
            std::cout << "oikein" << std::endl;
            std::cout << "Arvausten lukumaara: ";
            return arvausten_maara;
        }

        else if (arvaus < etsittava_luku)
        {
            std::cout << "liian pieni" << std::endl;
        }
        else if (arvaus > etsittava_luku)
        {
            std::cout << "liian suuri" << std::endl;
        }

    }
}




int main()
{
    int maxluku;
    std::srand(std::time(0));
    std::cout << "Anna max luku" << std::endl;
    std::cin >> maxluku;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << game(maxluku) << std::endl;


    return 0;

}



