// https://programmers.co.kr/learn/courses/30/lessons/60058
// 2022-05-18 00:45:26 시작
// 2022-05-18 01:26:03 aC
// 너무 오래걸림
//  문제 이해를 잘 하고 시작하자 vs 빨리 구현하자의 싸움
// 아니 근데 이게 왜 bfs?
#include <bits/stdc++.h>

using namespace std;

void flip(string &s)
{
    for (char &c : s)
    {
        if (c == '(')
            c = ')';
        else
            c = '(';
    }
}

bool check_bal(string &s)
{
    int cnt = 0;
    if (s.size() % 2 != 0)
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
    }
    return cnt == s.size() / 2;
}

bool check_match(string &s)
{

    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt < 0)
            return false;
    }
    return cnt == 0;
}

int strsplit(string s)
{
    int i = 0;
    int l = 0, r = 0;
    for (i; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            l++;
        }
        else
            r++;
        if (l == r)
            break;
    }
    return i;
}

string task(string& s)
{
    if (s.empty())
        return s;
    string u = s.substr(0, strsplit(s)+1);
    string v = s.substr(strsplit(s)+1);
    if (check_match(u))
        return u += task(v);
    else
    {
        string empty = "(";
        empty += task(v) + ")";
        u.erase(u.begin()), u.erase(u.end()-1);
        flip(u);
        return empty+u;
    }
}

string solution(string p)
{
    string answer = "";
    answer = task(p);
    return answer;
}

int main(){
    cout<<solution(")(");
}