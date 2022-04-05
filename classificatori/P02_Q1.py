# SOLUCIÓ 1 (La bona):
# Per ser múltiple de 18 haurà de ser múltiple de 2 i de 9.
# No importa com ordenem els dígits, el nombre resultant
# sempre serà múltiple de 9 ja que la suma dels seus dígits sempre serà
# 1 + 2 + ... + 9 = 45, que és múltiple de 9.
# Per a què sigui múltiple de 2, només cal que el darrer dígit sigui parell.
# Per tant, tenim 4 opcions possibles per escollir l'últim dígit (2, 4, 6 i 8)
# i només ens quedarà ordenar els 8 dígits restants d'alguna de les 8!
# (8 factorial) maneres possibles.
# La solució per tant serà 4 x 8! = 161280

# SOLUCIÓ 2 (La de flipao):
from itertools import permutations
print(len(list(filter(
    lambda n : n % 18 == 0,
    (int(''.join(map(str, perm))) for perm in permutations(list(range(1, 10))))
))))
