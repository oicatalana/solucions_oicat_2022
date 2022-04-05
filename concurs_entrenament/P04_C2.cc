#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    cout << (x % 4 == 0 and not (x % 100 == 0 and x % 400 != 0) ? "YES" : "NO") << endl;
}
