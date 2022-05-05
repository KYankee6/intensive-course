# 5. DFS/BFS

## 5-1 꼭 필요한 자료구조 기초
**탐색**이란 많은 양의 데이터 중에서 원하는 데이터를 찾는 과정을 말한다.  
- 그래프, 트리 탐색
- 자료구조 (스택, 큐)


### 5-1-1. 스택
- 박스 쌓기에 비유
- 아래서부터 위로 차곡차곡 쌓는다.(Stack)
- 선입후출(First-in Last-out)
- python은 list에 append(), pop() => stack

### 5-1-2. 큐
- 대기줄에 비유
- 먼저 온 사람이 먼저 들어가게 된다. (Queue)
- `공정한` 자료구조 
- 선입 선출(First-in First-out)
- python은 `collections` 모듈의 `deque` 자료구조 사용

```python
from collections import deque

queue = deque()
queue.append(1)
...
queue.popleft()
print(queue) # 먼저 들어온 순서대로 출력
queue.reverse()  # 다음 출력을 위해 연순으로 바꾸기
print(queue) # 나중에 들어온 원소부터 출력
```
심지어는 deque 자료형을 list로 바꿀 수도 있다.

### 5-1-3. 재귀 함수
- 재귀 함수(Recursive Function)란, 자기 자신을 다시 호출하는 함수
- 재귀 함수를 사용할 땐 `종료 조건`을 명시해야 한다.
- 컴퓨터 내부에서 재귀 함수의 수행은 스택 자료구조를 이용한다.
- 가장 마지막에 호출한 함수가 먼저 수행을 끝낸다.
 
```python
def factorial_iterative(n):
    result = 1
    for i in range(1, n+1):
        result *= i
    return result

def factorial_recursive(n):
    if n<=1:
        return 1
    return n* factorial_recursive(n-1)    
print('반복문으로 구현:', factorial_iterative(5))
print('재귀적으로 구현:', factorial_recursive(5))
```


> 그렇다면 반복분 대신에 재귀 함수를 사용 했을 때 얻을 수 있는 장점은 무엇일까?
> 재귀 함수의 코드가 간결해진다.(점화식->소스코드)

## 5-2. 탐색 알고리즘 DFS/BFS
### 5-2-1. DFS
- `DFS`는 "Depth First Search", 깊이 우선 탐색이라고 부른다.
- 깊이를 우선으로 탐색하는 알고리즘
- 그래프의 기본구조
	1) 노드(Node, 혹은 정점(Vertex))
    2) 간선(Edge)
- 두 노드가 간선으로 연결되어 있다면 `두 노드는 인접하다(Adjacent).`라고 표현
- 인접 행렬(Adjacency Matrix) 
	2차원 배열로 그래프의 연결 관계를 표현하는 방식
- 인접 리스트(Adjacency List)
	리스트로 그래프의 연결 관계를 표현하는 방식
    
### 5-2-2. 인접행렬 방식 예제
```python
INF = 999999999

graph = [
	[0,7,5],
    [7,0,INF],
    [5,INF,0]
    ]
```
### 5-2-3. 인접 리스트 방식
```python
graph = [[] for _ in range(3)]

# 노드 0에 연결된 노드 정보 저장 (노드, 거리)
graph[0].append((1,7))
graph[0].append((2,5))
  
# 노드 1에 연결된 노드 정보 저장 (노드, 거리)
graph[1].append((0,7))

# 노드 2에 연결된 노드 정보 저장 (노드, 거리)
graph[2].append((0,5))

print(graph)
```

> 무슨 차이가 있을까?
> **메모리 측면** : `인접 행렬 방식`은 모든 관계를 저장하므로 노드 개수(Edges) 많을 수록 메모리가 불필요하게 낭비된다.
>`인접 리스트 방식`은 인접 행렬에 비해 특정한 두 노드가 연결되어 있는지에 대한 정보를 얻는 속도가 느리다.
>예를 들어, 노드 1과 노드 7이 연결되어있는지 확인하려면?
>
>```python
># 인접 행렬 (O(1))
>if graph[1][7] != INF
>
># 인접 리스트 (O(V))
>INF = 999999999
>
>for vertex, weight in graph[1]: 
>    if vertex == 0 and weight != INF:
>        print('vertex: ' , vertex)
>        print('weight: ' , weight)
>        print('vertex 1 and 0 is connected!')
>
>```

DFS의 구체적인 동작 과정은 다음과 같다.
>1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.
>2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 인접 노드를 스택에 넣고 방문 처리를 한다. 방문하지 않은 인접 노드가 없으면 최상단 노드를 꺼낸다.
>3. 2번의 과정을 더 이상 수행 할 수 없을 때 까지 반복한다.

```python
# 5-8.py
def dfs(graph, v, visited):
	visited[v]=True
    print(v, end=' ')
    for i in graph[v]:
    	if not visited[i]:
        	dfs(graph, i, visited)

graph = [ [], [] ..... ]
visited = [False] * 9
dfs(graph,1,visited)
```

### 5-2-4. BFS
- `BFS` "Breath First Search", 너비 우선 탐색
- 가까운 노드부터 탐색하는 알고리즘 (가장 깊게 가는 DFS와 정반대)
- DFS는 `queue` 자료구조를 이용하는 것이 정석이다.

동작 방식은 다음과 같다.

> 1. 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다
> 2. 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리를 한다.
> 3. 2번의 과정을 더 이상 수행할 수 없을 때 까지 반복한다.


```python
# 5-9.py
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
                
graph = [ [], [] ..... ]
visited = [False] * 9
bfs(graph,1,visited)
```

|DFS|BFS
|:---|:---|
동작원리|스택|큐
구현방법|재귀 함수|큐 자료구조
