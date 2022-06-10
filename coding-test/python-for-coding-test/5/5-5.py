# 인접 행렬, 인접 리스트 방식의 차이

graph = [[] for _ in range(3)]
INF = 999999999

# 인접 행렬 (O(1))
if graph[1][7] != INF:
    # do somthing
    print('vetex 1 and 7 are connected')


# 인접 리스트 (O(V))
for vertex, weight in graph[1]: 
    if vertex == 0 and weight != INF:
        print('vertex: ' , vertex)
        print('weight: ' , weight)
        print('vertex 1 and 0 are connected!')
