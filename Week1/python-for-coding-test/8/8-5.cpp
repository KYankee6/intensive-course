// 2022-05-10 00:07:24
//  1로 만들기
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int dp[30001];
    fill(dp, dp + 30001, INT_MAX);
    dp[1] = 0;
    cin>>N;
    for (int i = 2; i <= 30000; i++)
    {
        if (i % 5 == 0)
        {
            dp[i] = min(dp[i / 5] + 1, dp[i]);
        }
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    cout<<(dp[N]);
    return 0;
}