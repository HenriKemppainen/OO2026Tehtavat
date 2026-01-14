#include "italianchef.h"


ItalianChef::ItalianChef(std::string kokki) : Chef(kokki)
{
    std::cout << "Italian" << getName() << " konstruktori" << std::endl;

}

ItalianChef::~ItalianChef()
{
    std::cout << "Italian" << getName() << " destruktori" << std::endl;
}

bool ItalianChef::askSecret(std::string salasana,int jauhot,int vesi)
{
    if (salasana == "pizza")   
    {
        std::cout << "Password ok!" << std::endl;
        std::cout << "Italian" << getName() << " with " << jauhot << " flour and " << vesi << " water can make ";
        int pizza = makepizza(jauhot,vesi);
        std::cout << pizza << " pizzas" << std::endl;
        return true;
    }
    return false;

}
int ItalianChef::makepizza(int jauho, int vesi)
{
    return std::min(jauho/5,vesi/5);

}
