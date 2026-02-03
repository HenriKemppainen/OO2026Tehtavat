#include "seuraaja.h"

Seuraaja::Seuraaja(string seuraajan_nimi) {
    nimi = seuraajan_nimi;
    cout << "Luodaan seuraaja " << nimi << endl;
}

string Seuraaja::getNimi(){
    return nimi;
}


void Seuraaja::paivitys(string viesti)
{
    cout << "Seuraaja " << getNimi() << " sai viestin " << viesti << endl;
}
