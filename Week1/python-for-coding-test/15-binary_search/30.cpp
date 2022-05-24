#include <bits/stdc++.h>
#define n_child 26
using namespace std;

int to_idx(char a)
{
    return a - 'a';
}

struct Trie
{
    char x;
    Trie *childs[n_child];
    bool isEnd;
    int cnt;
    Trie(){};
    Trie(int _x) : x(_x)
    {
        cnt = 0;
        fill(childs, childs + n_child, nullptr);
        isEnd = false;
    };
    ~Trie()
    {
        for (int i = 0; i < n_child; i++)
        {
            if (childs[i])
            {
                delete childs[i];
            }
        }
    }
    void insert(int idx, string &str)
    {
        if (idx == str.size() - 1)
        {
            isEnd = true;
        }
        else
        {
            if (childs[to_idx(str[idx])] == nullptr)
            {
                Trie *new_trie = new Trie(str[idx]);
                childs[to_idx(str[idx])] = new_trie;
            }
            childs[to_idx(str[idx])]->insert(idx + 1, str);
        }
    }
    bool search(int idx, string &target)
    {
        if (idx == target.size() && childs[to_idx(target[idx - 1])]->isEnd)
        {
            return true;
        }
        else if (target[idx] == '?' || childs[to_idx(target[idx])])
        {
            return childs[to_idx(target[idx])]->search(idx + 1, target);
        }
        else
            return false;
    }
};

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;
    Trie *root = new Trie('.');
    for (int i = 0; i < words.size(); i++)
    {
        root->insert(0, words[i]);
    }

    return answer;
}