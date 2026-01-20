#include "luottotili.h"


Luottotili::Luottotili(string tilinomistaja, double luotto) : Pankkitili(tilinomistaja)
{
    luottoRaja = -luotto;
    saldo = luotto;

}



bool Luottotili::deposit(double talletus){
    if (talletus >= 0 && saldo + talletus <= 0){
        saldo += talletus;
        cout  << "Luottotili: talletus: " << talletus << " tehty" << endl;
        return true;
    }
    else {
        return false;
    }
}
bool Luottotili::withdraw(double nosto){
    if(saldo-nosto >= luottoRaja && nosto >= 0){
        saldo -= nosto;
        cout << "Luottotili: nosto: " << nosto << " tehty, luottoa jaljella " << saldo << endl;
        return true;
    }
    else {
        return false;
    }
}
