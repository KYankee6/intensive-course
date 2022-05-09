#include <bits/stdc++.h>

using namespace std;

int N, M;
int max_el;
vector<int> rcs;

int get_left_rcs(int standard)
{
    if(standard >= max_el) return 0;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (standard < rcs[i])
            result += rcs[i] - standard;
    }
    return result;
}

int guillotine()
{
    int answer = 0;
    int start = 0;
    int end = 2000000000;
    int mid = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int result = get_left_rcs(mid);
        if (result >= M)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    rcs.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> rcs[i];
    }
    sort(rcs.begin(), rcs.end());
    max_el = rcs[N-1];
    cout << guillotine();
}