from math import isqrt      # Part entera de l'arrel quadrada

def es_quadrat_perfecte(x):
    return isqrt(x)**2 == x

suma = 102      # El valor de a + b
while True:
    a = 1
    b = suma - 1
    while b > a + 100:
        if es_quadrat_perfecte(a**2 + b**2):
            print(suma)     # Escriu la resposta
            exit(0)         # Mata el programa
        a += 1
        b -= 1
    suma += 1