#include <iostream>
#include <vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<VI> VVI;

VVI G;		// El graf
VI color;	// color[x] val -1 si el node x encara no té color

bool dfs(int x, int c) {
	// Si el node està pintat, retornem si el color candidat és igual al color
	if (color[x] != -1)
        return color[x] == c;

	// Pintem el node del color c (que valdrà 0 o 1) si no està pintat
    color[x] = c;

	// Intentem pintar tots els veïns del color contrari
	// Retornem false si no hem pogut
	for (int y : G[x])
        if (!dfs(y, 1 - c))
            return false;

	// Si hem arribat aquí, tot ha anat bé i retornem true
	return true;
}

int main(){
	int n, m;
	while (cin >> n >> m) {
		// Marquem tots els nodes com a no colorejats
		color = VI(n, -1);

		// Llegim el graf
		G = VVI(n);
        for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}

		// Intentem colorejar tots els nodes no colorejats que trobem i responem
		bool ok = true;
		for (int i = 0; i < n and ok; ++i)
			if (color[i] == -1)
                ok &= dfs(i, 0);

		cout << (ok ? "yes" : "no") << endl;
	}
}