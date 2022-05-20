// https://www.acmicpc.net/problem/2110
// 공유기 설치
// 2022-05-19 16:20:47
// 실패!
// 2022-05-20 13:10:10

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C;
    int answer = 0;
    cin >> N >> C;
    vector<int> house;
    house.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    int min_gap = 0;
    int max_gap = house[house.size() - 1] - house[0];
    while (min_gap <= max_gap)
    {
        int cnt = 1;
        int cur_gap = (min_gap + max_gap) / 2;
        int trav_gap = house[0];
        for (int i = 1; i < house.size(); i++)
        {
            int cur_pos = house[i];
            if (trav_gap + cur_gap <= cur_pos)
            {
                cnt++;
                trav_gap = house[i];
            }
        }
        if (cnt >= C)
        {
            answer = max(cur_gap, answer);
            min_gap = cur_gap + 1;
        }
        else
        {
            max_gap = cur_gap - 1;
        }
    }
    cout << answer;
}