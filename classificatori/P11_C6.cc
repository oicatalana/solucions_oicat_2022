#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI G;      // G[x]: els veïns de x
VI dist;    // dist[x]: distancia màxima des de x
            // (-1 quan no se sap, -2 quan no puguem arribar a l'últim vèrtex)

// Retorna la distància màxima des del vèrtex x
int troba_distancia_maxima(int x) {
    // Si ja coneixem quan val, retornem el valor
    if (dist[x] != -1)
        return dist[x];

    // Mirem quina és la distància màxima d entre els veïns
    int d = -2;
    for (int y : G[x]) {
        int z = troba_distancia_maxima(y);
        if (z != -2)
            d = max(d, z + 1);
    }

    // Retornem d i guardem alhora el resultat a dist[x]
    return dist[x] = d;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        // Creem el vector de distàncies màximes
        dist = VI(n, -1);
        dist[n - 1] = 0;

        // Llegim el graf (el -1 és per indexar des de 0)
        G = VVI(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x - 1].push_back(y - 1);
        }

        // Mirem quina és la distància màxima i quants cops es repeteix
        int maxima_distancia = 0;
        int resposta = 0;
        for (int i = 0; i < n; ++i) {
            int x = troba_distancia_maxima(i);
            if (x > maxima_distancia) {
                maxima_distancia = x;
                resposta = 1;
            }
            else if (x == maxima_distancia)
                ++resposta;
        }

        cout << resposta << endl;
    }
}
