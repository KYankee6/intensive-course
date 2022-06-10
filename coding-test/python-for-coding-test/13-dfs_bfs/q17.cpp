#include <bits/stdc++.h>
using namespace std;

int N, K, S, X, Y; // S 초 이후, X,Y 위치
vector<vector<int>> graph;
deque<tuple<int, int, int>> dq;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool in_range(int x, int y)
{
    return x >= 1 && y >= 1 && x <= N && y <= N;
}

void bfs()
{
    int time = 0;
    int set_cnt = dq.size();
    sort(dq.begin(),dq.end());
    while (!dq.empty())
    {
        if (set_cnt == 0)
        {
            time++;
            set_cnt = dq.size();
            if (time == S)
            {
                return;
            }
            sort(dq.begin(),dq.end());
        }
        set_cnt--;
        int v_num = get<0>(dq[0]);
        int cur_x = get<1>(dq[0]);
        int cur_y = get<2>(dq[0]);
        dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int px = dx[i] + cur_x;
            int py = dy[i] + cur_y;
            if (in_range(px, py) && graph[px][py] == 0)
            {
                dq.push_back(make_tuple(v_num, px, py));
                graph[px][py] = v_num;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    graph.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
            {
                dq.push_back(make_tuple(graph[i][j], i, j));
            }
        }
    }
    cin >> S >> X >> Y;
    if(S!=0)
        bfs();
    cout<<graph[X][Y];
    return 0;
}