# 경로 압축 사용
def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    else:
        return x

def union_parent(parent, a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


v, e = map(int, input().split())
parent = [0] * (v + 1)

for i in range(1, v + 1):
    parent[i] = i

edges = []
result = 0

for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append({cost,a,b})
    
edges.sort()

for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a)!= find_parent(parent,b):
        union_parent(parent,a,b)
        result+=cost

print(result)