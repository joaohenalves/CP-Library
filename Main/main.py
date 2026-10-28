from pyscipopt import Model, quicksum

def transpose_matrix_loops(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    transposed = [[0 for _ in range(rows)] for _ in range(cols)]

    for i in range(rows):
        for j in range(cols):
            transposed[j][i] = matrix[i][j]
    return transposed

modelo = Model("Modelo de PLI para o Problema das Tarefas")

#modelo.readProblem("mochila.lp")

c = []
a = []
x = []

m, n = map(int, input().split())

for j in range(m):
    vet = list(map(int, input().split()))
    c.append(vet)

c = transpose_matrix_loops(c)

for j in range(m):
    vet = list(map(int, input().split()))
    a.append(vet)

a = transpose_matrix_loops(a)

b = list(map(int, input().split()))

for i in range(n):
    empty = []
    for j in range(m):
        empty.append(modelo.addVar(f"x_{i}_{j}", vtype = "INTEGER", lb = 0, ub = 1))
        #x[i] = modelo.addVar(f"x_{i}", vtype = "BINARY")
    x.append(empty)

for i in range(n):
    modelo.addCons(quicksum(x[i][j] for j in range(m)) == 1)
    #modelo.addCons(x[i] + x[j] <= 1, f"Restricao x{i} x{j}")

for j in range(m):
    modelo.addCons(quicksum(x[i][j] * a[i][j] for i in range(n)) <= b[j])

modelo.setObjective(quicksum(x[i][j] * c[i][j] for i in range(n) for j in range(m)),
    sense = "minimize")

modelo.writeProblem("modelo.lp")

modelo.setParam("presolving/maxrounds", 0)
modelo.setParam("separating/maxrounds", 0)
modelo.setParam("limits/time", 300)
modelo.optimize()

# if modelo.getStatus() == "optimal":
#     print(f"Valor ótimo: {modelo.getObjVal()}")
#     print("Solução Ótima:")
#     #for v in modelo.getVars():
#         #print(f"{v.name}: {modelo.getVal(v)}")
# else:
#     print("Solução ótima não encontrada.")

if modelo.getNSols() > 0:
    print(f"Melhor valor encontrado: {modelo.getObjVal()}")
else:
    print("Nenhuma solução viável encontrada.")