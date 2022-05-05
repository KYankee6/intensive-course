// 2022-05-05 22:49:38 시작
// 2022-05-05 22:59:59 세팅전 + 끝

#include <bits/stdc++.h>
#define N 8
#define in_range(x,y) x>=0 && y>=0 && x<N && y<N
using namespace std;

int main(){
    int dx[8]={2,2,-2,-2,1,1,-1,-1};
    int dy[8]={1,-1,1,-1,2,-2,2,-2};
    vector<vector<int>> board(N,vector<int>(N,0));
    int answer=0;
    int x,y;
    string s;
    cin>>s;
    x=s[0]-'a';
    y=s[1]-'1';

    for(int i=0; i<8; i++){
        int px = x+dx[i];
        int py = y+dy[i];
        if(in_range(px,py))answer++;
    }
    cout<<answer;

}