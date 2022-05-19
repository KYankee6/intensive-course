// https://programmers.co.kr/learn/courses/30/lessons/42889
// 실패율
// 2022-05-19 13:06:23

// 2022-05-19 13:52:31 AC
// 틀렸습니다! 가 아니라 0으로 나누고 있어서 터지고 있었다
// 처음 논리도 조금 이상했다
// 20분이라는 시간에 쫄아서 빨리 풀려하다보니 오히려 더 돌아간 느낌이 없잖아 있다.
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<double, int> &p1, const pair<double, int> &p2)
{
    return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
}
vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<double, int>> cnt_v;
    int sum = stages.size();
    cnt_v.resize(N + 2, {0, 0});
    for(int i=0; i<N+2; i++){
        cnt_v[i].first=0;
    }
    for (int i = 0; i < stages.size(); i++)
    {
        cnt_v[stages[i]].first++;
    }
    for (int i = 1; i < cnt_v.size(); i++)
    {
        cnt_v[i].second = i;
        if(sum==0)continue;
        int temp = cnt_v[i].first;
        int divider = sum;
        cnt_v[i].first /= sum;
        sum -= temp;
    }
    sort(cnt_v.begin(), cnt_v.end(), cmp);
    for (int i = 0; i < cnt_v.size(); i++)
    {
        if (cnt_v[i].second == 0 || cnt_v[i].second ==N+1)
            continue;
        else
        {
            answer.push_back(cnt_v[i].second);
        }
    }
    return answer;
}

int main()
{
    vector<int> v = {2, 1, 2, 6, 2, 4, 3, 3};
    solution(9, v);
}