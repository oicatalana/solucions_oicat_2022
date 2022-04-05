#include <iostream>
#include <map>
using namespace std;

typedef long long int LL;

int main() {
    int n;
    while (cin >> n) {
        // M[x]: nombre de cops que apareix el nombre x a la llista
        map<LL, LL> M;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++M[x];
        }

        // Guardem la suma màxima i la segona suma màxima
        LL suma_maxima = 0, segona_suma_maxima = 0;
        for (auto [x, reps] : M) {
            // Per a cada x de M, els únics candidats a ser suma màxima i
            // segona suma màxima són x*M[x] i x*(M[x] - 1)
            for (LL candidat : {x*reps, x*(reps - 1)}) {
                if (candidat > suma_maxima) {
                    segona_suma_maxima = suma_maxima;
                    suma_maxima = candidat;
                }
                else if (candidat > segona_suma_maxima) {
                    segona_suma_maxima = candidat;
                }
            }
        }

        cout << segona_suma_maxima << endl;
    }
}