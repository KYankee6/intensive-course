
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    vector<int> perm;
    int flag = 0;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < N + 1; ++i)
    {
        perm.push_back(i);
    }

    do
    {
        if (flag == 1)
        {
            for (int i = 0; i < perm.size(); ++i)
            {
                cout << perm[i] << endl;
            }
            return 0;
        }

        if (perm == v)
        {
            flag = 1;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    return -1;
}