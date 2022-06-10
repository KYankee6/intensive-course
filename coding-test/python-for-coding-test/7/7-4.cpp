// 부품찾기
// binary_Serach

#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int>& data, int target){
    int start = 0;
    int end = data.size()-1;
    int mid = 0;
    while(start<=end){
        mid = (start+end)/2;
        if(data[mid]==target){
            return true;
        }
        else if(target>data[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}

int N, M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int> store(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> store[i];
    }
    cin>>M;
    vector<int> request(M,0);
    for (int i = 0; i < M; i++)
    {
        cin >> request[i];
    }
    for(int i=0; i<M; i++){
        if(bs(store, request[i])){
            cout<<"yes ";
        }
        else cout<<"no ";
    }
}
