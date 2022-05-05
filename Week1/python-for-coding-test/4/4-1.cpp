#include <bits/stdc++.h>
#define in_range(x, y) x >= 0 && y >= 0 && x < N &&y < N
using namespace std;
int N;

pair<int, int> get_next_pos(pair<int, int> cur_pos, char dir)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int idx;
    switch (dir)
    {
    case 'U':
        idx = 0;
        break;
    case 'R':
        idx = 1;
        break;
    case 'D':
        idx = 2;
        break;
    case 'L':
        idx = 3;
        break;
    }
    pair<int, int> next_pos = make_pair(cur_pos.first + dx[idx], cur_pos.second + dy[idx]);
    if (in_range(next_pos.first, next_pos.second))
        return next_pos;
    else
        return cur_pos;
}

int main()
{
    char c;
    pair<int, int> cur_pos = make_pair(0, 0);
    cin >> N;
    while(cin>>c)
    {
        cur_pos = get_next_pos(cur_pos, c);
    }
    cout << cur_pos.first + 1 << " " << cur_pos.second + 1;
}