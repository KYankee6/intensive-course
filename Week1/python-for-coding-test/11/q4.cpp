// 2022-05-13 19:28:08
// 만들 수 없는 금액
// 오름 차순 sort후 앞에서부터 더해가기?
// 이게 왜 난이도 1?

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int target=1;
    for(int i=0; i<N; i++){
        if(target<v[i]) break;
        target+= v[i];
    }
    cout<<target;
}
