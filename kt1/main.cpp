#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    // luku väliltä 1–20
    int oikea = rand() % 20 + 1;

    int arvaus;

    while (arvaus != oikea) {
        cout << "Arvaa luku (1-20): ";
        cin >> arvaus;

        if (arvaus < oikea) {
            cout << "Liian pieni" << endl;
        } else if (arvaus > oikea) {
            cout << "Liian suuri" << endl;
        } else if (arvaus == oikea){
            cout << "Oikein!" << endl;
        }
    }

    return 0;
}
