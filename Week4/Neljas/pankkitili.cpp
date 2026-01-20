#include "pankkitili.h"

Pankkitili::Pankkitili(string nimi) {
    omistaja = nimi;
    cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
}


double Pankkitili::getBalance(){
    return saldo;
}

bool Pankkitili::deposit(double talletus){
    if (talletus >= 0){
            saldo += talletus;
            return true;
    }
    else {
        return false;
    }
}
bool Pankkitili::withdraw(double nosto){
    if(saldo-nosto >= 0 && nosto >= 0){
        saldo -= nosto;
        return true;
    }
    else {
        return false;
        }
}

