#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int suma = a + b;
    int resta = a - b;

    if (suma > resta) {
        cout << "suma" << endl;
        cout << suma - resta << endl;
    }
    else if (resta > suma) {
        cout << "resta" << endl;
        cout << resta - suma << endl;
    }
    else {
        cout << "igual" << endl;
        cout << 0 << endl;
    }
}