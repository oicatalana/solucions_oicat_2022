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