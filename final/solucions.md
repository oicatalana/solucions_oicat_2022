# Solucions Final OICat 2022

<!-- :warning: __AQUEST DOCUMENT ENCARA NO ESTÀ ACABAT I CONTÉ ERRORS__ -->

## Taula de continguts
* [Problema Q1. Onze llibres](#Q1)
* [Problema C1. Esperança de vida](#C1)
* [Problema G1. Dígits iguals](#G1)
* [Problema C2. Estudiant nefast](#C2)
* [Problema Q2. Hotel Vela](#Q2)
* [Problema G2. Paràbola](#G2)
* [Problema C3. Eliminació per parells](#C3)
* [Problema Q3. Octaedre](#Q3)
* [Problema G3. Hipercub](#G3)
* [Problema C4. Xor de tres](#C4)
* [Problema G4. Pixel art](#G4)
* [Problema C5. Mineria](#C5)
* [Problema C6. Nombres de Bell](#C6)
* [Problema C7. Avaries](#C7)
* [Problema Q4. Raó àuria](#Q4)

## [Problema Q1. Onze llibres](https://jutge.org/problems/P57678_ca) <a name="Q1"/>

<b>Autor:</b> Marc Felipe <br>
<b>Nombre de ACs:</b> 25 <br>
<b>Primer AC:</b> Roger Lidón

Clarament, haurem de posar els 6 llibres blaus separats pels altres 5 llibres,
per tant només ens queda escollir on posem aquests 5.

Com que ja estan separats pels llibres blaus, només ens cal escollir les 2 posicions
d'aquestes 5 on hi posarem els llibres vermells (les altres 3 seran pels llibres grocs).

Podem trobar aquesta quantitat a mà o amb una mica de [combinatòria](https://ca.wikipedia.org/wiki/Coeficient_binomial#Interpretaci%C3%B3_combinat%C3%B2ria): $\binom{5}{2} = 10$.

## [Problema C1. Esperança de vida](https://jutge.org/problems/P12454_ca) <a name="C1"/>

<b>Autor:</b> Jorge Castro <br>
<b>Nombre de ACs:</b> 23 <br>
<b>Primer AC:</b> Alejandro Vivero

És suficient amb anar llegint les dades i anar actualitzant la informació
del millor país segons els tres criteris diferents en la sortida.

En aquests casos, cal anar amb compte amb com inicialitzem les variables:
volem que després de llegir el primer país aquest sigui el millor en tots tres aspectes!

<details>
  <summary><b>Codi</b></summary>

```cpp
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
```
</details>

## [Problema G1. Dígits iguals](https://jutge.org/problems/P27390_ca) <a name="G1"/>

<b>Autor:</b> Xavier Povill <br>
<b>Nombre de ACs:</b> 22 <br>
<b>Primer AC:</b> Roger Lidón

En tenim prou amb anar comprovant la condició per tots els punts i pintar-lo
amb el color que toca. Si rebeu un _time limit exceeded_,
és una bona idea plantejar-se pintar tot del color de fons `f`,
i després només pintar els punts que toquin amb el color `c`, que serà
el que aparegui de forma menys freqüent.

<details>
  <summary><b>Codi</b></summary>

```py
from PIL import Image, ImageDraw

# Llegim les variables
n = int(input())
m = int(input())
c = input()
f = input()

# Creem la imatge
img = Image.new('RGB', (m, n), f)
dib = ImageDraw.Draw(img)

# Anem pintant tots els punts
for y in range(n):
    for x in range(m):
        digit_unitats_suma = (x + y)%10
        digit_desenes_producte = ((x * y)//10)%10
        if digit_unitats_suma == digit_desenes_producte:
            dib.point((x, y), c)

# Guardem la imatge
img.save("output.png")
```
</details>

__Repte:__ Podríeu demostrar matemàticament que la imatge és
una repetició de patrons de mida $100 \times 100$?

## [Problema C2. Estudiant nefast](https://jutge.org/problems/P81388_ca) <a name="C2"/>

<b>Autor:</b> Víctor Martín <br>
<b>Nombre de ACs:</b> 26 <br>
<b>Primer AC:</b> Innokentiy Kaurov

Sí, aquest problema està basat en fets reals. Es pot solucionar de diverses
maneres. Potser aquesta és la més senzilla: ordenem totes les notes,
a continuació les anem posant en ordre en un vector, però fent dues passades:
primer una amb les notes aprovades, i després una amb les suspeses.

<details>
  <summary><b>Codi</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        // Llegim les notes
        vector<int> v(n);
        for (int& x : v)
            cin >> x;

        // Ordenem de petit a gran
        sort(v.begin(), v.end());

        // Notes ordenades amb el criteri demanat
        vector<int> w;

        // Posem primer els aprovats
        for (int x : v)
            if (x >= 500000)
                w.push_back(x);

        // Posem després els suspesos
        for (int x : v)
            if (x < 500000)
                w.push_back(x);

        // Escrivim la resposta
        for (int i = 0; i < n; ++i) {
            if (i > 0)
                cout << ' ';
            cout << v[i];
        }
        cout << endl;
    }   
}
```
</details>

<details>
  <summary><b>Repte:</b> Intenteu entendre aquesta solució "d'una línia":</summary>

```python
import sys

for line in sys.stdin:
    print(*sorted([int(s) for s in line.rstrip('\n').split()][1:], key=lambda x:(x < 500000, x)))
```
</details>

## [Problema Q2. Hotel Vela](https://jutge.org/problems/P24906_ca) <a name="Q2"/>

<b>Autor:</b> Xavier Povill <br>
<b>Nombre de ACs:</b> 26 <br>
<b>Primer AC:</b> Amal Dokkar

__Solució 1:__

Per una porta $n$ hi passen tantes persones com divisors tingui $n$. Per tant, les portes que quedin obertes seran aquelles amb un nombre senar de divisors. Observeu que podem agrupar els divisors d'un nombre $n$ en parelles que multiplicades donen $n$. Per exemple: $24 = 1 \cdot 24 = 2 \cdot 12 = 3 \cdot 8 = 4 \cdot 6$. L'únic cas en què no ho podrem fer és si el nombre és un quadrat perfecte. Per tant, els únics nombres amb un nombre senar de divisors són els quadrats perfectes.

Per trobar la suma dels quadrats perfectes fins a 473, podem escriure un programa o utilitzar la fórmula:

$$1^2 + 2^2 + \dots + n^2 = \frac{n(n+1)(2n+1)}{6}$$

__Repte__: Podríeu demostrar aquesta fórmula? (Pista: useu el mètode d'inducció)

__Solució 2:__

Alternativament, podem simular el que ens diu l'enunciat: iterem en ordre per cada hoste,
i per cadascun d'aquests fem que canviï l'estat de les portes per les que passa.

<details>
  <summary><b>Codi</b></summary>

```python
NUM_PORTES = 473

# portes[i] és True si i només si la porta de l'habitació i està oberta
portes = [False]*(NUM_PORTES + 1)

# Simulem
for i in range(1, NUM_PORTES + 1):
    for j in range(i, NUM_PORTES + 1, i):
        portes[j] = not portes[j]

# Donem la suma dels índexos de les portes obertes
print(sum(i for i in range(1, NUM_PORTES + 1) if portes[i]))
```
</details>

__Repte:__ Si teniu dubtes de com funciona el `range()` amb 3 paràmetres del codi anterior, podeu provar de resoldre [aquest problema](https://jutge.org/problems/P93780_ca).

## [Problema G2. Paràbola](https://jutge.org/problems/P60526_ca) <a name="G2"/>

<b>Autor:</b> Max Balsells <br>
<b>Nombre de ACs:</b> 7 <br>
<b>Primer AC:</b> Innokentiy Kaurov

Per resoldre'l no cal massa més que seguir al peu de la lletra el que diu
l'enunciat, però cal anar amb compte amb els següents detalls:
* L'eix `y` va al revés a l'enunciat del problema respecte a la imatge que dibuixem (a la llibreria `PIL` per defecte l'eix vertical augmenta de dalt a baix).
* Si el punt final de la paràbola està per sota del punt inicial, caldrà traslladar la imatge verticalment.
* Només sabrem quina mida ha de tenir la imatge un cop haguem calculat tots els punts.
* Cal dibuixar les línies en l'ordre adient (altrament la imatge resultant pot ser lleugerament diferent).

A la nostra solució utilitzem [`zip()`](https://docs.python.org/3/library/functions.html#zip) i [slices](https://stackoverflow.com/questions/509211/understanding-slicing),
us recomenem fer una ullada a aquestes dues *features* de python perquè són molt comunes i útils.

<details>
  <summary><b>Codi</b></summary>

```python
from PIL import Image, ImageDraw

# Llegim l'entrada
a = int(input())
b = int(input())
c = int(input())
T = int(input())

# Guardem la llista de punts (canviant els signe de la coordenada y)
punts = [(c * t, -(b*t - a*t*t//2)) for t in range(T + 1)]

# Mirem quin és el punt més alt i el més baix
sorted_y_coords = sorted(y for _, y in punts)
min_y, max_y = sorted_y_coords[0], sorted_y_coords[T]

# Actualizem la llista de punts tal i com apareixeran a l'output
punts = [(x, y - min_y) for x, y in punts]

# Creem la imatge
img = Image.new('RGB', (c*T + 1, max_y - min_y + 1), 'SkyBlue')
dib = ImageDraw.Draw(img)

# Creem segments entre els parells de punts consecutius
for p, q in zip(punts, punts[1:]):
  dib.line([p, q], 'Red')

# Guardem la imatge
img.save("output.png")
```
</details>

## [Problema C3. Eliminació per parells](https://jutge.org/problems/P84545_ca) <a name="C3"/>

<b>Autor:</b> Salvador Roura <br>
<b>Nombre de ACs:</b> 2 <br>
<b>Primer AC:</b> Sergio Domínguez

La solució d'aquest problema passa per adonar-se del següent:

Sigui $T = C \setminus S$ el complementari de $S$ en $C$ (el que ens quedaria
a $C$ si hi traguéssim els elements de $S$). Sigui $S = ${$s_1, \dots, s_n $} i $T =$ {$t_1, \dots, t_n$}, de tal forma que els seus elements estan ordenats creixentment (és a dir, $s_1 \leq \dots \leq s_n$ i $t_1 \leq \dots \leq t_n$). Aleshores, existeix una solució si i només si $(s_1, t_{n-k+1}), (s_2, t_{n-k+2}),  \dots,  (s_k, t_n),  (s_{k+1}, t_1),  (s_{k+2}, t_2),  \dots, (s_n, t_{n-k})$ és solució.

Intuïtivament, el que significa això és que sempre és òptim emparellar els $k$ elements més petits de $S$ amb els $k$ més grans de $T$, i els $n-k$ més grans de $S$ amb els $n-k$ més petits de $T$. A continuació us ho demostrem.

__Demostració:__

Suposem que tenim una solució $(s_1, t_1), \ldots, (s_n, t_n)$ tal que,
per a tot $i$, $s_i$ i $t_i$ pertanyen a $S$ i $T$, respectivament,
i tal que $s_i \leq t_i$ si $1 \leq i \leq k$, i $s_i \geq t_i$ si $k < i \leq n$ (observeu que ara estem indexant els elements diferentment i que per tant no suposem que estiguin ordenats creixentment).
Suposem sense pèrdua de generalitat que $s_1 \leq \ldots \leq s_k$ i que
$s_{k + 1} \leq \ldots \leq s_n$.

Podem fer les següents observacions similars:

* Si existeixen $i \leq k < j$ tals que $s_i > s_j$, intercanviant $s_i$ per $s_j$
seguirem tenint una solució. D'aquí deduïm que podem dur a terme aquesta mena
d'intercanvis iterativament tantes vegades com calgui fins que
$s_1 \leq \ldots \leq s_k \leq s_{k + 1} \leq \ldots \leq s_n$,
i seguirem tenint una solució vàlida.
* Si existeixen $i \leq k < j$ tals que $t_i < t_j$, aleshores intercanviant $t_i$ per $t_j$
seguirem tenint una solució.
* Si existeixen $1 \leq i < j \leq k$ tals que $t_i > t_j$, aleshores intercanviant $t_i$ per $t_j$
seguirem tenint una solució.
* Si existeixen $k < i < j \leq n$ tals que $t_i > t_j$, aleshores intercanviant $t_i$ per $t_j$
seguirem tenint una solució.

Novament, aplicant aquests canvis tantes vegades com calgui, acabem obtenint una solució on $s_1 \leq \dots \leq s_n$ i $t_{k+1} \leq \dots \leq t_n \leq t_1 \leq \dots \leq t_{k}$. Es pot veure que això es correspon amb la construcció que havíem donat anteriorment.

<details>
  <summary><b>Codi</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;

int main() {
    int n, k;
    while (cin >> n >> k) {
        // Llegim C i ordenem
        VI C(2*n);
        for (int& x : C)
            cin >> x;
        sort(C.begin(), C.end());

        // Llegim S i ordenem
        VI S(n);
        for (int& x : S)
            cin >> x;
        sort(S.begin(), S.end());

        // T serà el complementari de S en C (el que pertany a C però no a S)
        // T també estarà ordenat
        VI T;
        int ps = 0;
        for (int pc = 0; pc < 2*n; ++pc) {
            if (ps == n or C[pc] != S[ps])
                T.push_back(C[pc]);
            else
                ++ps;
        }

        // La solució, i si la podem obtenir
        VPII sol;
        bool ok = true;

        // Ajuntem els k més petits de S amb els k més grans de T,
        // seguint el mateix ordre
        for (int i = 0; ok and i < k; ++i) {
            if (S[i] > T[(n - k) + i])
                ok = false;

            sol.push_back({S[i], T[n - k + i]});
        }

        // Ajuntem els n - k més grans de S amb els n - k més petits de T,
        // seguint el mateix ordre
        for (int i = 0; ok and i < n - k; ++i) {
            if (S[k + i] < T[i])
                ok = false;

            sol.push_back({S[k + i], T[i]});
        }

        // Responem en funció del que hem trobat
        if (ok) {
            cout << "SI";
            for (auto [s, t] : sol)
                cout << "  " << s << ' ' << t;
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
}
```
</details>

<details>
  <summary><b>Solució parcial</b></summary>

  Per obtenir la puntuació parcial havíem de resoldre el cas en que $k = 0$. Això vol dir que hem d'agrupar els nombres de $C$ en $n$ parelles de manera que els nombres més grans de cada parella formin $S$.

  Per tant, hem d'emparellar cada $s \in S$ amb un $t \in T$ que sigui més petit o igual que ell. En particular, observem que això vol dir que el nombre més gran de $S$ ha de ser més gran o igual que el nombre més gran de $T$ (altrament aquest nombre de $T$ no el podrem emparellar amb cap nombre de $S$), el segon nombre més gran de $S$ ha de ser més gran o igual que el segon nombre més gran de $T$, i així successivament.

  Així doncs, podem ordenar els nombres de $S$ i de $T$ i comprovar simplement si $s_i \geq t_i$ per cada $i$ de 1 fins a $n$. En cas que no, no hi haurà solució. En cas que sí, una solució possible serà $\{(s_1, t_1), (s_2, t_2), \dots, (s_n, t_n)\}$.

  <details>
    <summary>Codi</summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;

int main() {
    int n, k;
    while (cin >> n >> k) {
        // Llegim C i ordenem
        VI C(2*n);
        for (int& x : C)
            cin >> x;
        sort(C.begin(), C.end());

        // Llegim S i ordenem
        VI S(n);
        for (int& x : S)
            cin >> x;
        sort(S.begin(), S.end());

        // T serà el complementari de S en C (el que pertany a C però no a S)
        // T també estarà ordenat
        VI T;
        int ps = 0;
        for (int pc = 0; pc < 2*n; ++pc) {
            if (ps == n or C[pc] != S[ps])
                T.push_back(C[pc]);
            else
                ++ps;
        }

        // La solució, i si la podem obtenir
        VPII sol;
        bool ok = true;

        for (int i = 0; ok and i < n; ++i) {
            if (S[i] < T[i])
                ok = false;

            sol.push_back({S[i], T[i]});
        }

        // Responem en funció del que hem trobat
        if (ok) {
            cout << "SI";
            for (auto [s, t] : sol)
                cout << "  " << s << ' ' << t;
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
}
```

  </details>

</details>

## [Problema Q3. Octaedre](https://jutge.org/problems/P84218_ca) <a name="Q3"/>

<b>Autor:</b> Max Balsells <br>
<b>Nombre de ACs:</b> 12 <br>
<b>Primer AC:</b> Carles Melé

El primer pas per resoldre aquest problema és adonar-se que els valors de les arestes incidents a cada vèrtex han de sumar 26. Sabríeu justificar per què?
<details>
  <summary><b>Spoiler</b></summary>

  Els nombres de l'1 al 12 sumen 78, i cada aresta és incident a dos vèrtexs, de manera que la suma per tots els vèrtexs de la suma dels valors de les arestes incidents és $2 \cdot 78 = 156$. Com que la suma a cada vèrtex ha de ser igual i tenim 6 vèrtexs, tenim que la suma a cada vèrtex és $156/6 = 26$.

</details>

Un cop tenim això, podem anar provant a mà els diferents casos possibles amb una mica de traça o fer un programa que ens comprovi cada possible assignació dels nombres d'1 a 12 a les arestes.

<details>
  <summary><b>Codi</b></summary>

```python
# Graf: Cada entrada representa un node i conté una llista: les arestes a les que és incident
GRAF = [
    [1, 2, 5, 6],
    [1, 3, 4, 9],
    [2, 3, 7, 8],
    [4, 5, 10, 12],
    [6, 7, 10, 11],
    [8, 9, 11, 12],
]

## SOLUCIÓ 1: BACKTRACKING

def backtracking(perm):
    # Si ja hem afegit els 12 elements de la permutació, comprovem si és la resposta
    if len(perm) == 12:
        # Si per a cada node, la suma dels valors de les seves arestes és 26, hem trobat la solució
        for L in GRAF:
            if sum(perm[x - 1] for x in L) != 26:
                return

        # Si hem arribat aquí, la permutació que tenim és la solució
        print('-'.join(str(x) for x in perm))
        exit(0)

    # Per a cada i, si encara no hem usat i, l'afegim recursivament a la permutació
    for i in range(1, 13):
        if i not in perm:
            backtracking(perm + [i])

# Cridem el backtracking
backtracking([])

## SOLUCIÓ 2: ITERTOOLS

from itertools import permutations
for perm in permutations(list(range(1, 13))):
    for L in GRAF:
        if sum(perm[x - 1] for x in L) != 26:
            break
    else:
        print('-'.join(str(x) for x in perm))
        break
```
</details>

## [Problema G3. Hipercub](https://jutge.org/problems/P20096_ca) <a name="G3"/>

<b>Autor:</b> Víctor Martín <br>
<b>Nombre de ACs:</b> 4 <br>
<b>Primer AC:</b> Roger Lidón

Només s'han de dibuixar els $2^n$ punts i connectar cadascun als seus $n$ veïns,
anant amb compte de posar l'aresta correcta. El problema més gran que pot
sorgir és com canviar un bit concret d'un nombre. Ho podem fer amb XORs, amb recursivitat,
o fins i tot convertint el nombre a string i reconvertint-lo a enter després de canviar-li el valor de la posició on toca.

<details>
  <summary><b>Codi</b></summary>

```python
from PIL import Image, ImageDraw

# Llegim l'entrada
f = input()
c = input()
a = int(input())
b = int(input())
n = int(input())

# Llegim els punts
punts = [(int(input()), int(input())) for i in range(2**n)]

# Creem la imatge
img = Image.new('RGB', (a, b), f)
dib = ImageDraw.Draw(img)

# Dibuixem els punts
for x, y in punts:
    dib.ellipse((x - 2, y - 2, x + 2, y + 2), c)

# Funció per crear una línia del punt a al b
def add_edge(a, b):
    dib.line([punts[a], punts[b]], c)

# Funció per canviar el r-èssim bit de x
def canvia_bit(x, r):
    # Si cal canviar l'últim bit, suma 1 si aquest és 0, resta 1 si aquest és 1
    if r == 0:
        if x % 2 == 0:
            return x + 1
        else:
            return x - 1

        # Solucionem recursivament
        return 2*canvia_bit(x // 2, r - 1) + (x % 2)

# Connectem cada punt i a tots els punts j que difereixen en un bit (si i < j)
for i in range(2**n):
    for r in range(n):
        # j = i ^ (2 ** r) també funciona (sí, "^" representa un XOR)
        j = canvia_bit(i, r)
        if i < j:
            add_edge(i, j)

# Guardem la imatge
img.save("output.png")
```
</details>

## [Problema C4. Xor de tres](https://jutge.org/problems/P60779_ca) <a name="C4"/>

<b>Autor:</b> Edgar Moreno <br>
<b>Nombre de ACs:</b> 3 <br>
<b>Primer AC:</b> Innokentiy Kaurov

### Solució parcial

Per obtenir la puntuació parcial, n'hi havia prou amb iterar per totes les possibles combinacions de 4 elements, comprovant si el seu XOR és 0 (observeu que $v_i \oplus v_j \oplus v_k = v_l \iff v_i \oplus v_j \oplus v_k \oplus v_l = v_l \oplus v_l = 0$).

  El cost computacional és $\mathcal{O}(n^4)$, però com $n \leq 50$ en aquest subcàs, aquesta complexitat és assumible.

<details>
  <summary><b>Codi</b></summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;

bool resol(int n) {
    // Llegim els nombres
    vector<LL> v(n);
    for (LL& x : v)
        cin >> x;

    // Retornem true si trobem i < j < k < l tals que v[i]^v[j]^v[k] == v[l]
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                for (int l = k + 1; l < n; ++l)
                    if ((v[i]^v[j]^v[k]) == v[l])
                        return true;

    // Retornem false en cas contrari
    return false;
}

int main() {
    int n;
    while (cin >> n)
        cout << (resol(n) ? "SI" : "NO") << endl;
}
```
</details>

### Solució total

Cal observar primer algunes de les propietats de l'operació XOR (aquí la representarem amb el símbol $\oplus$):
* És commutativa: $x \oplus y = y \oplus x$.
* És associativa: $(x \oplus y) \oplus z = x \oplus (y \oplus z)$ (i per tant no ens cal representar-la amb parèntesis).
* La més important: $x \oplus x = 0$ per a tot $x$.

D'aquí es deriva el següent: si $x \oplus y = z$, llavors $x \oplus y \oplus y = z \oplus y$, i per tant
$x = y \oplus z$. En altres paraules, la condició que havíeu de trobar (hi ha 4 índexos diferents
$i, j, k, l$ tals que $v_i \oplus v_j \oplus v_k = v_l$), és equivalent a trobar 4 índexos diferents
$i, j, k, l$ tals que $v_i \oplus v_j = v_k \oplus v_l$.

Per tant, l'únic que s'ha de fer és calcular tots els XORs $v_i \oplus v_j$ amb $i < j$ i
parar quan trobem un resultat que ja haguem vist abans. Utilitzant un *set*, podem comprovar si hem vist abans un resultat en temps $\mathcal{O}(\log(n^2)) = \mathcal{O}(\log(n))$. Per tant, la complexitat total és $\mathcal{O}(n^2\log n)$.
Un cop troben aquest duplicat, hauríem de parar la nostra cerca per tal d'evitar gastar temps de computació inútilment.

Ens cal un últim detall: Què passa si tenim índexos diferents $i, j$ tals que $v_i = v_j$? En aquest cas
podríem cometre l'error de dir incorrectament que hem trobat dos parells: $(v_i, v_k)$, i $(v_j, v_k)$
amb mateix XOR. En aquest cas, no es difícil demostrar el següent:

__Repte__: Si $v_i \oplus v_j = v_k \oplus v_l$ i no tots els valors són diferents dos a dos,
llavors hi ha dos nombres $x, y$ (potser iguals) tals que dos d'aquests índexos valen $x$ i els
altres dos, $y$.

<details>
  <summary><b>Codi</b></summary>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long int LL;

bool solve(int n) {
    // Llegim l'entrada
    vector<LL> v(n);
    for (LL& x : v)
        cin >> x;

    // Ordenem els valors
    sort(v.begin(), v.end());

    // Si tenim i, j, k, l diferents tals que v[i] == v[j] i v[k] == v[l]...
    int reps = 0;
    for (int i = 1; i < n; ++i)
        if (v[i - 1] == v[i])
            ++reps, ++i;

    // ... resposta és sí
    if (reps >= 2)
        return true;

    // Eliminem les repeticions
    vector<LL> w;
    for (int i = 0; i < n; ++i)
        if (i == 0 or v[i] != v[i - 1])
            w.push_back(v[i]);

    // Mirem si hi ha dos parells amb el mateix XOR
    set<LL> S;
    for (int i = 0; i < w.size(); ++i)
        for (int j = i + 1; j < w.size(); ++j)
            if (!S.insert(w[i]^w[j]).second)
                return true;

    // Si no n'hem trobat cap, la resposta és NO
    return false;
}

int main() {
    int n;
    while (cin >> n)
        cout << (solve(n) ? "SI" : "NO") << endl;
}
```
</details>

## [Problema G4. Pixel art](https://jutge.org/problems/P38156_ca) <a name="G4"/>

<b>Autor:</b> Edgar Moreno <br>
<b>Nombre de ACs:</b> 3 <br>
<b>Primer AC:</b> Eloi Pagès

El problema ens demana buscar les $k$ components connexes més grans
i pintar totes les caselles que les componen. Podem fer això fàcilment usant
un algorisme de cerca en grafs com el DFS o el BFS.

<details>
  <summary><b>Codi</b></summary>

```python
from PIL import Image, ImageDraw

# Llista de direccions en les que ens podem moure
DIRECCIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# Llegim l'entrada
f = input()
c = input()
n = int(input())
m = int(input())
k = int(input())
graella = [input() for i in range(n)]

# Marquem totes les caselles com a no visitades
visitat = [[False for x in range(m)] for y in range(n)]

# Troba quantes caselles no visitades podem visitar des de (x, y)
def dfs(y, x):
    # Parem estem fora del mapa o la casella ja ha estat visitada
    if not (0 <= y < n) or not (0 <= x < m) or graella[y][x] == '.' or visitat[y][x]:
        return 0

    # Marquem ara la casella com a visitada
    visitat[y][x] = True

    # Retornem a quantes caselles no visitades hi podem arribar
    return sum(dfs(y + dy, x + dx) for dy, dx in DIRECCIONS) + 1

# Guardem la llista de components connexes. Aquestes vindran donades per 3 nombres:
# (mida, y, x), on `mida` és la mida de la component connexa, i (x, y) és un punt d'aquesta
components_connexes = []
for y in range(n):
    for x in range(m):
        if not visitat[y][x] and graella[y][x] == 'X':
            components_connexes.append((dfs(y, x), y, x))

# Creem la imatge
img = Image.new('RGB', (m, n), f)
dib = ImageDraw.Draw(img)

# Marquem quins punts hem pintat
pintat = [[False for x in range(m)] for y in range(n)]

# Pintem la component connexa
def pinta_dfs(y, x):
    # Parem si estem fora del mapa, o si ja hem pintat la casella
    if not (0 <= y < n) or not (0 <= x < m) or graella[y][x] == '.' or pintat[y][x]:
        return

    # Pintem el punt i el marquem com a pintat
    dib.point((x, y), c)
    pintat[y][x] = True

    # Pintem recursivament els punts adjacents
    for dy, dx in DIRECCIONS:
        pinta_dfs(y + dy, x + dx)

# Pintem les com a molt k components connexes més grans
for _, y, x in sorted(components_connexes, reverse=True)[:k]:
    pinta_dfs(y, x)

# Guardem la imatge
img.save('output.png')
```
</details>

## [Problema C5. Mineria](https://jutge.org/problems/P61019_ca) <a name="C5"/>

<b>Autor:</b> Salvador Roura <br>
<b>Nombre de ACs:</b> 0 <br>
<b>Primer AC:</b> :-(

<details>
  <summary><b>Solució parcial</b></summary>

  Per obtenir la puntuació parcial, s'havia de resoldre el cas on cap $b_i$ és negativa. Observeu que aleshores sempre ens interessa excavar el màxim possible (ja que el benefici d'excavar mai serà negatiu).

  No obstant això, continuem sotmesos a la restricció de no excavar més enllà de $p_i$ a la columna $i$, i no excavar fins a profunditat $j$ si a les posicions adjacents no s'ha excavat almenys fins a profunditat $j-1$.

  Una manera de resoldre el problema seria començar per l'esquerra i anar excavant sempre a 1 més de profunditat que a la columna anterior. Si en algun moment ens trobem amb que volem excavar $j$ metres i la profunditat màxima $p_i$ és més petita, excavem només $p_i$ metres i tirem cap enrere, actualitzant totes les columnes anteriors per assegurar-nos de no excavar més de 1 metre més que en la columna de la dreta.

  Observeu que aquest algorisme té complexitat $\mathcal{O}(n^2)$ ja que, encara que haguem de tirar cap enrere en cada posició, com a molt ho farem $n$ vegades, i cada cop que tirem cap enrere visitarem com a molt $n$ posicions.

  <details>
    <summary><b>Codi</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n;
  while(cin >> n) {
    vector<int> b(n); // benefici
    for(int& x : b) cin >> x;
    vector<int> p(n); // profunditat maxima
    for(int& x : p) cin >> x;

    vector<int> h(n); // profunditat que excavem
    // A la primera columna, com a molt podem excavar 1 casella
    h[0] = min(1, p[0]);
    // Calculem h[i] per la resta de columnes:
    for(int i = 1; i < n; ++i) {
      h[i] = h[i-1] + 1;
      if(h[i] > p[i]) {
        // si la profunditat maxima es mes petita que la profunditat a la que
        // voliem excavar, actualitzem el seu valor
        h[i] = p[i];
        // i propaguem el nou valor cap enrere, assegurant-nos de no excavar
        // mes d'una casella mes que a la columna de la nostra dreta
        for(int j = i-1; j >= 0; --j) {
          h[j] = min(h[j], h[j+1]+1);
        }
      }
    }
    // a la ultima columna com a molt podem excavar fins a profunditat 1
    if(h[n-1] > 1) {
      h[n-1] = 1;
      for(int j = n-2; j >= 0; --j) {
        h[j] = min(h[j], h[j+1] + 1);
      }
    }
    // calculem el benefici total obtingut
    ll ans = 0; // benefici total
    for(int i = 0; i < n; ++i) {
      ans += ll(b[i])*h[i];
    }
    cout << ans << endl;
  }
}
```
  </details>

  Una manera més ràpida i bonica (tot i que potser una mica menys intuïtiva) és la següent: Comencem des de l'esquerra, i seguim el procediment anterior, però sense tirar enrere si ens trobem amb què $p_i < j$. A continuació fem el mateix començant des de la dreta. Es pot comprovar que la solució òptima consisteix en prendre el mínim entre les dues profunditats (la que hem calculat començant des de l'esquerra i la que hem calculat començant des de la dreta).

  <details>
    <summary><b>Codi</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n;
  while(cin >> n) {
    vector<int> b(n); // benefici
    for(int& x : b) cin >> x;
    vector<int> p(n); // profunditat maxima
    for(int& x : p) cin >> x;

    // Primer iterem d'esquerra a dreta, excavant el maxim possible sense passar-nos
    // de profunditat (i excavant com a molt 1 mes que a la nostra esquerra)
    vector<int> esquerra(n);
    esquerra[0] = min(1, p[0]);
    for(int i = 1; i < n; ++i) {
      esquerra[i] = min(esquerra[i-1]+1, p[i]);
    }

    // Despres iterem de dreta a esquerra, excavant el maxim possible sense passar-nos
    // de profunditat (i excavant com a molt 1 mes que a la nostra dreta)
    vector<int> dreta(n);
    dreta[n-1] = min(1, p[n-1]);
    for(int i = n-2; i >= 0; --i) {
      dreta[i] = min(dreta[i+1]+1, p[i]);
    }

    ll ans = 0; // benefici total
    for(int i = 0; i < n; ++i) {
      // A cada columna fa falta profunditat <= esquerra[i] (per no excavar 2 mes   
      // que a la nostra esquerra) i profunditat <= dreta[i] (per no excavar 2  
      // mes que a la nostra dreta)
      int profunditat = min(esquerra[i], dreta[i]);
      ans += ll(b[i])*profunditat;
    }
    cout << ans << endl;
  }
}
```
  </details>
</details>

<details>
  <summary><b>Solució general</b></summary>
  Passem ara a resoldre el cas general, on $b_i$ pot ser negativa.

  Sigui $f(i, h)$ el màxim benefici que podem obtenir amb les columnes des de 1 fins a $i$, i suposant que a la columna $i$ hem excavat fins a profunditat $h$. Suposeu que hem calculat els valors de $f(j, h)$ per tot $h$ i per tot $j < i$. Com calcularíeu aleshores $f(i, h)$?

  <details>
    <summary><b>Spoiler</b></summary>
    Si a la columna $i$ hem excavat fins a profunditat $h$, aleshores a la columna $i-1$ hem d'haver excavat fins a profunditat $h-1$, $h$ o $h+1$. El benefici màxim per tant serà el màxim entre $f(i-1, h-1)$, $f(i-1, h)$ i $f(i-1,h+1)$, més el benefici corresponent a la columna $i$, que és $h \cdot b_i$.
  </details>

  Amb l'expressió anterior, podem anar calculant els valors de $f(i, h)$ recursivament, tenint en compte que en tot moment necessitem que $h \leq p_i$. Per tal d'evitar repetir càlculs, ens construïm una matriu de mida $n \times \big((n+1)/2 + 1 \big)$ on anem guardant els valors de $f(i, h)$ que ja hem calculat (aquesta tècnica es coneix com a *programació dinàmica*). Observeu que tota solució vàlida no pot excavar més enllà de profunditat $(n+1)/2$, ja que si no no pot arribar a la superfície per les dues bandes.

  <details>
    <summary><b>Solució recursiva</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;
int n;
vector<int> b, p;
vector<vector<ll>> memoria; // aqui guardem els valors de 'dp' que anem calculant

// Definim dp(col, h) com el maxim benefici que podem
// obtenir amb les columnes de 1 fins a 'col', suposant
// que a la columna 'col' hem excavat fins a profunditat 'h'
ll dp(int col, int h) {
  // Per simplificar la implementacio, considerem que la primera columna
  // es la columna 1, i que a la columna 0 estem obligats a excavar a
  // profunditat 0:
  if(col == 0) {
    if(h == 0) return 0;
    return -INF; // retornar un valor negatiu molt gran ens assegura que mai
                 // escollirem aquesta opcio com a optima
  }
  if(h > p[col-1]) return -INF; // p[col-1] ens marca la profunditat maxima a la
                                // qual podem excavar a la columna 'col'
  if(h < 0 or h > (n+1)/2) return -INF;
  // A l'utilitzar el simbol '&', aconseguim que si modifiquem la variable
  // 'ans', tambe es modificara la variable 'memoria[col][h]' automaticament.
  // (internament, li estem passant l'adreça de la variable en lloc d'una copia)
  // Per tant, el valor final que calculem quedara guardat a la matriu 'memoria'.
  ll& ans = memoria[col][h];
  // Si ja hem calculat el resultat previament, el retornem sense fer
  // mes calculs:
  if(ans != -INF) return ans;
  // La resposta sera el maxim entre dp(col-1, h), dp(col-1, h-1) i dp(col, h+1):
  ans = max(dp(col-1, h), dp(col-1, h-1));
  ans = max(ans, dp(col-1, h+1));
  // Li afegim el benefici d'excavar fins 'h' a la columna 'col':
  ans += ll(h) * b[col-1];
  return ans;
}

int main() {
  while(cin >> n) {
    b = vector<int>(n); // benefici
    for(int& x : b) cin >> x;
    p = vector<int>(n); // profunditat maxima
    for(int& x : p) cin >> x;
    // Inicialitzem la matriu on ens guardarem els valors que anem calculant
    // de la funcio 'dp':
    memoria = vector<vector<ll>>(n+1, vector<ll>((n+1)/2 + 1, -INF));
    // A la ultima columna o be excavem 0 o 1, de manera que el benefici maxim
    // sera el maxim entre els dos casos:
    cout << max(dp(n, 0), dp(n, 1)) << endl;
  }
}
```
  </details>

  <details>
    <summary><b>Solució iterativa</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n;
  while(cin >> n) {
    vector<int> b(n); // benefici per casella excavada a cada columna
    for(int& x : b) cin >> x;
    vector<int> p(n); // profunditat maxima a cada columna
    for(int& x : p) cin >> x;

    const ll INF = 1e18;
    // Definim 'dp[col][h]' com el maxim benefici que podem obtenir
    // des de la columna 1 fins a la columna 'col', suposant que a la
    // columna 'col' hem excavat fins a profunditat 'h'.
    // Observem que la profunditat maxima que podem excavar es (n+1)/2
    vector<vector<ll>> dp(n+1, vector<ll>((n+1)/2 + 1, -INF));
    // Afegim una columna 0 a l'esquerra on estem obligats a excavar a
    // profunditat 0. Aixi ens assegurem que a la columna 1 excavarem maxim 1
    dp[0][0] = 0;
    for(int col = 1; col <= n; ++col) {
      for(int h = 0; h <= (n+1)/2; ++h) {
        if(h > p[col-1]) break; // ens passem de profunditat
        dp[col][h] = dp[col-1][h];
        if(h > 0) { // si h == 0 no comprovem el cas h-1
          dp[col][h] = max(dp[col][h], dp[col-1][h-1]);
        }
        if(h < (n+1)/2) { // si h == (n+1)/2, no comprovem el cas h+1
          dp[col][h] = max(dp[col][h], dp[col-1][h+1]);
        }
        dp[col][h] += ll(h)*b[col-1]; // afegim el benefici de la columna actual
      }
    }
    // per tal que la solucio sigui valida, a la ultima columna hem
    // d'haver excavat a profunditat 0 o 1:
    cout << max(dp[n][0], dp[n][1]) << endl;
  }
}
```
  </details>
</details>


## [Problema C6. Nombres de Bell](https://jutge.org/problems/P70740_ca) <a name="C6"/>

<b>Autor:</b> Jordi Petit <br>
<b>Nombre de ACs:</b> 2 <br>
<b>Primer AC:</b> Sergio Domínguez

Hi ha diferents maneres de calcular els [nombres de Bell](https://en.wikipedia.org/wiki/Bell_number),
la més intuïtiva requereix una mica de programació dinàmica:

En comptes de pensar com partir un conjunt de $n$ elements en diferents subconjunts
d'elements no buits, podem pensar en com partir-los en exactament $k$ subconjunts
no buits. Aquests valors es coneixen com a [nombres d'Stirling del segon tipus](https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind). A partir d'aquí, cal pensar com afegir un nou element
en aquest partició. Ho expliquem amb més claredat en el codi (utilitzar C++ aquí no és bona idea
ja que els valors de l'output superen els $2^{64} - 1$: el màxim valor que pot tenir un
`unsigned long long int`):

<details>
  <summary><b>Codi</b></summary>

```python
from easyinput import read

N = 400

# dp[n][k] ens dirà les maneres de partir n elements en k grups no buits
# (dp[n][k] representa un nombre d'Stirling del segon tipus)
dp = [[0 for j in range(N + 1)] for i in range(N + 1)]

# Donada una partició de n - 1 elements en k grups,
# hi podem afegir un n-èssim element o bé posant-lo en
# algun d'aquests k grups, o bé posant-lo aïllat en un (k + 1)-èssim grup
for n in range(1, N + 1):
    for k in range(1, n):
        dp[n][k] += k*dp[n - 1][k] + dp[n - 1][k - 1]
    dp[n][n] = 1        # Per raons òbvies

# La solució per un cert n serà
# bell[n] = dp[n][1] + dp[n][2] + ... + dp[n][n]
bell = [sum(v[1:n+1]) for v in dp]

while True:
    n = read(int)
    if n is None:
        break
    print(bell[n])
```
</details>

Un truc típic en aquests problemes on la $n$ màxima és petita és precalcular-se tots els nombres de Bell localment amb el codi anterior en Python i llavors enviar un codi en C++ que tingui totes les respostes en un vector, i que per cada entrada retorni la resposta sense haver de calcular res.

En aquest problema això no era necessari, però va bé tenir-ho en compte si teniu una solució que dona TLE i el nombre d'inputs diferents possibles és petit.

## [Problema C7. Avaries](https://jutge.org/problems/P67717_ca) <a name="C7"/>

<b>Autor:</b> Xavier Povill <br>
<b>Nombre de ACs:</b> 1 <br>
<b>Primer AC:</b> Innokentiy Kaurov

Per cada vèrtex, hem de comptar el nombre de components connexos en que quedaria separat el graf si eliminéssim aquell vèrtex. Per tal de calcular-ho eficientment, modifiquem lleugerament l'algorisme clàssic per calcular *punts d'articulació* d'un graf (vegeu [aquest tutorial](https://cp-algorithms.com/graph/cutpoints.html)).

Al link anterior podeu trobar una explicació més detallada, però la idea general de l'algorisme és fer un DFS començant des d'un vèrtex arbitrari, i anar calculant per cada vèrtex el *temps d'entrada* `tin[v]` (que definim de manera que `tin[a] < tin[b]` si visitem `a` abans que `b` en el DFS) i un valor `low[v]` que és el mínim entre `tin[v]` i `tin[u]`, per tot $u$ que estigui connectat directament amb un descendent de $v$ (és a dir, per tota back-edge des d'un descendent de $v$ en el DFS-tree).

Aleshores, és fàcil veure que $u$ formarà un component connex nou a l'eliminar $v$ si, i només si, `low[u] >= tin[v]` (és a dir, si no té cap connexió amb un antecessor de $v$).

<details>
  <summary><b>Codi</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> tin; // temps d'entrada al vertex.
vector<int> low; // minim entre el temps d'entrada i el temps
                 // d'entrada dels vertexs accessibles des de
                 // back-edges dels descendents.
vector<int> ans; // nombre de components connexes en que
                 // es separa el graf.
int curtime; // temps actual.
const int INF = 1e9;

void dfs(int v, int pare) {
  tin[v] = low[v] = curtime;
  ++curtime;
  for(int u : G[v]) {
    if(u == pare) {
      ans[v]++;
      continue;
    }
    if(tin[u] == -1) {
      dfs(u, v);
      if(low[u] >= tin[v]) {
                // a l'eliminar `v`, `u` formara un component connex nou
        ans[v]++;
      }
      low[v] = min(low[v], low[u]);
    }
    else {
      low[v] = min(low[v], tin[u]);
    }
  }
}

int main() {
  int n, m;
  while(cin >> n >> m) {
    G = vector<vector<int>>(n);
    for(int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    tin = vector<int>(n, -1);
    low = vector<int>(n);
    ans = vector<int>(n, 0);
    curtime = 0;
    dfs(0, -1);
    for(int i = 0; i < n; ++i) {
      cout << i << ": " << ans[i] << endl;
    }
    cout << string(10, '-') << endl;
  }
}
```
</details>

<details>
  <summary><b>Solució parcial</b></summary>

  Per obtenir la puntuació parcial s'havien de resoldre els casos on el graf té com a molt un cicle.

  En primer lloc, si el graf no té cicles sabem que serà un [arbre](https://ca.wikipedia.org/wiki/Arbre_(teoria_de_grafs)) (perquè és acíclic i connex). En aquest cas, si eliminem el vèrtex $v$, cada veí de $v$ formarà un component connex diferent. Per tant, el nombre de components connexos és simplement el *grau* de $v$ (és a dir, el seu nombre de veïns).

  En cas que el graf tingui un únic cicle $C$, si $v \notin C$ continuem tenint que el nombre de components en que queda dividit el graf a l'eliminar $v$ és el grau de $v$. En canvi, si $v \in C$, els dos veïns de $v$ pertanyents al cicle estaran units per un camí i formaran part del mateix component connex. Així doncs, el nombre de components connexos és $\text{grau}(v)-1$.

  Per tal de detectar quins vèrtexs estan al cicle, podem fer un DFS des d'un vèrtex arbitrari, guardant els pares de cada node. Si arribem a un vèrtex que ja hem visitat abans i que no és el nostre pare, voldrà dir que hem trobat un cicle. Per tal de trobar tots els vèrtexs del cicle, anem tirant enrere per la llista de pares fins a tornar al vèrtex original.

  <details>
    <summary><b>Codi</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> pare; // guarda el pare de cada vertex en el DFS
vector<bool> cicle; // true si el vertex esta al cicle
vector<bool> vis; // true si ja hem visitat el vertex en el DFS
bool cicle_trobat;

void dfs(int v) {
  vis[v] = true;
  for(int u : G[v]) {
    if(cicle_trobat) return;
    if(u == pare[v]) continue;
    if(vis[u]) {
      cicle[v] = true;
      int x = pare[v];
      while(x != u) {
        cicle[x] = true;
        x = pare[x];
      }
      cicle[u] = true;
      cicle_trobat = true;
    }
    else {
      pare[u] = v;
      dfs(u);
    }
  }
}

int main() {
  int n, m;
  while(cin >> n >> m) {
    G = vector<vector<int>>(n);
    for(int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    pare = vector<int>(n, -1);
    cicle = vector<bool>(n, false);
    vis = vector<bool>(n, false);
    cicle_trobat = false;
    dfs(0);
    for(int i = 0; i < n; ++i) {
      cout << i << ": " << int(G[i].size()) - int(cicle[i]) << endl;
    }
    cout << string(10, '-') << endl;
  }
}
```    
  </details>

</details>


## [Problema Q4. Raó àuria](https://jutge.org/problems/P94346_ca) <a name="Q4"/>

<b>Autor:</b> Fèlix Moreno <br>
<b>Nombre de ACs:</b> 0 <br>
<b>Primer AC:</b> :-(

L'algoritme és "senzill". A cada pas, busquem el valor més gran $p$ tal que
$n \geq \varphi^p$. Llavors, el $p$-èssim dígit (vigileu que $p$ també pot ser negatiu)
de $n$ en base $\varphi$ valdrà $1$. Repetiu el procediment amb $n - \varphi^p$ fins
que el nombre restant sigui $0$.

__Repte__: Us animem a que demostreu vosaltres mateixos (i si voleu, podeu enviar-nos la demostració)
que qualsevol enter $n$
té una expressió única i amb finits decimals en base $\varphi$, i que es
pot trobar mitjançant l'algorisme que acabem de mencionar. Pistes:

1. Demostreu que l'algorisme mencionat funciona, és a dir, que dóna una expressió de $n$ en base $\varphi$.
2. Demostreu que tot natural $n$ té una expressió finita en base $\varphi$ (podeu fer-ho per inducció).
3. Demostreu que tot real es pot expressar d'una manera única en base $\varphi$ (amb excepció de nombres acabats en
$...1010101010...$ periòdic en base $\varphi$ (l'anàleg a $1 = 0.99999...$ en base $10$))
4. Demostreu que l'algorisme no donarà mai $...1010101010...$ periòdic, i que per tant assolirà l'expressió finita única de $n$ en base $\varphi$.

Si implementeu directament aquest algorisme, probablement no obtindreu la puntuació completa, ja que els floats o doubles no tenen suficients decimals com per donar la resposta exacta. Per evitar problemes de precisió, hem de buscar alguna manera de fer tot els càlculs amb nombres enters.

__Solució 1:__

La idea és expressar totes les potències de $\varphi$ de la forma $a + b \varphi$, on $a$ i $b$ són enters. Això sempre es pot aconseguir, ja que $\varphi^2 = \varphi + 1$, de manera que podem anar reduint totes les potències de $\varphi$ fins a arribar a una expressió de la forma anterior.

Per exemple:

$$
\begin{gather}
\varphi^3 = \varphi\cdot \varphi^2 = \varphi(\varphi + 1) = \varphi^2 + \varphi = 2 \varphi + 1 \\
\varphi^4 = \varphi \cdot \varphi^3 = \varphi \cdot (2 \varphi + 1) = 2 \varphi^2 + \varphi = 3 \varphi + 2
\end{gather}
$$

Observeu que la suma, resta i multiplicació de nombres de la forma $a + b \varphi$ dona com a resultat nombres de la mateixa forma:

$$
\begin{gather}
(a + b \varphi) + (c + d\varphi) = (a + c) + (b + d)\varphi \\
(a + b \varphi) - (c + d\varphi) = (a + c) - (b + d)\varphi \\
(a + b \varphi) \cdot (c + d\varphi) = ac + (bc + ad)\varphi + bd \varphi^2 = (ac + bd) + (bc + ad + bd)\varphi
\end{gather}
$$

També hem de saber comparar dos nombres de la forma anterior. La idea és que $a + b \varphi < c + d \varphi$ si $a-c < (d-b)\varphi$. Si els dos coeficients tenen signe diferent, la comparació és trivial. Si tenen el mateix signe, substituïm $\varphi = (1 + \sqrt{5})/2$, aïllem $\sqrt{5}$ i elevem al quadrat els dos costats de la desigualtat. Així aconseguim trobar una condició que només utilitzi nombres enters.

<details>
<summary><b>Codi</b></summary>

```python3
## CONSTANTS

ZERO = (0, 0)           # 0
U = (1, 0)              # 1
PHI = (0, 1)            # φ
INV_PHI = (-1, 1)       # 1/φ (= φ - 1)

## OPERACIONS

# Retorna la resta (a[0] + a[1]*φ) - (b[0] + b[1]*φ)
def resta(a, b):
  return (a[0] - b[0], a[1] - b[1])

# Retorna el produte (a[0] + a[1]*φ) * (b[0] + b[1]*φ)
def prod(a, b):
  return (a[0]*b[0] + a[1]*b[1], a[0]*b[1] + a[1]*b[0] + a[1]*b[1])

# Calcula x^b
def power(x, b):
    pot = U
    for i in range(b):
        pot = prod(pot, x)
    return pot

# Calculem φ^e
def potencia_phi(e):
    return power(PHI, e) if e >= 0 else power(INV_PHI, -e)

# Retorna True si a[0] + a[1]*φ <= b[0] + b[1]*φ
# Desenvolupant, això és equivalent a dir:
# 2*(a[0] - b[0]) + a[1] - b[1] <= √5 (b[1] - a[1])
def leq(a, b):
  lhs = 2*(a[0] - b[0]) + a[1] - b[1]
  rhs = b[1] - a[1]
  if lhs <= 0 and rhs >= 0: return True
  if lhs >= 0 and rhs <= 0: return False
  if lhs < 0 and rhs < 0: return lhs**2 >= 5*rhs**2
  if lhs > 0 and rhs > 0: return lhs**2 <= 5*rhs**2

## SOLUCIÓ

# Retorna el maxim p tal que cur >= φ^p
def max_exponent(x):
    p = 0
    while True:
        if not leq(potencia_phi(p + 1), x):
            return p
        p += 1

# Retorna la llista dels índexos que valen 1 a la representació de x en base φ
def llista_indexos(cur, pot):
    indexos = []
    while cur != ZERO:
        if leq(potencia_phi(pot), cur):
            indexos.append(pot)
            cur = resta(cur, potencia_phi(pot))
        pot -= 1

    return indexos

# Passa de la llista de indexos a l'string format per les diferencies
def indexos_to_string(llista):
    llista_diferencies = [a - b - 1 for a, b in zip(llista, llista[1:])]
    return ''.join(str(x) for x in llista_diferencies)

# Passa de la llista de indexos a l'string format per les diferencies
def to_string(indexos):
    indexos_pos = [x for x in indexos if x >= 0] + [-1]
    indexos_neg = [0] + [x for x in indexos if x < 0]
    return indexos_to_string(indexos_pos) + '-' + indexos_to_string(indexos_neg)

def resol(n):
    cur = [n, 0]
    pot = max_exponent(cur)
    indexos = llista_indexos(cur, pot)
    return to_string(indexos)

for n in [10, 201, 10**30]:
    print(resol(n))
```
</details>

Si voleu aprofitar per aprendre una mica de Python avançat, us deixem una solució
alternativa usant classes i [operadors màgics](https://www.tutorialsteacher.com/python/magic-methods-in-python) de Python.

<details>
<summary><b>Codi</b> (usant operadors màgics)</summary>

```python3
# Representa nombres de l'estil a + bφ
class RepresentacioPhi:
    # Inicia la classe (donant els valors de a i b)
    def __init__(self, a, b):
        self.a = a
        self.b = b

    # Operador -
    def __sub__(self, other):
        return RepresentacioPhi(self.a - other.a, self.b - other.b)

    # Operador -=
    def __isub__(self, other):
        prod = self - other
        self.a, self.b = prod.a, prod.b
        return self

    # Operador *
    def __mul__(self, other):
        return RepresentacioPhi(self.a*other.a + self.b*other.b, self.a*other.b + self.b*other.a + self.b*other.b)

    # Operador *=
    def __imul__(self, other):
        prod = self * other
        self.a, self.b = prod.a, prod.b
        return self

    # Operador **
    def __pow__(self, e):
        pot = RepresentacioPhi(1, 0)        # pot = 1
        for i in range(e):
            pot *= self
        return pot

    # Operador <=
    def __le__(self, other):
        lhs = 2*(self.a - other.a) + self.b - other.b
        rhs = other.b - self.b
        if lhs <= 0 and rhs >= 0: return True
        if lhs >= 0 and rhs <= 0: return False
        if lhs < 0 and rhs < 0: return lhs**2 >= 5*rhs**2
        if lhs > 0 and rhs > 0: return lhs**2 <= 5*rhs**2

    # Operador ==
    def __eq__(self, other):
        return self.a == other.a and self.b == other.b

    # Operador !=
    def __ne__(self, other):
        return not (self == other)

## CONSTANTS
ZERO = RepresentacioPhi(0, 0)           # 0
PHI = RepresentacioPhi(0, 1)            # φ
INV_PHI = RepresentacioPhi(-1, 1)       # 1/φ (= φ - 1)

# Calculem φ^e
def potencia_phi(e):
    return PHI**e if e >= 0 else INV_PHI**(-e)

# Retorna el maxim p tal que cur >= φ^p
def max_exponent(x):
    p = 0
    while True:
        if not PHI**(p + 1) <= x:
            return p
        p += 1

# Retorna la llista dels índexos que valen 1 a la representació de x en base φ
def llista_indexos(cur, pot):
    indexos = []
    while cur != ZERO:
        if potencia_phi(pot) <= cur:
            indexos.append(pot)
            cur -= potencia_phi(pot)
        pot -= 1
    return indexos

# Passa de la llista de indexos a l'string format per les diferencies
def indexos_to_string(llista):
    llista_diferencies = [a - b - 1 for a, b in zip(llista, llista[1:])]
    return ''.join(str(x) for x in llista_diferencies)

# Passa de la llista de indexos a l'string format per les diferencies
def to_string(indexos):
    indexos_pos = [x for x in indexos if x >= 0] + [-1]
    indexos_neg = [0] + [x for x in indexos if x < 0]
    return indexos_to_string(indexos_pos) + '-' + indexos_to_string(indexos_neg)

def resol(n):
    cur = RepresentacioPhi(n, 0)
    pot = max_exponent(cur)
    indexos = llista_indexos(cur, pot)
    return to_string(indexos)

for n in [10, 201, 10**30]:
    print(resol(n))
```
</details>

__Solució 2:__

Les dues solucions anteriors es basaven en expressar les potències de $\varphi$ en una forma *canònica* que ens permetés operar amb elles treballant només amb enters. Una altra forma d'enfocar el problema és partir de l'expressió:

$$
n = \dots + 0\cdot \varphi^2 + 0 \cdot \varphi + n \cdot 1 + 0 \cdot \varphi^{-1} + \dots
$$

Llavors, mentre tinguem coeficients més grans que 1, restem $2$ al coeficient de la posició $k$ i afegim $1$ a les posicions $k + 1$ i $k-2$.

Això no modifica el valor de l'expressió, ja que $2 = 1 + 1 = 1 + \varphi^{-1} + \varphi^{-2} = \varphi + \varphi^{-2}$, i es pot demostrar que amb un nombre finit d'aquestes operacions acabem obtenint una expressió amb només 0's i 1's. A l'acabar, per eliminar els 1's consecutius, substituïm un 1 a la posició $k$ i un 1 a la posició $k+1$ per un 1 a la posició $k + 2$ (i tornem a aplicar novament el procediment de reducció anterior).

L'avantatge d'aquesta solució és que es pot implementar directament en C++ sense haver d'utilitzar enters excessivament grans. No obstant això, el codi resultant és més complicat que els dos codis anteriors.
