#include <iostream>
#include <string>

class Seuraaja {
public:
    // Konstruktori asettaa nimen ja varmistaa, että next on nullptr
    Seuraaja(std::string n) : nimi(n), next(nullptr) {
        std::cout << "Luotiin seuraaja: " << nimi << std::endl;
    }

    std::string getNimi() const { return nimi; }

    // Tulostus
    void paivitys(std::string viesti) {
        std::cout << "Seuraaja " << nimi << " sai viestin: " << viesti << std::endl;
    }

    Seuraaja* next; // Osoitin seuraavaan

private:
    std::string nimi;
};


class Notifikaattori {
public:
    // Alustetaan tyhjäks
    Notifikaattori() : seuraajat(nullptr) {
        std::cout << "Notifikaattori alustettu." << std::endl;
    }

    // Lisäys "kiilaamalla" listan alkuun
    void lisaa(Seuraaja* uusi) {
        if (uusi == nullptr) return;
        uusi->next = seuraajat;
        seuraajat = uusi;
        std::cout << "Lisattiin " << uusi->getNimi() << " notifikaattoriin." << std::endl;
    }

    // Poisto "skippaamalla" olio listassa
    void poista(Seuraaja* poistettava) {
        Seuraaja* nykyinen = seuraajat;
        Seuraaja* edellinen = nullptr;

        while (nykyinen != nullptr && nykyinen != poistettava) {
            edellinen = nykyinen;
            nykyinen = nykyinen->next;
        }

        if (nykyinen == nullptr) return; // Ei loytynyt

        if (edellinen == nullptr) {
            seuraajat = nykyinen->next; // Oli ensimmäinen
        } else {
            edellinen->next = nykyinen->next; // Ohitus
        }
        std::cout << "Poistettiin " << nykyinen->getNimi() << " notifikaattorista." << std::endl;
    }

    // Tulostus käymällä lista läpi
    void tulosta() {
        std::cout << "Notifikaattorin seuraajat talla hetkella:" << std::endl;
                Seuraaja* o = seuraajat;
        while (o != nullptr) {
            std::cout << "  - " << o->getNimi() << std::endl;
            o = o->next;
        }
    }

    // Postitus kutsumalla joka tyypin paivitys()-funktiota
    void postita(std::string viesti) {
        std::cout << "Notifikaattori postaa: " << viesti << std::endl;
        Seuraaja* o = seuraajat;
        while (o != nullptr) {
            o->paivitys(viesti);
            o = o->next;
        }
    }

private:
    Seuraaja* seuraajat; // Listan head
};


int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(&b);

    n.postita("Tama on viesti 2");

    return 0;
}
