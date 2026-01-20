#include "asiakas.h"

Asiakas::Asiakas(string asiakas, double luottoraja) : luottotili(asiakas,luottoraja), kayttotili(asiakas) {
    nimi = asiakas;

    cout << "Asiakkuus luotu " << asiakas << endl;
    cout << "Pankkitili luotu " << asiakas << ":lle" << endl;
    cout << "Luottotili luotu " << asiakas << ":lle, luottoraja "
         << luottoraja << endl;
}


string Asiakas::getNimi(){
    return nimi;
}
void Asiakas::showSaldo(){
    cout << getNimi() << " Kayttotilin saldo: " << kayttotili.getBalance() << endl;
    cout << getNimi() << " Luottotilin saldo: " << luottotili.getBalance() << endl;

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

bool Asiakas::tiliSiirto(double summa, Asiakas &vastaanottaja)
{   cout << getNimi() << " siirtaa " << summa << " " << vastaanottaja.getNimi() << ":lle" << endl;
    cout << getNimi() << " ";

    kayttotili.withdraw(summa);
    cout << vastaanottaja.getNimi() << " ";
    vastaanottaja.tallennus(summa);
    return true;
    }
   // return false;
//}
