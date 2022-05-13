// 2022-05-13 19:57:38
// int vector 10개짜리 만들고 count 계수정렬하기
// vector[i]!=0 이 아니면 조합으로 들어가기
// 전형적인 조합 rCn 문제 (n=2)
// 이중 포문으로 해결
// 2022-05-13 20:11:39 온료

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    int answer = 0;
    cin >> N >> M;
    vector<pair<int, int>> v; //번호 -  무게
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back({i, t});
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(v[i].second!=v[j].second)answer++;
        }
    }

    // temp[0]=true;
    // temp[1]=true;

    // do{
    //     int cnt=0;
    //     int first=
    //     for(int i=0; i<M; i++){
    //         if(temp[i] && v[i]!=0){
    //             cnt++;
    //         }
    //     }
    //     if(cnt==2) answer++;
    // }while(prev_permutation(temp.begin(),temp.end()));
    cout << answer;
}