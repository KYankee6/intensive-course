// 미로 탈출
// 2022-05-06 16:15:28 시작
// 2022-05-06 16:21:38 끝
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int answer = 0;
int N, M;
vector<vector<int>> graph;
vector<vector<bool>> visited;

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < M;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        visited[cur.first][cur.second] = true;
        for (int i = 0; i < 4; i++)
        {
            int px = cur.first + dx[i];
            int py = cur.second + dy[i];
            if (in_range(px, py) && !visited[px][py] && graph[px][py] == 1)
            {
                visited[px][py] = true;
                graph[px][py]=graph[cur.first][cur.second]+1;
                q.push(make_pair(px, py));
            }
        }
    }
    answer++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    graph.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    bfs(0,0);
    cout << graph[N-1][M-1];
}