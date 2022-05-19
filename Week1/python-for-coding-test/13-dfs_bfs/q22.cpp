// https://programmers.co.kr/learn/courses/30/lessons/60063
// 블록 이동하기
// 2022-05-18 19:55:45
// 50분 제한

// dx dy는 4개 유지, move(), turn(), is_movable(), is_turnable()
// range checker
// graph, robot = 2 robot deque
// visited는 어떻게 check?
// head+ 상태로 구분하자.
// 2022-05-18 19:59:19 구현시작
#include <bits/stdc++.h>
using namespace std;

struct obj
{
    int x;
    int y;
    int state;
    int cnt = 0;

    obj(){};
    obj(int _x, int _y, int _state) : x(_x), y(_y), state(_state){};
};
int N;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
vector<vector<int>> visited;

bool in_range(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}

bool in_range(deque<obj> &target)
{
    for (obj &o : target)
    {
        if (o.x >= 0 && o.y >= 0 && o.x < N && o.y < N)
        {
            continue;
        }
        else
            return false;
    }
    return true;
}
bool end_check(deque<obj> &cd)
{
    for (auto e : cd)
    {
        if (e.x == N-1 && e.y == N-1)
            return true;
    }
    return false;
}

bool visit_check(deque<obj> &cd)
{
    for (int i = 0; i < cd.size(); i++)
    {
        bool result =((1 << cd[i].state) & visited[cd[i].x][cd[i].y]) > 0;
        if (result)
            return false;
    }
    return true;
}

void set_visit(deque<obj> &cd)
{
    for (auto e : cd)
    {
        visited[e.x][e.y] |= 1 << e.state;
    }
}

void set_rb_map(deque<obj> &cd, vector<vector<int>> &board)
{
    for (auto e : cd)
    {
        // visited logic
        board[e.x][e.y] = 2;
    }
}

void turn(bool isClockWise, obj &head, obj &tail)
{
    int &px = tail.x;
    int &py = tail.y;
    int &ts = tail.state;
    if (isClockWise)
    {
        switch (head.state)
        {
        case 0:
        {
            py++;
            px++;
            break;
        }
        case 1:
        {
            px++;
            py--;
            break;
        }
        case 2:
        {
            py--;
            px--;
            break;
        }
        case 3:
        {
            px--;
            py++;
            break;
        }
        }
        head.state = (head.state + 1) % 4;
        ts = (ts + 1) % 4;
    }
    else
    {
        switch (head.state)
        {
        case 0:
        {
            py--;
            px++;
            break;
        }
        case 1:
        {
            px--;
            py--;
            break;
        }
        case 2:
        {
            py++;
            px--;
            break;
        }
        case 3:
        {
            px++;
            py++;
            break;
        }
        }
        head.state -= 1;
        if (head.state < 0)
            head.state = 3;
        ts--;
        if (ts < 0)
            ts = 3;
    }
}

bool is_turnable(bool isClockWise, vector<vector<int>> &board, obj &head, obj &tail)
{
    int px = tail.x;
    int py = tail.y;
    if (isClockWise)
    {
        // 유효성 먼저 검사
        switch (head.state)
        {
        case 0:
        {
            py++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            px++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        case 1:
        {
            px++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            py--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        case 2:
        {
            py--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            px--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        case 3:
        {
            px--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            py++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        }
    }
    else
    {
        switch (head.state)
        {
        case 0:
        {
            py--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            px++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        case 1:
        {
            px--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            py--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        case 2:
        {
            py++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            px--;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        case 3:
        {
            px++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            py++;
            if (!in_range(px, py) || board[px][py] == 1)
            {
                return false;
            }
            break;
        }
        }
    }
    return true;
}

bool is_movable(deque<obj> &cd, vector<vector<int>> &board)
{
    for (obj &o : cd)
    {
        if (board[o.x][o.y] == 1)
        {
            return false;
        }
    }
    return true;
}

deque<obj> move(int d, deque<obj> &cd)
{
    deque<obj> next(2, obj());

    for (int i = 0; i < 2; i++)
    {
        next[i].x = cd[i].x + dx[d];
        next[i].y = cd[i].y + dy[d];
        next[i].state = cd[i].state;
    }
    return next;
}

int bfs(vector<vector<int>> &board)
{
    queue<deque<obj>> q;
    obj o1 = (obj(0, 0, 1));
    obj o2 = (obj(0, 1, 3));
    deque<obj> rb = {o1, o2};
    visited[rb[0].x][rb[0].y] |= 1 << rb[0].state;
    visited[rb[1].x][rb[1].y] |= 1 << rb[1].state;

    q.push(rb);
    while (!q.empty())
    {
        auto cur = q.front();
        // front

        if (end_check(cur))
            return min(cur[0].cnt, cur[1].cnt);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            auto next = move(i, cur);
            if (in_range(next) && is_movable(next, board) && visit_check(next))
            {
                set_visit(next);
                next[0].cnt = cur[0].cnt + 1;
                next[1].cnt = cur[1].cnt + 1;
                q.push(next);
            }
        }
        bool clock = true;
        for (int i = 0; i < 4; i++)
        {
            int j = (3 - i) % 2;
            int k = (i) % 2;
            if (is_turnable(clock, board, cur[k], cur[j]))
            {
                auto next = cur;
                turn(clock, next[k], next[j]);
                if (visit_check(next))
                {
                    set_visit(next);
                    next[0].cnt = cur[0].cnt + 1;
                    next[1].cnt = cur[1].cnt + 1;
                    q.push(next);
                }
            }
            if (i == 1)
                clock = !clock;
        }
    }
    return -1;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    N = board.size();
    visited.resize(N, vector<int>(N, 0));
    answer = bfs(board);

    return answer;
}

int main()
{
    vector<vector<int>> v = {{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}};
    cout << solution(v);
}