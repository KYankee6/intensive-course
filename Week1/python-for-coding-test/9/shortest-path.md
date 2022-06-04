# 9-1. 가장 빠른 길 찾기

최단 경로(Shortest Path) 알고리즘은 말 그대로 가장 짧은 경로를 찾는 알고리즘이다.
다양한 종류가 있는데 상황에 맞는 효율적인 알고리즘이 **이미 정립되어 있다.**

> ex)
>
> - 한 지점에서 다른 특정 지점까지의 최단 경로를 구하는 경우
> - 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구하는 경우

최단 경로 알고리즘은 보통 그래프로 표현한다.

- 정점(지점) = 노드(Vertex)
- 지점간 연결된 도로 = 간선(Edge)

학부 수준 최단 거리 알고리즘

1. 다익스트라
2. 플로이드-워셜
3. 벨만 포드
   여기서 **다익스트라**와 **플로이드-워셜** 알고리즘이 자주 나온다.

# 9-2 다익스트라 최단 경로 알고리즘

그래프에서 여러 개의 노드가 있을 때, **특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단 경로를 구해주는 알고리즘**이다.

- 다익스트라 알고리즘에서는 **음의 간선**이 없어야한다.
- GPS 소프트웨어의 기본 알고리즘으로 채택되곤 한다.
- 기본적으로 그리디 알고리즘 (현재 정점에서 가장 적은 비용의 간선으로 이동)이다.

원리는 아래와 같다.

1. 출발 노드를 설정한다.
2. 최단 거리 테이블을 초기화한다.
3. 방문하지 않은 노드 중에서 가장 비용이 낮은 간선을 선택한다.
4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.
5. 3, 4를 반복한다.

과정에서 `각 노드에 대한 현재까지의 최단 거리`정보를 항상 1차원 리시트에 저장하여 리스트를 계속 갱신한다는 특징이 있다.
**매번** 현재 처리하고 있는 노드를 기준으로 주변 간선을 확인한다.
나중에 현재 처리하고 있는 노드와 인접한 노드로 도달하는 더 짧은 경로를 찾으면 '더 짧은 경로가 있었네? 이제부터는 이 경로가 제일 짧은 경로야' 라고 판단하는 것이다.

> 즉, 한 단계당 하나의 노드에 대한 최단 거리를 확실히 찾는 것

## 9-2-1. 간단한 다익스트라 알고리즘

- $O(V^2)$
- 총 O(V)번에 걸쳐 최단 거리가 가장 짧은 노드를 매번 선형 탐색(O(V))해야 하기 때문이다.
- 각 노드에 대한 최단거리를 담는 1차원 리스트를 선언한다.
- 이후 단계마다 '방문 하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택'하기 위해 매 단계마다 1차원 리스트를 확인(순차 탐색) 한다.

```python
import sys
input = sys.stdin.readline
INF = int(1e9)

# 노드의 개수, 간선 개수
n, m = map(int, input().split())

# 시작 노드 입력
start = int(input())
graph = [[] for i in range(n+1)]
visited = [False]*(n+1)
distance = [INF]*(n+1)

for _ in range(m):
    a,b,c, = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 c
    graph[a].append((b,c))

def get_smallest_node():
    min_value = INF
    index = 0
    for i in range(1, n+1):
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            index = i
    return index

def dijkstra(start):
    distance[start]=0
    visited[start]=True

    for j in graph[start]:
        distance[j[0]] = j[1]
      
    for i in range(n-1):
        now = get_smallest_node()
        visited[now]=True
        for j in graph[now]:
            cost = distance[now]+j[1]
            if cost < distance[j[0]]:
                distance[j[0]]=cost

dijkstra(start)
for i in range(1, n+1):
    if distance[i]==INF:
        print("INF ")
    else: print(distance[i])
```

아래는 C++로 구현한 코드다

```cpp
#include <bits/stdc++.h>
#define INF int(1e9)
using namespace std;

int start;
int V,E;
vector<vector<pair<int,int>>> graph;
vector<bool> visited;
vector<int> dist;

int get_smallest_node(){
    int min_val=INF;
    int result=0;
    for(int i=0; i<dist.size(); i++){
        if(min_val>dist[i] && !visited[i]){
            min_val=dist[i];
            result=i;
        }
    }
    return result;
}

void dijkstra(){
    visited[start]=true;
    dist[start]=0;
    for(int i=0; i<graph[start].size(); i++){
        auto next = graph[start][i];
        int nNode = next.first;
        int nCost = next.second;
        dist[nNode] = nCost;
    }

    for(int i=0; i<V-1; i++){
        int now = get_smallest_node();
        visited[now]=true;
        for(int j=0; j<graph[now].size(); j++){
            auto next = graph[now][j];
            int nNode = next.first;
            int nCost = next.second;
            if(dist[nNode]>dist[now]+nCost){
                dist[nNode]=dist[now]+nCost;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>V>>E>>start;
    start--;
    graph.resize(V);
    visited.resize(V,false);
    dist.resize(V,INF);

    for(int i=0; i<E; i++){
        int src, dest, cost;
        cin>>src>>dest>>cost;
        graph[src-1].push_back(make_pair(dest-1,cost));
    }
    dijkstra();
    for(int i=0; i<V; i++){
        if(dist[i] == INF){
            cout<<("INF ");
        }
        else cout<<dist[i]<<" ";
    }
    return 0;
}
```

