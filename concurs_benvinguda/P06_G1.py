from PIL import Image, ImageDraw

# Llegim l'entrada
n = int(input())

# Creem la imatge, amb la mida i el color de fons corresponents
img = Image.new('RGB', (3*n, 3*n), 'Beige')
dib = ImageDraw.Draw(img)

# Dibuixem el polígon, donant els vèrtexs en ordre
# Vigileu amb no pintar píxels de més!
dib.polygon([
    (n, 0),
    (2*n - 1, 0),
    (3*n - 1, n),
    (3*n - 1, 2*n - 1),
    (2*n - 1, 3*n - 1),
    (n, 3*n - 1),
    (0, 2*n - 1),
    (0, n)
], 'Red')

# Guardem la imatge
img.save('output.png')
