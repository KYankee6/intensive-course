// 2022-05-10 00:21:44
// 바닥공사

// 못풀겠어용..

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int dp[1002];
    fill(dp,dp+1002,0);
    dp[0]=-1;
    dp[1]=1;
    dp[2]=3;
    for(int i=3; i<=1000; i++){
        dp[i]=(dp[i-2]*2+dp[i-1])%796796;
    }
    cout<<dp[N];
}