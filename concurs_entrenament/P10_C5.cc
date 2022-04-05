#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Sudoku;

// Definició: Direm que un subrectangle del sudoku és "complet"
// si té els nombres de l'1 al 9 exactament un cop

// Retorna true si el subrectangle del sudoku s de mida h x w
// amb cantonada superior esquerra a (x, y) és complet
bool rectangle_complet(Sudoku& s, int x, int y, int h, int w) {
    vector<bool> v(10, false);      // v[k] és true si k apareix al subrectangle
    for (int i = x; i < x + h; ++i)
        for (int j = y; j < y + w; ++j) {
            if (v[s[i][j]])
                return false;
            v[s[i][j]] = true;
        }
    return true;
}

// Retorna true si la fila x és completa
bool fila_completa(Sudoku& s, int x) {
    return rectangle_complet(s, x, 0, 1, 9);
}

// Retorna true si la columna y és completa
bool columna_completa(Sudoku& s, int y) {
    return rectangle_complet(s, 0, y, 9, 1);
}

// Retorna true si el subquadrat 3x3 corresponent és complet
bool quadrat_complet(Sudoku& s, int X, int Y) {
    return rectangle_complet(s, 3*X, 3*Y, 3, 3);
}

// El sudoku s estarà resolt si i només si les seves
// 9 files, 9 columnes, i 9 subquadrats 3x3 són complets
bool es_solucio(Sudoku& s) {
    for (int i = 0; i < 9; ++i)
        if (!fila_completa(s, i) or !columna_completa(s, i) or !quadrat_complet(s, i/3, i%3))
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; ++t) {
        // Llegim el sudoku
        Sudoku s(9, Fila(9));
        for (Fila& f : s)
            for (int& x : f)
            cin >> x;

        // Donem la resposta
        cout << (es_solucio(s) ? "si" : "no") << endl;
    }
}