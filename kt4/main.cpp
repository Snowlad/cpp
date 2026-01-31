#include <iostream>
#include <string>

using namespace std;

class Pankkitili {
protected:
    string omistaja;
    double saldo = 0;

public:
    Pankkitili(string nimi) : omistaja(nimi) {}

    double getBalance() { return saldo; }

    virtual bool deposit(double maara) {
        if (maara < 0) return false; // Ei negatiivistä
        saldo += maara;
        return true; //
    }

    virtual bool withdraw(double maara) {
        if (maara < 0 || maara > saldo) return false; // Ei liikaa nostoa
        saldo -= maara;
        return true; //
    }
};

class Luottotili : public Pankkitili {
protected:
    double luottoRaja = 0; //

public:

    Luottotili(string nimi, double raja) : Pankkitili(nimi), luottoRaja(raja) {}

    bool withdraw(double maara) override {
        if (maara < 0 || (saldo - maara) < -luottoRaja) return false; //
        saldo -= maara;
        return true; //
    }

    bool deposit(double maara) override {
        if (maara < 0 || (saldo + maara) > 0) return false; //
        saldo += maara;
        return true; //
    }
};

class Asiakas {
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    // Pistetää asiakkaan tiedot
    Asiakas(string nimi, double luottoRaja)
        : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja) {}

    string getNimi() { return nimi; } //

    void showSaldo() {
        cout << "\n Asiakkaan " << nimi << " tilitiedot:" << endl;
        cout << " Kayttotilin saldo: " << kayttotili.getBalance() << endl; //
        cout << " Luottotilin saldo: " << luottotili.getBalance() << endl; //
    }

    bool talletus(double maara) { return kayttotili.deposit(maara); }
    bool nosto(double maara) { return kayttotili.withdraw(maara); }
    bool luotonMaksu(double maara) { return luottotili.deposit(maara); }
    bool luotonNosto(double maara) { return luottotili.withdraw(maara); }

    //Tilisiirto eli teht2
    bool tiliSiirto(double summa, Asiakas &vastaanottaja) {
        cout << "Pankkitili: " << nimi << " siirtaa " << summa << " " << vastaanottaja.nimi << ":lle" << endl;
        // jos ei massii nii kielletty
        if (summa < 0) return false;

        if (this->kayttotili.withdraw(summa)) {
            cout << nimi << " Pankkitili: nosto " << summa << " tehty" << endl;
            vastaanottaja.kayttotili.deposit(summa);
            cout << vastaanottaja.nimi << " Pankkitili: talletus " << summa << " tehty" << endl;
            return true;
        }

        cout << "Siirto epaonnistui." << endl;
        return false;
    }
};

int main() {
    // testiuseri
    Asiakas paavo("Paavo", 1000);
    paavo.showSaldo();

    // Paavon siirto
    cout << "\nPankkitili: talletus 250 tehty" << endl;
    paavo.talletus(250);

    cout << "Luottotili: nosto 150 tehty, luottoa jaljella 850" << endl;
    paavo.luotonNosto(150);

    paavo.showSaldo();

    // toka uuuseri
    cout << endl;
    Asiakas bertta("Bertta", 1000);
    bertta.showSaldo();

    // siirto
    cout << endl;
    paavo.showSaldo();
    paavo.tiliSiirto(50, bertta);

    bertta.showSaldo();

    return 0;
}
