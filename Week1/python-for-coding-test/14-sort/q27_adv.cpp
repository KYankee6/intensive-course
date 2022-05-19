// upper_bound(), lower_bound() 예제
// lower_bound()는 key값보다 같거나, 큰 값이 언제 첫번째에 나오느냐
// upper_bound()는 key값 보다 큰 수가 언제 나오느냐
// 둘다 iterator를 반환

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int target = 0;
    vector<int> data = {1, 2, 2, 2, 2, 4, 5, 6, 7, 8, 9, 9, 10, 10, 10, 11};
    auto lb_2 = lower_bound(data.begin(), data.end(), 2) - data.begin();
    auto ub_2 = upper_bound(data.begin(), data.end(), 2) - data.begin();
    cout << "2's lower bound: " << lb_2 << "    2's upper bound: " << ub_2 << endl;
    auto lb_11 = lower_bound(data.begin(), data.end(), 11) - data.begin();
    auto ub_11 = upper_bound(data.begin(), data.end(), 11) - data.begin();

    cout << "11's lower bound: " << lb_11 << "   11's upper bound: " << ub_11 << endl;
    cout << "data's size(): " << data.size() << endl;
    cout << data.end() - data.begin() << endl;
    cout << upper_bound(data.begin(), data.end(), target) - lower_bound(data.begin(), data.end(), target) << endl;
    cout << upper_bound(data.begin(), data.end(), target) - data.begin() << endl;
    cout << lower_bound(data.begin(), data.end(), target) - data.begin() << endl;
    return 0;
}