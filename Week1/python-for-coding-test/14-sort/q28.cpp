// 2022-05-19 16:03:32
// 고정점 찾기

#include <bits/stdc++.h>
using namespace std;
bool isfound = false;
void getpos(vector<int> &data, int start, int end)
{
    if (start > end)
        return;
    int mid = (start + end) / 2;
    if (mid == data[mid])
    {
        cout << mid;
        isfound = true;
        return;
    }
    if (mid <= data[mid])
    {
        getpos(data, start, mid - 1);
    }
    else
    {
        getpos(data, mid + 1, end);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // vector<int> data = {1, 2, 3, 3, 4, 4, 5, 5, 6, 7};
    // vector<int> data = {-15,-6,1,3,7};
    // vector<int> data = {-15,-4,2,8,9,13,15};
    vector<int> data = {-15, -4, 3, 8, 9, 13, 15};
    int N = data.size();
    getpos(data, 0, N);
    if (!isfound)
        cout << -1;
    return 0;
}