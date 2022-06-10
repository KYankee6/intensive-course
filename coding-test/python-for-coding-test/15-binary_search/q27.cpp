// 정렬된 배열에서 특정한 수의 개수 구하기
// 2022-05-19 15:09:37
// O(logN) 즉 이분탐색을 강제하는 문제.

#include <bits/stdc++.h>
using namespace std;

int bs_range(vector<int> &data, int target)
{
    int answer = 0;
    int start = 0;
    int end = data.size();
    int middle;
    while (start <= end)
    {
        middle = (start + end) / 2;
        if (target > data[middle])
        {
            start = middle + 1;
        }
        else if (target < data[middle])
        {
            end = middle - 1;
        }
        else
        { // what if target==middle?
            if (middle == 0 || target < data[middle + 1])
                return 1;
            if (middle == data.size() - 1 || target > data[middle - 1])
                return 1;
            vector<int> left(data.begin(), data.begin() + middle);
            vector<int> right(data.begin() + middle, data.end());
            return bs_range(left, target) + bs_range(right, target);
        }
    }
    return 0;
}

int main()
{
    vector<int> v = {1, 2, 2, 2, 2, 2, 2, 3, 4, 4, 5, 6};
    int x = 2;
    cout << bs_range(v, x);
}