// 못생긴수
// 2022-05-31 15:48:01

// 모르겠씁니다. .ㅠㅠ
#include <bits/stdc++.h>
using namespace std;

int N;
int main()
{
    cin >> N;
    int arr[1001];
    fill(arr, arr + 1001, 0);
    arr[1] = 1;
    int i2 = 1, i3 = 1, i5 = 1;
    int n2 = 2, n3 = 3, n5 = 5;
    for (int i = 2; i <= N; i++)
    {
        arr[i] = min(min(n2, n3), n5);
        if (arr[i] == n2)
        {
            i2++;
            n2 = arr[i2] * 2;
        }
        if (arr[i] == n3)
        {
            i3++;
            n3 = arr[i3] * 3;
        }
        if (arr[i] == n5)
        {
            i5++;
            n5 = arr[i5] * 5;
        }
    }
    cout << arr[N];
    return 0;
}
