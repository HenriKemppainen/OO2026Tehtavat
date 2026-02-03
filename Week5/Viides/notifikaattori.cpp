#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *uusi){
    cout << "Notifikaattori lisaa seuraajan " << uusi->getNimi() << endl;
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void Notifikaattori::poista(Seuraaja *poisto){

    cout << "Notifikaattori poistaa seuraajan " << poisto->getNimi() << endl;

    // Poistettava on listan ensimmäinen
    if (seuraajat == poisto) {
        seuraajat = seuraajat->next;
        return;
    }

    // Etsitään poistettavaa edeltävä jäsen
    Seuraaja *ptr = seuraajat;
    while (ptr->next != nullptr && ptr->next != poisto) {
        ptr = ptr->next;
    }

    // Jos poistettava löytyi, "hypätään" sen yli
    if (ptr->next == poisto) {
        ptr->next = poisto->next;
    }
}

void Notifikaattori::tulosta(){
    cout << "Notifikaattorin seuraajat:" << endl;
    Seuraaja* ptr = seuraajat;
    while (ptr != nullptr) {
        cout << "Seuraaja " << ptr->getNimi() << endl;
        ptr = ptr->next;
    }
}

void Notifikaattori::postita(string postaus){
    cout << "Notifikaattori postaa viestin: " << postaus << endl;

    Seuraaja* ptr = seuraajat;
    while (ptr != nullptr) {
        ptr->paivitys(postaus);
        ptr = ptr->next;
    }
}
