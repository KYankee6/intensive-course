# DFS

# 5-8.py
def dfs(graph, v, visited):
    visited[v]=True
    print(v, end=' ')
    for i in graph[v]:
    	if not visited[i]:
        	dfs(graph, i, visited)

graph = [[] for _ in range(3)]
visited = [False] * 9
dfs(graph,1,visited)