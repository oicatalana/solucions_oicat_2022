from PIL import Image, ImageDraw

# Llegim les variables
f = input()
n = int(input())
a = int(input())
r1 = int(input())
g1 = int(input())
b1 = int(input())
r2 = int(input())
g2 = int(input())
b2 = int(input())

# Creem la imatge
img = Image.new('RGB', (a*n, a*n), f)
dib = ImageDraw.Draw(img)

# Dibuixa un quadrat amb cantonada superior esquerra (x, y), costat a, i color col
def quadrat(x, y, col):
    dib.polygon([(x, y), (x + a - 1, y), (x + a - 1, y + a - 1), (x, y + a - 1)], col)

# Iterem per cada columna
for i in range(n):
    # Si la columna és central, pintem amb la mitjana dels dos colors
    if 2*i + 1 == n:
        quadrat(a*i, a*i, ((r1 + r2) // 2, (g1 + g2) // 2, (b1 + b2) // 2))
    else:
        quadrat(a*i, a*i, (r1, g1, b1))
        quadrat(a*i, a*(n - i - 1), (r2, g2, b2))

img.save('output.png')
