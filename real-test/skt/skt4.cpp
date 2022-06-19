#include <bits/stdc++.h>

using namespace std;
int N, M;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

struct pos
{
    int x;
    int y;
    int left;
    int sleep;

    pos(){};
    pos(int _x, int _y, int _left, int _sleep) : x(_x), y(_y), left(_left), sleep(_sleep){};
};

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < M;
}
void bfs(vector<string> &grid, int &k, int &answer)
{
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(k + 1, 0)));
    queue<pos> q;
    q.push({0, 0, k, 0});
    visited[0][0][0]=true;
    while (!q.empty())
    {
        int cx = q.front().x;
        int cy = q.front().y;
        int cl = q.front().left;
        int cs = q.front().sleep;
        q.pop();
        if (cx == N - 1 && cy == M - 1)
        {
            answer = min(answer, cs);
            continue;
        }
        if (cl == 0)
        {
            if (grid[cx][cy] == '.' && !visited[cx][cy][cs + 1])
            {
                visited[cx][cy][cs + 1] = true;
                q.push({cx, cy, k, cs + 1});
            }
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int px = cx + dx[i];
            int py = cy + dy[i];
            if (in_range(px, py) && grid[px][py] != '#')
            {
                if (grid[cx][cy] == '.' && grid[px][py] == 'F' && !visited[px][py][cs + 1])
                {
                    visited[px][py][cs + 1] = true;
                    q.push({px, py, k, cs + 1});
                }
                if (!visited[px][py][cs])
                {
                    visited[px][py][cs] = true;
                    q.push({px, py, cl - 1, cs});
                }
            }
        }
    }
}
int solution(vector<string> grid, int k)
{
    int answer = INT_MAX;
    N = grid.size();
    M = grid[0].length();
    bfs(grid, k, answer);
    return answer;
}

int main()
{
    vector<string> grid = {
        "..FF",
        "###F",
        "###."
    };
    cout<<solution(grid,4);
}