// 2022-05-10 23:46:09
// 미래도시

// 2022-05-10 23:55:46 끝
// 정답은 맞는것 같은데
// 플로이드-워셜로 푸는 문제였던 것 같다.

#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int answer = -1;
int N, M;
int X, K;
vector<vector<int>> graph;
vector<vector<int>> dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    graph.resize(N);
    dist.resize(N, vector<int>(N, INF));
    for (int i = 0; i < M; i++)
    {
        int src, dest;
        cin >> src >> dest;
        src--;
        dest--;
        dist[src][dest]=1;
        dist[dest][src]=1;
    }
    for (int i = 0; i < N; i++)
    {
        dist[i][i] = 0;
    }
    cin >> X >> K;
    X--;
    K--;
    // D_{AB} = min(D_{AB}, D_{AK} + D_{KB})
    for (int k = 0; k < N; k++)
    {
        for (int a = 0; a < N; a++)
        {
            for (int b = 0; b < N; b++)
            {
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
            }
        }
    }
    if(dist[0][K]+dist[K][X]<INF)
        cout << dist[0][K] + dist[K][X];
    else
        cout<<-1;
    return 0;
}

// int answer=-1;
// int N, M;
// int X, K;
// vector<vector<int>> graph;
// vector<int> dist;

// void dijkstra(int start)
// {
//     priority_queue<pair<int, int>> pq;
//     dist[start] = 0;
//     pq.push(make_pair(0, start));
//     while (!pq.empty())
//     {
//         int cur_cost = -pq.top().first;
//         int cur = pq.top().second;
//         pq.pop();
//         if (dist[cur] < cur_cost)
//             continue;
//         for (int i = 0; i < graph[cur].size(); i++)
//         {
//             int next = graph[cur][i];
//             if (dist[next] > cur_cost + 1)
//             {
//                 dist[next] = cur_cost + 1;
//                 pq.push({-dist[next], next});
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     cin >> N >> M;
//     graph.resize(N);
//     dist.resize(N, INF);
//     for (int i = 0; i < M; i++)
//     {
//         int src, dest;
//         cin >> src >> dest;
//         graph[src - 1].push_back(dest - 1);
//         graph[dest - 1].push_back(src - 1);
//     }
//     cin>>X>>K;
//     X--; K--;
//     dijkstra(0);
//     if(dist[K]!=INF){
//         answer=dist[K];
//     }
//     else {
//         cout<<-1;
//         return 0;
//     }
//     fill(dist.begin(),dist.end(),INF);
//     dijkstra(K);
//     if(dist[X]!=INF){
//         answer+=dist[X];
//     }
//     else {
//         cout<<-1;
//         return 0;
//     }
//     cout<<answer;
//     return 0;
// }