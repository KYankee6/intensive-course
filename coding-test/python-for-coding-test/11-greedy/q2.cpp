// 2022-05-13 19:15:58
// 곱하기 혹은 더하기
// 0이면 더하고 아니면 곱하면 된다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int answer;
    string s;
    cin >> s;
    answer = s[0] - '0';
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '0')
        {
            answer += s[i + 1] - '0';
        }
        else
            answer *= s[i + 1] - '0';
    }
    cout << answer;
    return 0;
}