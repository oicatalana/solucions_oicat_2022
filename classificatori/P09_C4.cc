// El problema és fàcil si el pensem al revés:
// Intentem anar des de n fins a 0 fent el mínim nombre de passes
// possibles, restant 1 o dividint per 3 
// (només si el nostre nombre és múltiple de 3).
// És fàcil veure que dividir per 3 sempre ens acosta més ràpid
// a la solució. Per tant, dividirem per 3 sempre que puguem,
// i si no, restarem 1.

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int resposta = 0;
        while (n > 0) {
            if (n%3 == 0)
                n /= 3;
            else
                --n;
            ++resposta;
        }
        cout << resposta << endl;
    }
}