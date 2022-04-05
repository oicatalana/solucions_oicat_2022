#include <iostream>
#include <vector>
using namespace std;

// Desplaçaments possibles del cavall
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Mapa i dimensions
vector<string> mapa;
int n, m;

// Nombre de posicions buides del mapa (sense comptar l'inici)
int llocs_buits = 0;

// Retorna true si la posició (x, y) està dins del mapa
bool esta_dins(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

int backtracking(int x, int y, int salts) {
    // Hem trobat una solució si el cavall ha fet tants salts
    // com espais buits hi ha
    if (salts == llocs_buits)
        return 1;

    // Marquem provisionalment la posició com a prohibida
    // per no visitar-la de nou
    mapa[x][y] = 'X';

    // Ens desplacem a totes les caselles buides sense visitar a les que
    // el cavall pot arribar des de (x, y) amb un sol salt,
    // i acumulem el nombre de solucions
    int solucions_trobades = 0;
    for (int i = 0; i < 8; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (esta_dins(X, Y) and mapa[X][Y] == '.')
            solucions_trobades += backtracking(X, Y, salts + 1);
    }

    // Tornem a marcar la casella com a visitable i retornem la solució
    mapa[x][y] = '.';
    return solucions_trobades;
}

int main() {
    while (cin >> n >> m) {
        // Fem que el mapa tingui n files i el llegim
        mapa.resize(n);
        for (string& s : mapa)
            cin >> s;

        // Busquem la posició inicial, i mirem quants llocs buits hi ha
        int px = -1, py = -1;
        llocs_buits = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (mapa[i][j] == 'I') {
                    px = i;
                    py = j;
                }
                if (mapa[i][j] == '.') {
                    ++llocs_buits;
                }
            }

        // Comptem les solucions corrent un backtracking des de l'inici
        cout << backtracking(px, py, 0) << endl;
    }
}