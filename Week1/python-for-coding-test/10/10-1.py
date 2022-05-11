# 기본적인 서로소 집합 알고리즘
def find_parent(parent, x):
    if parent[x] != x:
        return find_parent(parent, parent[x])
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

for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent,a,b)

# 각 원소가 속한 집합 출력
print('각 원소가 속한 집합: ')
for i in range(1, v+1):
    print(find_parent(parent,i), end=' ')
    
print()

# 부모 테이블 출력
print('부모 테이블: ')
for i in range(1,v+1):
    print(parent[i], end=' ')
    