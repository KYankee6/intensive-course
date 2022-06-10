#include <bits/stdc++.h>
using namespace std;

int main()
{
    int answer = 0;
    int N, K;
    cin >> N >> K;
    // for small N,K
    /* while (N != 1)
    {
        if (N % K == 0)
            N /= K; //
        else
            N--;
        answer++;
    } */
    // for larger N,K
    while (N != 1)
    {
        if(N<K)break;
        if (N % K == 0)
        {
            N /= K; 
            answer++;
        }
        else{
            int target = (N/K)*K; //fast substitution   
            answer+=N-target;
            N-=N-target;
        }
    }
    cout << answer+(N-1);
}