#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // Anem escrivint els nombres en ordre amb un for
    // Posem la coma després de tots excepte l'últim
    for (int i = a; i <= b; ++i) {
        cout << i;
        if (i != b)
            cout << ",";
    }
    cout << endl;
}