#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
    int cost;

    node(){};
    node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost){};
};

vector<node> graph;
vector<vector<int>> dist;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    graph.resize(n);
    dist.resize(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++)
    {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        node newNode(src - 1, dest - 1, cost);
        graph.push_back(newNode);
    }
}