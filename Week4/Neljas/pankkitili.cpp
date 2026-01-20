#include "pankkitili.h"

Pankkitili::Pankkitili(string nimi) {
    omistaja = nimi;

}


double Pankkitili::getBalance(){
    return saldo;
}

bool Pankkitili::deposit(double talletus){
    if (talletus >= 0){
            saldo += talletus;
            cout  << "Pankkitili: talletus: " << talletus << " tehty" << endl;
            return true;
    }
    else {
        return false;
    }
}
bool Pankkitili::withdraw(double nosto){
    if(saldo-nosto >= 0 && nosto >= 0){
        saldo -= nosto;
        cout << "Pankkitili: nosto: " << nosto << " tehty" << endl;
        return true;
    }
    else {
        return false;
        }
}

