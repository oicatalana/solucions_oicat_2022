from PIL import Image, ImageDraw

# Llegim l'entrada
n = int(input())

# Creem la imatge, amb la mida corresponent
# Posem el gris de color de fons per estalviar-nos el més pesat,
# que serà pintar els rectangles verticals i horitzontals
img = Image.new('RGB', (175*n - 25, 175*n - 25), 'Grey')
dib = ImageDraw.Draw(img)

# Dibuixem els n x n quadrats negres
for i in range(n):
	for j in range(n):
		dib.polygon([
			(175*i, 175*j),
			(175*i + 149, 175*j),
			(175*i + 149, 175*j + 149),
			(175*i, 175*j + 149)
		], 'Black')

# Dibuixem els (n - 1) x (n - 1) cercles blancs
for i in range(n - 1):
	for j in range(n - 1):
		dib.ellipse([
			175*i + 150,
			175*j + 150,
			175*i + 174,
			175*j + 174
		], 'White')

# Guardem la imatge
img.save('output.png')
