// 성적이 낮은 순서로 학생 출력하기
// 2022-05-06 19:19:55 시작
// C++ MAP은 SORT가 안되용~
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    map<string, int> m;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        int val;
        cin >> s >> val;
        m[s] = val;
    }
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),compare);
    for (auto p : v)
    {
        cout << p.first << " ";
    }
    return 0;
}