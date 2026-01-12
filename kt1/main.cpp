#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game() {
    srand(time(0));
    // luku väliltä 1–20
    int oikea = rand() % 20 + 1;

    int arvaus = 0;
    int yritykset = 0;

    while (arvaus != oikea) {
        cout << "Arvaa luku (1-20): ";
        cin >> arvaus;
        yritykset++;
        if (arvaus < oikea) {
            cout << "Liian pieni" << endl;
        } else if (arvaus > oikea) {
            cout << "Liian suuri" << endl;
        } else if (arvaus == oikea){
            cout << "Oikein!" << endl;
        }
    }

    return yritykset;
}


int main() {
    int tulos = game();
    cout << "Arvasit oikein " << tulos << " kerralla!" << endl;
    return 0;
}
