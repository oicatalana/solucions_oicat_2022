#include <iostream>
using namespace std;

// El patró per n = 1 és "*"
// El patró per n > 1 és:
//      1. El patró per n - 1
//      2. Una línia amb n asteriscs
//      3. El patró per n - 1
void dibuixa_patro(int n) {
    if (n == 1) {
        cout << "*" << endl;
        return;
    }
    dibuixa_patro(n - 1);
    cout << string(n, '*') << endl;
    dibuixa_patro(n - 1);
}

int main() {
    int n;
    cin >> n;
    dibuixa_patro(n);
}