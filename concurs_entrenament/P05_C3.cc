#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'o') --x;
        if (s[i] == 'e') ++x;
        if (s[i] == 'n') --y;
        if (s[i] == 's') ++y;
    }

    cout << "(" << x << ", " << y << ")" << endl;
}