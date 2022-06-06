#include <bits/stdc++.h>
#define INF 100000001
using namespace std;

vector<vector<int>> graph;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    graph.resize(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        src--;
        dest--;
        graph[src][dest] = min(graph[src][dest],cost);
    }
    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (graph[i][j]==INF)
                cout << 0 << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}