#include <iostream>
using namespace std;

int main() {
    // Anem llegint les entrades i responem en funció de la paritat
    int n;
    while (cin >> n) {
        if (n % 2 == 0)
            cout << "apagat" << endl;
        else
            cout << "ences" << endl;
    }
}