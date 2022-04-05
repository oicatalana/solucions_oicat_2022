from PIL import Image, ImageDraw

# Llegim les variables
col_peix = input()
col_fons = input()
n = int(input())

# Variables auxiliars
MARGE = 10
INCREMENT = (n - 1)//2

# Creem la imatge
img = Image.new('RGB', (n + 2*MARGE + INCREMENT, n + 2*MARGE), col_fons)
dib = ImageDraw.Draw(img)

# Dibuixem el triangle
dib.polygon([
    (MARGE, MARGE),
    (MARGE + INCREMENT, MARGE + INCREMENT),
    (MARGE, MARGE + 2*INCREMENT)
], col_peix)

# Dibuixem el quadrat
dib.polygon([
    (MARGE + INCREMENT, MARGE + INCREMENT),
    (MARGE + 2*INCREMENT, MARGE),
    (MARGE + 3*INCREMENT, MARGE + INCREMENT),
    (MARGE + 2*INCREMENT, MARGE + 2*INCREMENT)
], col_peix)

# Guardem la imatge
img.save('output.png')
