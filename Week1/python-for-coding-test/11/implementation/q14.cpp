// 2022-05-17 06:12:52
// 외벽 점검
// N*N*2의 케이스를 모두 담아놓자
// 시계방향/반시계방향을 담는다고 하자.
// 첫번째는 커버리지(벡터), 두번째는 거리로 담는다.
// priority queue로 커버리지 maxheap 사용
// 거리가 가능한 친구가 있다면 덮는다. 이후 pop
// dist -> 거리는 mean heap을 사용하자
// visited 사용해서 그 곳을 체크 했는지 확인도 한다.
// 2022-05-17 07:34:59 72점
// 완탐/dfs 백트래킹인듯

#include <bits/stdc++.h>
using namespace std;

struct obj
{
    int cover_cnt;
    vector<int> idxs;
    int d;

    obj(){};
    obj(int cover_cnt, vector<int> _idxs, int _d) : cover_cnt(_idxs.size()), idxs(_idxs), d(_d){};
};
struct pqcmp
{
    bool operator()(obj const &a, obj const &b)
    {
        return a.cover_cnt == b.cover_cnt ? a.d > b.d : a.cover_cnt < b.cover_cnt;
    }
};
int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;
    int dist_max = *max_element(dist.begin(), dist.end());
    priority_queue<obj, vector<obj>, pqcmp> pq;
    sort(dist.begin(), dist.end());
    for (int cv = dist_max; cv >= 1; cv--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            // 시계
            vector<int> idxs1;
            int cur_distance1 = 0;
            for (int j = i; cur_distance1 <= cv; j++, cur_distance1++)
            {
                if (j >= n)
                    j = 0;
                if (binary_search(weak.begin(), weak.end(), j))
                {
                    idxs1.push_back(j);
                }
            }
            if (!idxs1.empty())
                pq.push(obj(0, idxs1, cur_distance1 - 1));

            // 반시계
            vector<int> idxs2;
            int cur_distance2 = 0;
            for (int j = i; cur_distance2 <= cv; j--, cur_distance2++)
            {
                if (binary_search(weak.begin(), weak.end(), j))
                {
                    idxs2.push_back(j);
                }
                if (j <= 0)
                    j = n;
            }
            if (!idxs2.empty())
                pq.push(obj(0, idxs2, cur_distance2 - 1));
        }
    }

    int man_cnt = 0;
    while (!pq.empty())
    {
        obj cur = pq.top();
        // dist 조합을 써보는것은 어떠니?
        vector<bool> used(dist.size(), false);
        vector<bool> visited(n, false);
        for (int r = 0; r < dist.size(); r++)
        {
            used[r]=true;
            do
            {
                for(int i=0; i<dist.size(); i++){
                    if(used[i]){
                        man_cnt++;
                    }
                }
            } while (prev_permutation(used.begin(), used.end()));
        }

        pq.pop();
        if (accumulate(visited.begin(), visited.end(), 0) == weak.size())
        {
            return accumulate(used.begin(), used.end(), 0);
        }
        if (man_cnt == dist.size())
            break;
    }
    return -1;
}

int main()
{

    vector<int> v1 = {0, 100};
    vector<int> v2 = {1, 1};
    cout << solution(200, v1, v2);
}