#include <bits/stdc++.h>
using namespace std;

int answer;
int N, M;
vector<int> indegree;
vector<vector<int>> graph;

void topology_sort()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push({1, i});
        }
    }
    while (!q.empty())
    {
        int cnt = q.front().first;
        int cnt2 = 0;
        int node = q.front().second;
        q.pop();
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            indegree[next]--;
            if (indegree[next] == 0)
            {
                cnt2++;
                q.push({cnt + 1, next});
            }
        }
        if(cnt+cnt2 == N-1){
            answer++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    indegree.resize(N, 0);
    graph.resize(N);

    for (int i = 0; i < M; i++)
    {
        int s, d;
        cin >> s >> d;
        s--;
        d--;
        indegree[d]++;
        graph[s].push_back(d);
    }
    topology_sort();
    cout<<answer;
    return 0;
}