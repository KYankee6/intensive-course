#include <bits/stdc++.h>

using namespace std;

bool cur_vip();
bool next_vip();

void find_answer(vector<bool> &cur, vector<bool> &next, vector<int> &answer)
{
    for (int i = 0; i < cur.size(); i++)
    {
        if (!cur[i] && next[i])
            answer[0]++;
        if (cur[i] && !next[i])
            answer[1]++;
    }
    return;
}

void find_cur_vips(vector<bool> &cv, vector<int> &periods, vector<int> &summation)
{
    for (int i = 0; i < periods.size(); i++)
    {
        if (periods[i] < 24)
            continue;
        if (summation[i] >= 900000)
        {
            if (periods[i] >= 24)
            {
                cv[i] = true;
                continue;
            }
        }
        if (summation[i] >= 600000)
        {
            if (periods[i] >= 60)
                cv[i] = true;
        }
    }
    return;
}

void find_next_vips(vector<bool> &cv, vector<int> &periods, vector<int> &summation)
{
    for (int i = 0; i < periods.size(); i++)
    {
        if (periods[i] + 1 < 24)
            continue;
        if (summation[i] >= 900000)
        {
            if (periods[i] + 1 >= 24)
            {
                cv[i] = true;
                continue;
            }
        }
        if (summation[i] >= 600000)
        {
            if (periods[i] + 1 >= 60)
                cv[i] = true;
        }
    }
    return;
}

vector<int> solution(vector<int> periods, vector<vector<int>> payments, vector<int> estimates)
{
    vector<int> answer(2,0);
    vector<int> summation1(periods.size());
    vector<int> summation2(periods.size());
    vector<bool> cur_vips(periods.size());
    vector<bool> next_vips(periods.size());
    for (int i = 0; i < payments.size(); i++)
    {
        summation1[i] = accumulate(payments[i].begin(), payments[i].end(), 0);
    }
    for (int i = 0; i < payments.size(); i++)
    {
        summation2[i] = summation1[i] - payments[i][0] + estimates[i];
    }
    find_cur_vips(cur_vips, periods, summation1);
    find_next_vips(next_vips, periods, summation2);
    find_answer(cur_vips,next_vips,answer);
    return answer;
}