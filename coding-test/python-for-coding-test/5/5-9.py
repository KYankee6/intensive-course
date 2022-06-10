# BFS

from collections import deque
def bfs(graph, start, visited):
    queue = deque()
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True

graph = [[] for _ in range(3)]
visited = [False] * 9
bfs(graph,1,visited)