def es_descomposable(n):
    # Guardem n^2 com un string s amb mida k
    s = str(n**2)
    k = len(s)

    # s[:i] ens dona els primers i caràcters de s
    # s[i:] ens dona els caràcters de s si hi traiem els i primers
    for i in range(1, k):
        if int(s[:i]) + int(s[i:]) == n:
            return True

    return False

suma = 0
for n in range(4, 22022022 + 1):
    if es_descomposable(n):
        suma += n

print(suma)