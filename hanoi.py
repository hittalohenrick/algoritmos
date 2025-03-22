def hanoi(n, origem, destino, auxiliar):
    if n == 1:
        return [(origem, destino)]
    
    passos = hanoi(n - 1, origem, auxiliar, destino)
    passos.append((origem, destino))
    passos += hanoi(n - 1, auxiliar, destino, origem)
    
    return passos

n = 4
movimentos = hanoi(n, 'A', 'C', 'B')

for i, (de, para) in enumerate(movimentos, 1):
    print("Passo", i, ":", de, "->", para)
