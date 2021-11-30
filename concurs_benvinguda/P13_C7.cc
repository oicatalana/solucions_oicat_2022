#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> mapa;        // Mapa
int n, m;                   // Dimensions del mapa
int x_inicial, y_inicial;   // Posició inicial

// Possibles desplaçaments (est, nord, oest, sud)
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

// Diu si la posició (x, y) està dins del mapa
bool dins_del_mapa(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

// Guarda una posició (x, y) junt amb la distància des de la casella inicial
struct Posicio {
    int x, y, dist;
};

// Amb l'algorisme BFS, anirem explorant les caselles,
// ordenades per la distància respecte la posició inicial
int bfs() {
    // Creem la cua i hi afegim la posició inicial, amd distància 0
    queue<Posicio> Q;
    Q.push(Posicio{x_inicial, y_inicial, 0});

    // Anem explorat en ordre
    while (!Q.empty()) {
        // Mirem la següent posició i la traiem de la cua
        Posicio P = Q.front();
        Q.pop();

        // Si és un tresor, ja hem trobat el més proper
        if (mapa[P.x][P.y] == 't')
        return P.dist;

        // Si no, marquem la casella com un obstacle per no visitar-la de nou
        mapa[P.x][P.y] = 'X';

        // Mirem les 4 caselles (X, Y) veïnes. Si són dins del mapa
        // i no són un obstacle, les podrem visitar
        for (int i = 0; i < 4; ++i) {
            int X = P.x + dx[i];
            int Y = P.y + dy[i];
            if (dins_del_mapa(X, Y))
                if (mapa[X][Y] != 'X')
                    Q.push(Posicio{X, Y, P.dist + 1});
        }
    }

    // El bucle anterior acabarà si cap de les caselles a les que podíem
    // arribar era un tresor. Retornarem un -1. 
    return -1;
}

int main() {
    // Llegim l'entrada.
    // Disminuïm en 1 les coordenades inicials per fer-les 0-indexed
    cin >> n >> m;
    mapa.resize(n);
    for (string& fila : mapa)
        cin >> fila;
    cin >> x_inicial >> y_inicial;
    --x_inicial, --y_inicial;

    // Obtenim la resposta i responem
    int resposta = bfs();
    if (resposta == -1)
        cout << "no es pot arribar a cap tresor" << endl;
    else
        cout << "distancia minima: " << resposta << endl;
}
