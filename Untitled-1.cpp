#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    vector<int> v;
    vector<int> first;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        first.push_back(temp);
    }

    sort(first.begin(), first.end());
    next_permutation(v.begin(), v.end());
    bool temp = false;
    for (int i = 0; i < N; i++)
    {
        if (first[i] != v[i])
            temp = true;
    }
    if (!temp)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << v[i] << " ";
        }
    }

    return 0;
}