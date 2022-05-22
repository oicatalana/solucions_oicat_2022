# Problemes
* [Problema Q1. Onze llibres](#Q1)
* [Problema C1. Esperança de vida](#C1)
* [Problema G1. Dígits iguals](#G1)
* [Problema C2. Estudiant nefast](#C2)
* [Problema Q2. Hotel Vela](#Q2)


# [Problema Q1. Onze llibres](https://jutge.org/problems/P57678_ca) <a name="Q1"/>

Clarament haurem de posar els 6 llibres blaus separats pels altres 5 llibres,
per tant només ens queda escollir on posem aquests 5.

Com que ja estan separats pels llibres blaus, només ens cal escollir les 2 posicions
d'aquestes 5 on hi posarem els llibres vermells (les altres 3 seran pels llibres grocs).

Podem trobar aquesta quantitat a mà o fent una mica de [combinatòria bàsica](https://ca.wikipedia.org/wiki/Coeficient_binomial#Interpretaci%C3%B3_combinat%C3%B2ria).

# [Problema C1. Esperança de vida](https://jutge.org/problems/P12454_ca) <a name="C1"/>

És suficient amb anar llegint les dades i anar actualitzant la informació
del millor país segons els tres criteris diferents en la sortida.

En aquests casos, cal anar amb compte amb com inicialitzem les variables:
volem que després de llegir el primer país aquest sigui el millor en tots tres!

__Codi__:
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

# [Problema G1. Dígits iguals](https://jutge.org/problems/P27390_ca) <a name="G1"/>

En tenim prou amb anar comprovant la condició per tots els punts i pintar-lo
amb el color que toca. Si rebeu un _time limit exceeded_, 
és una bona idea plantejar-se pintar tot del color de fons `f`,
i després només pintar els punts que toquin amb el color `c`, que serà
el que aparegui de forma menys freqüent.

__Codi__:
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
        digit_centenes_producte = ((x * y)//10)%10
        if digit_unitats_suma == digit_centenes_producte:
            dib.point((x, y), c)

# Guardem la imatge
img.save("output.png")
```

__Repte:__ Podríeu demostrar matemàticament que la imatge és
una repetició de patrons de mida $100 \times 100$?

# [Problema C2. Estudiant nefast](https://jutge.org/problems/P81388_ca) <a name="C2"/>

Sí, aquest problema està basat en fets reals. Es pot solucionar de diverses
maneres, potser aquesta és la més intuïtiva: ordenem totes les notes,
a continuació les anem posant en ordre en un vector, però fent dues passades:
primer una amb les notes aprovades, i després una amb les suspeses.

__Codi__:
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
        bool hem_escrit = false;
        for (int i = 0; i < n; ++i) {
            if (i > 0)
                cout << ' ';
            cout << v[i];
        }
        cout << endl;
    }   
}
```

__Repte__: Intenteu entendre aquesta solució d'"una línia":
```py
import sys

for line in sys.stdin:
    print(*sorted([int(s) for s in line.rstrip('\n').split()][1:], key=lambda x:(x < 500000, x)))
```

# [Problema Q2. Hotel Vela](https://jutge.org/problems/P24906_ca) <a name="Q2"/>

Podem simular el que ens diu l'enunciat: iterem en ordre per cada hoste,
i per cadascun d'aquests fem que canviïn l'estat de les portes que toquen.

__Codi__ (si no enteneu el `range()` amb tres paràmetres, us deixem un __[repte](https://jutge.org/problems/P93780_ca)__):
```py
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