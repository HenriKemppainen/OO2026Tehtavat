#include "chef.h"
#include "italianchef.h"
#include <iostream>


Chef::Chef(std::string syote)
{

    chefName = syote;
    std::cout << getName() << " konstruktori" << std::endl;

}

Chef::~Chef() {

    std::cout << getName() << " dekonstruktori" << std::endl;
}


int Chef::makeSalad(int salaatti)
{
    return salaatti/5;
}

int Chef::makeSoup(int keitto)
{
    return keitto/3;
}

std::string Chef::getName()
{
    return "Chef " + chefName;
}
