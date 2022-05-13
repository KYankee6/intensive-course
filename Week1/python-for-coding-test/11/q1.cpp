// 2022-05-13 19:16:05
// 모험가 길드
// 계수 정렬 이용
// 1은 +1
// 2/2
// 3...
// 결국 오름 차순 정렬을 해도 큰 상관은 없을듯.
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int answer=0;
    cin>>N;
    vector<int> v(N+1,0);
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        v[temp]++;
    }
    for(int i=1; i<=N; i++){
        answer+=v[i]/i;
    }
    cout<<answer;
    return 0;
}