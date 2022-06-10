#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    vector<int> coins(N, 0);
    vector<int> dp(10001, INT_MAX);
    dp[0] = 0;
    
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    for(int i=1; i<=10000; i++){
        for(int j=0; j<coins.size(); j++){
            if(dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[M]==INT_MAX)cout<<-1;
    else cout<<dp[M];
}