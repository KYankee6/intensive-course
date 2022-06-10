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