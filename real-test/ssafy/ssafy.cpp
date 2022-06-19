// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>
// using namespace std;
// int answer;
// void dfs(int N, int depth, int idx, int sel, vector<int> &v, vector<bool> &visited)
// {
//     if (depth == 2)
//     {
//         answer += sel % v[idx];
//         return;
//     }
//     for (int i = 0; i < N; i++)
//     {
//         if (!visited[i] && depth == 0)
//         {
//             visited[i] = true;
//             dfs(N, depth + 1, i, v[i], v, visited);
//             visited[i] = false;
//         }
//         else if (!visited[i] && depth == 1)
//         {
//             visited[i] = true;
//             dfs(N, depth + 1, i, sel, v, visited);
//             visited[i] = false;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int T;
//     cin >> T;
//     for (int tc = 1; tc <= T; tc++)
//     {
//         answer = 0;
//         int N;
//         cin >> N;
//         vector<int> v(N, 0);
//         vector<bool> visited(N, false);

//         for (int i = 0; i < N; i++)
//         {
//             cin >> v[i];
//         }
//         dfs(N, 0, 0, 0, v, visited);
//         cout << "#" << tc << " " << answer << "\n";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        answer = 0;
        int N;
        cin >> N;
        vector<int> v(N, 0);

        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
            v[i] = v[i] % 2;
        }
        if (N <= 1)
        {
            cout << "#" << tc << " " << answer << "\n";
            continue;
        }
        int start = 0;
        while (start < N)
        {
            bool trig = false;
            if (start + 1 == N)
            {
                break;
            }
            if (v[start] == 0 && v[start + 1] == 0)
            {
                int next_one = start + 1;
                while (v[next_one] != 1)
                {
                    if (next_one >= N)
                    {
                        trig = true;
                        answer = -1;
                        break;
                    }
                    next_one++;
                }
                if(trig)break;
                answer += (next_one - start)-1;
                int temp = v[start+1];
                v[start+1] = v[next_one];
                v[next_one] = temp;
            }
            else if (v[start] == 1 && v[start + 1] == 1)
            {
                int next_zero = start + 1;
                while (v[next_zero] != 0)
                {
                    if (next_zero >= N)
                    {
                        trig = true;
                        answer = -1;
                        break;
                    }
                    next_zero++;
                }
                if(trig)break;
                answer += (next_zero - start)-1;
                int temp = v[start+1];
                v[start+1] = v[next_zero];
                v[next_zero] = temp;
            }
            start+=2;
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}
