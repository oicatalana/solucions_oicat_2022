from PIL import Image, ImageDraw

# Llegim l'entrada
n = int(input())
m = int(input())
k = int(input())
p = input()
c = input()

# Creem la imatge
img = Image.new('RGB', [10*m, 10*n])
dib = ImageDraw.Draw(img)

# eratostenes[i] serà True si i només si i es troba a la nosta llista
N = n*m
eratostenes = [True]*(N + 1)
eratostenes[0] = False
eratostenes[1] = False

# Actualizem la llista segons ens indica l'enunciat:
# Iterem per cada j des de 2 fins a k. Si j pertany a la llista,
# hi esborrarem 2j, 3j, 4j, ...
for j in range(2, k + 1):
    if eratostenes[j]:
        for i in range(2*j, N + 1, j):
            eratostenes[i] = False

# Funció per dibuixar un quadrat
def dibuixa_quadrat(y, x, col):
    dib.polygon((
        (10*x, 10*y),
        (10*x, 10*y + 9),
        (10*x + 9, 10*y + 9),
        (10*x + 9, 10*y)
    ), col)

# Dibuixem els quadrats
for i in range(n):
    for j in range(m):
        dibuixa_quadrat(i, j, p if eratostenes[m * i + j + 1] else c)

# Guardem la imatge
img.save('output.png')