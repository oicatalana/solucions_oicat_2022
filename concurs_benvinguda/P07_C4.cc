#include <iostream>
using namespace std;

int main() {
    // Anem llegint l'entrada, i afegim un salt
    // de línia a tots els casos menys el primer 
    int n;
    bool es_el_primer = true;
    while (cin >> n) {
        if (not es_el_primer)
            cout << endl;
        else
            es_el_primer = false;

        // Escrivim n línies, totes consistint en n cops el nombre n
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << n;
            cout << endl;
        }
    }
}