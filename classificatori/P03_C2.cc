#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> nombres = {
        "zero", "u", "dos", "tres", "quatre", "cinc", "sis",
        "set", "vuit", "nou", "deu", "onze", "dotze",
        "tretze", "catorze", "quinze", "setze", "disset", "divuit"
    };

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string A, B;
        cin >> A >> B;

        // a i b seran els valors numèrics dels nombres de l'input
        int a, b;
        for (int j = 0; j <= 9; ++j) {
            if (nombres[j] == A)
                a = j;
            if (nombres[j] == B)
                b = j;
        }

        cout << A << " + " << B << " = " << nombres[a + b] << endl;
    }
}