// 10-5

#include <bits/stdc++.h>
using namespace std;

int answer;
int V, E;
vector<tuple<int, int, int>> graph;
vector<int> parent;

int get_root(int x)
{
    if (parent[x] == x)
        return x;
    else return parent[x]=get_root(parent[x]);
}

void union_parent(int a, int b){
    int pa = get_root(a);
    int pb = get_root(b);
    if(pa<pb) parent[pb]=pa;
    else parent[pa]=pb;
}

bool is_unioned(int a, int b){
    return get_root(a)==get_root(b);
}

bool cmp(tuple<int, int, int> &t1, tuple<int, int, int> &t2)
{
    return get<2>(t1) < get<2>(t2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    parent.resize(V);
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < E; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        graph.push_back({src - 1, dest - 1, cost});
    }

    sort(graph.begin(), graph.end(), cmp);
    for (int i = 0; i < E; i++)
    {
        int a = get<0>(graph[i]);
        int b = get<1>(graph[i]);
        int cost = get<2>(graph[i]);
        if(!is_unioned(a,b)){
            union_parent(a,b);
            answer+=cost;
        }
    }
    cout<<answer;
    return 0;
}