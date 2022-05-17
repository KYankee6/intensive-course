// https://programmers.co.kr/learn/courses/30/lessons/60061
// 조금 빡세 보이는데요
// 2022-05-17 03:37:48
// board를 만들어 현재 설치의 조건에 맞는지를 확인해야합니다.
// 1. 기둥 설치 조건
// 기둥은 "바닥"에 있거나, "보의 한쪽 끝 부분 위"에 있거나, "다른 기둥"위에 있어야 한다
// 2. 보 설치 조건
// "기둥 한쪽 끝 부분 위"에 있거나, "양쪽 끝 부분이 보와 "동시에"" 연결되어야 한다.
// 가로랑 세로 좌표 꺾여있다.
// 마지막 결과를 조건에 맞게 정렬 해야한다.
// 2022-05-17 04:25:18 토나온다.
// 2022-05-17 05:06:48 진심 토나온다

// 2022-05-17 05:15:47 
// 너 다음에 다시 한번 더해..
#include <bits/stdc++.h>

using namespace std;

struct mobj
{
    bool p;
    bool b;
    mobj(){};
    mobj(bool _p, bool _b) : p(_p), b(_b){};
};

struct obj
{
    int x;
    int y;
    int type;
    int ins;

    obj(){};
    obj(int _x, int _y, int _type, int _ins) : x(_x), y(_y), type(_type), ins(_ins){};
};

bool cmp(vector<int> &v1, vector<int> &v2)
{
    if (v1[0] == v2[0] && v1[1] == v2[1])
    {
        return v1[2] < v2[2];
    }
    else
    {
        return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
    }
}

bool check_poll(obj &p1, vector<vector<mobj>> &board, int n)
{
    if(p1.ins==0){
        if(p1.x+1>n || p1.x-1 <0) return false;
    }
    bool cond1 = true;
    bool cond2 = true;
    bool cond3 = true;
    if (p1.x != 0)
        cond1 = false;
    if (p1.x+1<=n && !board[p1.x + 1][p1.y].b)
        cond2 = false;
    if (p1.x-1>=0 && !board[p1.x - 1][p1.y].p)
        cond3 = false;
    return cond1 || cond2 || cond3;
}

bool check_bo(obj &b1, vector<vector<mobj>> &board, int n)
{
    if(b1.ins==0){
        if(b1.x-1<0 || b1.y+1>n || b1.y-1<0)return false;
    }
    bool cond1 = true;
    bool cond2 = true;

    if (b1.x-1>=0 && !board[b1.x - 1][b1.y].p)
        cond1 = false;
    if (b1.y+1 <=n && b1.y-1 >=0 && !board[b1.x][b1.y + 1].b && !board[b1.x][b1.y - 1].b)
        cond2 = false;
    return cond1 || cond2;
}

vector<vector<mobj>> board;
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;
    deque<obj> builder;
    board.resize(n + 1, vector<mobj>(n + 1, mobj(false, false)));
    for (int i = 0; i < build_frame.size(); i++)
    {
        obj new_obj = obj(build_frame[i][1], build_frame[i][0], build_frame[i][2], build_frame[i][3]);
        builder.push_back(new_obj);
    }
    for (int i = 0; i < builder.size(); i++)
    {
        obj task = builder[i];
        if (task.ins == 0)
        { //삭제
            obj task_comple;

            if (task.type == 0) // 기둥의 반대는 보
            {
                task_comple.x = task.x + 1;
                task_comple.y = task.y;
                task_comple.ins = task.ins;
                board[task.x][task.y].p = false;
                board[task.x - 1][task.y].p = false;
                if (!check_poll(task, board,n) || !check_bo(task_comple, board,n))
                {
                    board[task.x][task.y].p = true;
                    board[task.x - 1][task.y].p = true;
                }
            }
            else
            {// 설치
                task_comple.x = task.x - 1;
                task_comple.y = task.y;
                task_comple.ins = task.ins;
                board[task.x][task.y].b = false;
                board[task.x][task.y + 1].b = false;
                if (!check_poll(task_comple, board,n) && !check_bo(task, board,n))
                {
                    board[task.x][task.y].b = true;
                    board[task.x][task.y + 1].b = true;
                }
            }
        }
        else
        {
            if (task.type == 0 && check_poll(task, board,n))
            {
                board[task.x][task.y].p = true;
                board[task.x + 1][task.y].p = true;
            }
            else if (task.type == 1 && check_bo(task, board,n))
            {
                board[task.x][task.y].b = true;
                board[task.x][task.y + 1].b = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j].b != 0 || board[i][j].p != 0)
            {
                vector<int> pollv;
                vector<int> bov;

                if (board[i][j].p)
                {
                    pollv.push_back(j);
                    pollv.push_back(i);
                    pollv.push_back(0);
                }
                if (board[i][j].b)
                {
                    bov.push_back(j);
                    bov.push_back(i);
                    bov.push_back(1);
                    answer.push_back(bov);
                }
            }
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}