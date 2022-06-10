// 2022-05-10 00:07:15
// 개미전사
// dp 두개 만들면 되지 않을까요?

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N,0);
    vector<int> dp(N,0);
    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);
    for(int i=2; i<N; i++){
        dp[i]= max(dp[i-1],dp[i-2]+v[i]);
    }
    cout<<dp[N-1];

    // 이런 답변을 생각 해봤으나 
    // TC -> 4 8 1 1 8이 반례가 됩니다.
    // int answer1=0;
    // int answer2=0;
    // for(int i=0; i<N; i++){
    //     int temp;
    //     cin>> temp;
    //     if(i%2==0) answer1+=temp;
    //     else answer2+=temp;
    // }
    // cout<<max(answer1,answer2);
}