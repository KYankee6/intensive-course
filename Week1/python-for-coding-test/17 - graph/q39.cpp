#include <bits/stdc++.h>
#define INF 0x6f6f6f6f
using namespace std;

int T, N;
int answer;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}
struct pos
{
    int w;
    int x;
    int y;

    pos(){};
    pos(int _w, int _x, int _y) : w(_w), x(_x), y(_y){};
};

struct cmp
{
    bool operator()(const pos &p1, const pos &p2)
    {
        return p1.w > p2.w;
    }
};
void dijkstra()
{
    priority_queue<pos, vector<pos>, cmp> pq;
    pq.push({graph[0][0], 0, 0});
    while (!pq.empty())
    {
        int cur_w = pq.top().w;
        int cur_x = pq.top().x;
        int cur_y = pq.top().y;
        pq.pop();
        if (visited[cur_x][cur_y])
            continue;
        visited[cur_x][cur_y] = true;

        if (cur_x == N - 1 && cur_y == N - 1)
        {
            answer = min(answer, cur_w);
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int px = cur_x + dx[i];
            int py = cur_y + dy[i];
            if (in_range(px, py) && !visited[px][py])
            {
                pq.push({cur_w + graph[px][py], px, py});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--)
    {
        answer = INF;
        cin >> N;
        graph.resize(N, vector<int>(N, 0));
        visited.resize(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
            }
        }
        dijkstra();
        cout << answer << '\n';
        graph.clear();
        visited.clear();
    }
}