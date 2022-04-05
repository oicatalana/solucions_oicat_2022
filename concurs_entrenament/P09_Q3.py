from math import isqrt      # Part entera de l'arrel quadrada

def es_quadrat_perfecte(x):
    return isqrt(x)**2 == x

s = 102      # El valor de a + b
while True:
    # Comprovem tots els valors a, b tals que a + b == s i b > a + 100
    a, b = 1, s - 1
    while b > a + 100:
        if es_quadrat_perfecte(a**2 + b**2):
            print(s)            # Escriu la resposta
            exit(0)             # Mata el programa
        
        a, b = a + 1, b - 1     # Provem amb els següents valors

    # Si cap ha funcionat, augmentem s en 1
    s += 1