// UF 간단한 예제

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> parent;

int get_root(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = get_root(parent[x]);
}

void union_parent(int a, int b)
{
    int pa = get_root(a);
    int pb = get_root(b);
    if (pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}

bool is_unioned(int a, int b)
{
    return get_root(a) == get_root(b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < M; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        switch (op)
        {
        case 0:
        {
            union_parent(a, b);
            break;
        }
        case 1:
        {
            if (!is_unioned(a, b))
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
            break;
        }
        }
    }
    return 0;
}