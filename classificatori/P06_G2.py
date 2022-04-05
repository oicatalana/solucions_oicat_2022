from PIL import Image, ImageDraw

# Llegim l'entrada
n = int(input())
f = input()
a = input()
b = input()
llista = [int(input()) for _ in range(n)]

# Creem la imatge
img = Image.new('RGB', [215, 215], f)
dib = ImageDraw.Draw(img)

# tocat[i] és True si i només si el patró passa pel punt i
tocat = [False]*10
for i in llista:
    tocat[i] = True 

# Dibuixem els punts en funció de si pertanyen al patró
for y in range(3):
    for x in range(3):
        dib.ellipse((
            20 + 65*x,
            20 + 65*y,
            20 + 65*x + 44,
            20 + 65*y + 44,
        ), a if tocat[3*y + x + 1] else b)

# Dibuixem els segments que composen el patró
for p, q in zip(llista, llista[1:]):
    dib.line([
        (42 + 65*((p - 1)%3), 42 + 65*((p - 1)//3)),
        (42 + 65*((q - 1)%3), 42 + 65*((q - 1)//3))
    ], fill=a, width=3)

# Guardem la imatge
img.save('output.png')