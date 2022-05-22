#include <iostream>
using namespace std;

int main() {
    // Inicialitzem les variables
    string str_millor_1, str_millor_2, str_millora_mes_gran;
    double millor_1 = -1.0, millor_2 = -1.0, millora_mes_gran = -1e6;
    
    // Llegim els anys
    int a1, a2;
    cin >> a1 >> a2;
    
    // Anem llegint les dades de cada país i actualitzant les variables
    string s;
    double e1, e2;
    while (cin >> s >> e1 >> e2) {
        if (e1 > millor_1) {
            millor_1 = e1;
            str_millor_1 = s;
        }
        if (e2 > millor_2) {
            millor_2 = e2;
            str_millor_2 = s;
        }
        if (e2 - e1 > millora_mes_gran) {
            millora_mes_gran = e2 - e1;
            str_millora_mes_gran = s;
        }
    }

    // Escrivim les respostes
    cout << str_millor_1 << " te la millor esperanca de vida de " << a1 << '.' << endl;
    cout << str_millor_2 << " te la millor esperanca de vida de " << a2 << '.' << endl;
    cout << str_millora_mes_gran << " te la millora mes gran." << endl;
}