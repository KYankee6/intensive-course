// levenshetein algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> dp;
    string s1, s2;
    int size;
    cin >> s1 >> s2;
    size = max(s1.length(), s2.length());
    dp.resize(size, vector<int>(size));

    dp[0][0] = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i < s1.size(); i++)
    {
        for (int j = 1; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
    }
    cout<<dp[s1.size()-1][s2.size()-1];
}