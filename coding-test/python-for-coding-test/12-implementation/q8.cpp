#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    sort(s.begin(), s.end());
    for (auto it = s.begin(); it != s.end();)
    {
        if (*it < 'A')
        {
            sum += *it-'0';
            it = s.erase(it);
        }
        else
            it++;
    }
    s += to_string(sum);
    cout << s;
}