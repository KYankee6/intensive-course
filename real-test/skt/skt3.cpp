#include <bits/stdc++.h>

using namespace std;

void split1(string &input, int &idx, vector<int> &p1, vector<int> &p2)
{
    stringstream ss(input);
    string temp;
    int i = 0;
    while (getline(ss, temp, ' '))
    {
        if (i == 0)
        {
            p1.push_back(stoi(temp));
            i++;
        }
        else
        {
            p2[stoi(temp)] = idx;
        }
    }
}

void split2(string &input, vector<int> &p1, vector<int> &p2, vector<int> &answer)
{
    int i = 0;
    stringstream ss(input);
    string temp;
    int min_data = 0;
    int max_service = INT_MIN;
    while (getline(ss, temp, ' '))
    {
        if (i == 0)
        {
            min_data = stoi(temp);
            i++;
        }
        else
        {
            if(p2[stoi(temp)]==-1){
                answer.push_back(0);
                return;
            }
            max_service = max(max_service, p2[stoi(temp)]);
        }
    }
    int pos = lower_bound(p1.begin() + max_service, p1.end(), min_data) - p1.begin();
    if (pos == p1.size())
        answer.push_back(0);
    else
    {
        answer.push_back(pos + 1);
    }
}

vector<int> solution(int n, vector<string> plans, vector<string> clients)
{
    vector<int> answer;
    vector<int> p1;
    vector<int> p2(300001, -1);
    for (int i = 0; i < plans.size(); i++)
    {
        split1(plans[i], i, p1, p2);
    }
    for (int i = 0; i < clients.size(); i++)
    {
        split2(clients[i], p1, p2, answer);
    }
    return answer;
}

int main()
{
    vector<string> plans = {
        "100 1 3", "500 4", "2000 5"};
    vector<string> clients = {
        "300 3 5",
        "1500 1",
        "100 1 3",
        "50 1 2"};
    solution(5, plans, clients);
}