## 9-2-2. 개선된 다익스트라 일고리즘

앞서 살펴본 간단한 다익스트라 알고리즘은 ($O(V^2)$)의 시간 복잡도를 가졌다.
이는 전체 노드의 개수가 10,000개를 넘어가면 이 코드로는 문제를 해결하기 어렵다.
노드의 개수, 간선의 수가 많을 때는 개선된 다익스트라 알고리즘을 사용해야 한다.

- $O(Elog{V})$
- 최단 거리 테이블을 선형적으로 탐색하는 것이 아니라 힙(Heap)자료구조 이용
- 힙 자료구조를 이용한다면 $O(V)$ 가 아닌 $O(logV)$시간이 소모된다.

> 힙 이란?
> 우선순위 큐를 구현하기 위하여 사용되는 자료구조중 하나.
> 우선순위가 가장 높은 데이터를 가장 먼저 삭제하는 자료구조
> 우선순위 값을 표현할 때는 일반적으로 정수형 변수가 사용된다.
> ex) {가치, 물건} 을 우선 순위 큐 자료구조에 넣는다면, 첫 번째 원소(가치) 기준으로 우선순위를 설정한다.
> 최소 힙(가장 낮은 우선순위(값이 낮은)를 먼저 삭제 <=> 최대 힙

| 우선순위 큐 구현방식 | 삽입 시간 | 삭제 시간 |
| -------------------- | --------- | --------- |
| 리스트               | O(1)      | O(N)      |
| 힙(Heap)             | O(logN)   | O(logN)   |

리스트를 이용해서 우선 순위 큐를 구현 => 매 삭제마다 우선순위를 확인(순회)하므로 $O(N)$ 시간이 걸린다.
그리고 개인적인 생각으로 `get_smallest_node()` 함수를 구현 안한다는게 매우 좋은 것 같다.

```python
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

# 노드의 개수, 간선 개수
n, m = map(int, input().split())

# 시작 노드 입력
start = int(input())
graph = [[] for i in range(n+1)]
visited = [False]*(n+1)
distance = [INF]*(n+1)

for _ in range(m):
    a,b,c, = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 c
    graph[a].append((b,c))

def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    distance[start] = 0
    while q :
        dist, now = heapq.heappop(q)
        if distance[now]<dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]]=cost
                heapq.heappush(q,(cost,i[0]))

dijkstra(start)
for i in range(1, n+1):
    if distance[i]==INF:
        print("INF ")
    else: print(distance[i])
```

아래는 C++로 작성한 개선된 다익스트라 알고리즘이다.

```cpp
#include <bits/stdc++.h>
#define INF int(1e9)
using namespace std;

int start;
int V, E;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;
            if (dist[next] > dist[now] + cost)
            {
                dist[next] = dist[now] + cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> V >> E >> start;
    start--;
    graph.resize(V);
    dist.resize(V, INF);

    for (int i = 0; i < E; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        graph[src - 1].push_back(make_pair(dest - 1, cost));
    }
    dijkstra();
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
        {
            cout << ("INF ");
        }
        else
            cout << dist[i] << " ";
    }
    return 0;
}
```

## 9-3. 플로이드 워셜 알고리즘

다익스트라 알고리즘 => '한 지점에서 다른 특정 지점까지의 최단 경로를 구하는 경우'
플로이드 워셜 => '모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구하는 경우'

다익스트라

- 단계마다 최단 거리를 가지는 ㄴ노드를 하나씩 반복적으로 선택한다.
- 경로를 확인하여, 최단 거리 테이블을 갱신한다.
- 출발 노드로 부터 도착 노드까지 1차원 리스트로 최단 경로를 갱신한다.
- 그리디 알고리즘이다.

플로이드 워셜

- 다익스트라와 같이 단계마다 '거쳐 가는 노드'를 기준으로 알고리즘 수행
- 하지만 매번 방문하지 않은 노드 중에서 최단 거리를 갖는 노드를 찾을 필요가 없다.
- 노드 개수가 N개일 때 N번을 수행하며, 단계마다 $O(N^2)$의 연산을 수행
- `현재 노드를 거쳐가는` 모든 경로를 고려한다.
- 따라서 총 시간 복잡도는 $O(N^3)$이다.
- 2차원 리스트에 '최단 거리' 정보를 저장한다.
- 다이나믹 프로그래밍이다.
- 'A에서 B로가는 최소 비용'과 'A에서 K를 거쳐 B로 가는 비용'을 비교하여 작은 값으로 갱신
- 점화식 $D_{ab} = min(D_{ab}, D_{ak} + D_{kb})$

```python
INF = int(1e9)

n = int(input())
m = int(input())

graph =  [[INF] * (n+1) for _ in range(n+1)]

for a in range(1, n+1):
    for b in range(1, n+1):
        if a==b:
            graph[a][b]=0
          
for _ in range(m):
    a, b, c = map(int,input().split())
    graph[a][b]=c
  
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1,n+1):
            graph[a][b]= min(graph[a][b], graph[a][k]+graph[k][b])
          
# 수행된 결과 출력

for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF:
            print("INF", end=" ")
        else:
            print(graph[a][b], end=" ")
    print()
  
  
```
