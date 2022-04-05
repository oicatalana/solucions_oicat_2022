#include <iostream>
#include <cmath>
using namespace std;

typedef long long int LL;

int main() {
    int n, a, b;
    while (cin >> n >> a >> b) {
        // La nostra solució estarà a l'interval (l, r]
        // Agafarem una r que asseguri que l'interval conté la solució,
        // però que no causi overflows
        LL l = 0, r = max(a, b)*LL(ceil(sqrt(n)));

        // Busquem quina és la solució més petita fent una cerca binària, i
        // pararem quan l'interval que conté la solució contingui un únic enter
        while (r - l > 1) {
            LL m = (r + l)/2;
            if ((m/a) * (m/b) >= n)
                r = m;
            else
                l = m; 
        }
        cout << r << endl;
    }
}