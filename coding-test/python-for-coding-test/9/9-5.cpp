// 2022-05-11 00:03:43

// 전보
// 2022-05-11 00:19:24 끝

#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int total_time;
int num_city;
int N, M, C;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    dist[C] = 0;
    pq.push({0, C});
    while (!pq.empty())
    {
        int cur_cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cur_cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;
            if (dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> C;
    C--;
    graph.resize(N);
    dist.resize(N, INF);
    for (int i = 0; i < M; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        src--;
        dest--;
        graph[src].push_back({dest, cost});
    }
    dijkstra();
    for (int i = 0; i < N; i++)
    {
        if (dist[i] != INF && i!=C)
        {
            num_city++;
            total_time = max(total_time,dist[i]);
        }
    }
    cout << num_city << " " << total_time;
    return 0;
}