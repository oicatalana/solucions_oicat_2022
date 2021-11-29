# Provem nombres a partir de 2
n = 2
while True:
    # Mirem si n només té 0s i 1s en les bases 3, 4 i 5
    # (en base 2 sempre tindrà 0s i 1s)
    funciona = True
    for base in [3, 4, 5]:
        # Copiem n a x, i anem mirant els dígits de x en la base
        x = n
        while x > 0:
            if x % base >= 2:
                funciona = False
            x //= base

    # Si és així, parem. Si no, augmentem n en 1
    if funciona:
        break
    n += 1

print(n)