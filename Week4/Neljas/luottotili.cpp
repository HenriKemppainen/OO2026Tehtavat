#include "luottotili.h"


Luottotili::Luottotili(string tilinomistaja, double luotto) : Pankkitili(tilinomistaja)
{
    luottoRaja = -luotto;
    cout << "Luottotili luotu " << tilinomistaja << ":lle, luottoraja "
         << luotto << endl;
}



bool Luottotili::deposit(double talletus){
    if (talletus >= 0 && saldo + talletus <= 0){
        saldo += talletus;
        return true;
    }
    else {
        return false;
    }
}
bool Luottotili::withdraw(double nosto){
    if(saldo-nosto >= luottoRaja && nosto >= 0){
        saldo -= nosto;
        return true;
    }
    else {
        return false;
    }
}
