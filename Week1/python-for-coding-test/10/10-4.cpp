// union-find Cpp type

#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<int> parent;

int get_root(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = get_root(parent[x]);
}

void union_parent(int a, int b)
{
    int pa = get_root(a);
    int pb = get_root(b);

    if (pa < pb)
    {
        parent[pb] = pa;
    }
    else
    {
        parent[pa] = pb;
    }
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

    cin >> V >> E;
    parent.resize(V,0);
    iota(parent.begin(),parent.end(),0);
    bool isCycle=false;
    for(int i=0; i<E; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if (is_unioned(a,b)){
            isCycle=true;
            break;
        }
        else union_parent(a,b);
    }
    if(isCycle){
        cout<<"cycle exist";
    }
    else cout<<"no cycle";
}