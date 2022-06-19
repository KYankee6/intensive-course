#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p)
{
    vector<int> answer;
    answer.resize(p.size(), 0);
    for (int i = 0; i < p.size(); i++)
    {
        int min_val = p[i];
        int min_idx = i;
        for (int j = i; j < p.size(); j++)
        {
            if (min_val > p[j])
            {
                min_idx = j;
                min_val = p[j];
            }
        }
        if (min_idx != i)
        {
            answer[i]++;
            answer[min_idx]++;
            swap(p[i],p[min_idx]);
        }
    }
    return answer;
}