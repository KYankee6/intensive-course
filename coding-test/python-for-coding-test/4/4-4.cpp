// 게임 개발 117pg
// 2022-05-05 23:01:14 시작
// dir을 이용하는 탐색문제 (귀찮다)
// 2022-05-05 23:41:15 풀이완료 40분 딱 걸렸음
// #define 전처리기로 깝치다가 많이 혼날수도 있겠구나
// 저 문장안에 괄호를 넣지 않아서 정말 정말 큰일날뻔함..
// 왠만하면 함수로 호출해야겠다.

#include <bits/stdc++.h>
#define in_range(x, y) (x >= 0) && (y >= 0) && (x < N) && (y < M)
using namespace std;

int dx[4] = {-1, 0, 1, 0}; // Up, Left, Down, Right
int dy[4] = {0, -1, 0, 1};

int N, M;
vector<vector<int>> graph;
tuple<int, int, int> forward(tuple<int, int, int> &pos)
{
    int x = get<0>(pos);
    int y = get<1>(pos);
    int d = get<2>(pos);

    return make_tuple(x + dx[d], y + dy[d], d);
}

tuple<int, int, int> backward(tuple<int, int, int> &pos)
{
    int x = get<0>(pos);
    int y = get<1>(pos);
    int d = get<2>(pos);

    return make_tuple(x - dx[d], y - dy[d], d);
}

tuple<int, int, int> get_next_dir(tuple<int, int, int> &pos)
{
    vector<int> ro = {0, 1, 2, 3};
    rotate(ro.begin(), ro.begin() + 1, ro.end());
    int d = get<2>(pos);
    int new_d = ro[d];
    return make_tuple(get<0>(pos), get<1>(pos), new_d);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    int answer = 0;
    int cur_x, cur_y, cur_d;
    cin >> cur_x >> cur_y >> cur_d;
    tuple<int, int, int> cur_pos = make_tuple(cur_x, cur_y, cur_d);

    graph.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }
    while (true)
    {
        bool isleftcand = false;
        auto next_pos = cur_pos;
        for (int i = 0; i < 4; i++)
        {
            next_pos = get_next_dir(next_pos);
            auto checker = forward(next_pos);
            int nx = get<0>(checker);
            int ny = get<1>(checker);
            int nd = get<2>(checker);
            if (in_range(nx, ny) && graph[nx][ny] == 0) // 0-> empty, 1 -> ocean, 2-> visited
            {
                answer++;
                graph[nx][ny] = 2;
                isleftcand = true;
                cur_pos = checker;
                break;
            }
        }
        if (!isleftcand)
        {
            auto back_pos = backward(cur_pos);
            int bx = get<0>(back_pos);
            int by = get<1>(back_pos);
            int bd = get<2>(back_pos);
            if (!in_range(bx, by) || graph[bx][by] == 1) // 0-> empty, 1 -> ocean, 2-> visited
            {
                break;
            }
            else
            {
                cur_pos = back_pos;
            }
        }
    }
    cout << answer;
    return 0;
}
