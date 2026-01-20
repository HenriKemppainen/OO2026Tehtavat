#include "asiakas.h"

Asiakas::Asiakas(string asiakas, double luottoraja) {
    nimi = asiakas;



}


string Asiakas::getNimi(){
    return nimi;
}
void Asiakas::showSaldo(){
    cout << Luottotili.saldo << endl;
    cout << Pankkitili.saldo << endl;
}
bool Asiakas::tallennus(double talletus){
    return Pankkitili.deposit(talletus);
}
bool Asiakas::nosto(double nosto){
    return Pankkitili.withdraw(nosto);
}
bool Asiakas::luotonMaksu(double talletus){
    return Luottotili.deposit(talletus);
}
bool Asiakas::luotonNosto(double nosto){
    return Luottotili.withdraw(nosto);
}
