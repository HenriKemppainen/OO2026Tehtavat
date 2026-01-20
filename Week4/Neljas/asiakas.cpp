#include "asiakas.h"

Asiakas::Asiakas(string asiakas, double luottoraja) : luottotili(asiakas,luottoraja), kayttotili(asiakas) {
    nimi = asiakas;
}


string Asiakas::getNimi(){
    return nimi;
}
void Asiakas::showSaldo(){
    cout << luottotili.getBalance() << endl;
    cout << kayttotili.getBalance() << endl;
}
bool Asiakas::tallennus(double talletus){
    return kayttotili.deposit(talletus);
}
bool Asiakas::nosto(double nosto){
    return kayttotili.withdraw(nosto);
}
bool Asiakas::luotonMaksu(double talletus){
    return luottotili.deposit(talletus);
}
bool Asiakas::luotonNosto(double nosto){
    return luottotili.withdraw(nosto);
}
