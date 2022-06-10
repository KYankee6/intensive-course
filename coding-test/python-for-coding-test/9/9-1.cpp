#include <bits/stdc++.h>
#define INF int(1e9)
using namespace std;

int start;
int V,E;
vector<vector<pair<int,int>>> graph;
vector<bool> visited;
vector<int> dist;

int get_smallest_node(){
    int min_val=INF;
    int result=0;
    for(int i=0; i<dist.size(); i++){
        if(min_val>dist[i] && !visited[i]){
            min_val=dist[i];
            result=i;
        }
    }
    return result;
}

void dijkstra(){
    visited[start]=true;
    dist[start]=0;
    for(int i=0; i<graph[start].size(); i++){
        auto next = graph[start][i];
        int nNode = next.first;
        int nCost = next.second;
        dist[nNode] = nCost;
    }

    for(int i=0; i<V-1; i++){
        int now = get_smallest_node();
        visited[now]=true;
        for(int j=0; j<graph[now].size(); j++){
            auto next = graph[now][j];
            int nNode = next.first;
            int nCost = next.second;
            if(dist[nNode]>dist[now]+nCost){
                dist[nNode]=dist[now]+nCost;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>V>>E>>start;
    start--;
    graph.resize(V);
    visited.resize(V,false);
    dist.resize(V,INF);

    for(int i=0; i<E; i++){
        int src, dest, cost;
        cin>>src>>dest>>cost;
        graph[src-1].push_back(make_pair(dest-1,cost));
    }
    dijkstra();
    for(int i=0; i<V; i++){
        if(dist[i] == INF){
            cout<<("INF ");
        }
        else cout<<dist[i]<<" ";
    }
    return 0;
}