#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// eka chef
class Chef {
protected:
    string chefName;

public:
    Chef(string name) {
        chefName = name;
        cout << "Chef " << chefName << " konstruktori" << endl;
    }
    ~Chef() {
        cout << "Chef " << chefName << " destruktori" << endl;
    }

    string getName() {
        return chefName;
    }

    int makeSalad(int ingredients) {
        int portions = ingredients / 5;
        cout << "Chef " << chefName << " makes salad with " << ingredients << " items" << endl;
        return portions;
    }

    int makeSoup(int ingredients) {
        int portions = ingredients / 3;
        cout << "Chef " << chefName << " makes soup with " << ingredients << " items" << endl;
        return portions;
    }
};

class ItalianChef : public Chef {
private:
    string password = "pizza";
    int flour;
    int water;

    // tee pitsu
    int makePizza(int flour, int water) {
        int pizzasFromFlour = flour / 5;
        int pizzasFromWater = water / 5;

        // Etitään rajoittava tekijä
        int pizzas = std::min(pizzasFromFlour, pizzasFromWater);

        cout << "ItalianChef " << chefName << " makes " << pizzas << " pizzas" << endl;
        return pizzas;
    }

public:
    // Konstru
    ItalianChef(string name) : Chef(name) {
        cout << "ItalianChef konstruktori" << endl;
    }

    // Destru
    ~ItalianChef() {
        cout << "ItalianChef destruktori" << endl;
    }

    // tarkista salasana
    bool askSecret(string givenPassword, int flourAmount, int waterAmount) {
        if (password.compare(givenPassword) == 0) {
            cout << "Passu ok!" << endl;

            this->flour = flourAmount;
            this->water = waterAmount;

            // Kutsutaan salaista metodia
            makePizza(flourAmount, waterAmount);
            return true;
        } else {
            cout << "Passu väärä!" << endl;
            return false;
        }
    }
};

int main() {
    // Testataan
    Chef kokki("Gordon");

    kokki.makeSalad(11); // Pitäisi tulla 2
    kokki.makeSoup(10);  // Pitäisi tulla 3



    ItalianChef Totti("Totti");

    Totti.makeSalad(10); // Chef

    // Kokeillaan väärää salasanaa
    cout << "\n Kokeillaan vaaraa salasanaa:" << endl;
    Totti.askSecret("pasta", 10, 10);

    // Kokeillaan oikeaa salasanaa
    cout << "\n Kokeillaan oikeaa salasanaa:" << endl;
    Totti.askSecret("pizza", 12, 12);

    return 0;
}
