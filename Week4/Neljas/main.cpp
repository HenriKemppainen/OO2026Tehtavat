#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    Asiakas pena("Pena", 500);
    pena.luotonNosto(360);
    pena.luotonMaksu(100);
    pena.showSaldo();

    Asiakas sirpa("Sirpa",200);
    sirpa.tallennus(400);
    sirpa.tiliSiirto(250, pena);

    sirpa.showSaldo();
    pena.showSaldo();

    return 0;
}
