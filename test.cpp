#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1};
    cout <<lower_bound(v.begin(),v.end(),2)-v.begin();
}