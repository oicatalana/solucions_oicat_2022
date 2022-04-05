from PIL import Image, ImageDraw

# Llegim l'entrada
f = input()
c = input()
n = int(input())
a = int(input())

# Creem la imatge
img = Image.new('RGB', (a*(2*n + 1), a*(n + 1)), f)
dib = ImageDraw.Draw(img)    

# Fila actual (inicialment, la fila 0)
fila_actual = [j == n for j in range(2*n + 1)]

# Diu si la k-èssima posició de la fila actual està ocupada
def k_essim_element(k):
    return fila_actual[k] if 0 <= k < 2*n + 1 else False 

for i in range(n + 1):
    # Dibuixem la fila actual
    for j in range(2*n + 1):
        if fila_actual[j]:
            dib.polygon([
                (a*j, a*i),
                (a*(j + 1) - 1, a*i),
                (a*(j + 1) - 1, a*(i + 1) - 1),
                (a*j, a*(i + 1) - 1)],
            c)
    
    # Actualitzem la fila
    fila_actual = [k_essim_element(j - 1) ^ (k_essim_element(j) | k_essim_element(j + 1)) for j in range(2*n + 1)]

# Guardem la imatge
img.save('output.png')
