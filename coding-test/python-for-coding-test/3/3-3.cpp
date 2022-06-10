#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> least_from_row;
    for(int i=0; i<N; i++){
        int least = INT_MAX;
        for(int j=0; j<M; j++){
            int temp;
            cin>>temp;
            if(least>temp){
                least = temp;
            }
        }
        least_from_row.push_back(least);
    }
    cout<<*max_element(least_from_row.begin(),least_from_row.end());
}