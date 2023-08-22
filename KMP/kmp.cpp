#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// next[i]数组表示 最长公共前后缀串
// 以下标0开始的前缀串（不包括i）和以下表i结束的后缀串（不包括0）
void getNext(vector<int> &next, string &needle)
{
    int j = 0;
    next[0] = 0;

    for (int i = 1; i < next.size(); i++)
    {
        while (j > 0 && needle[i] != needle[j]) // j要保证大于0，因为下面有取j-1作为数组下标的操作
        {
            j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
        }
        if (needle[i] == needle[j])
        {
            j++;
        }
        next[i] = j;
    }
}

int main()
{
    // string haystack = "sadbutsad", needle = "uts";
    string haystack = "leetcode", needle = "leeto";

    vector<int> next(needle.size(), 0);
    getNext(next, needle);

    int len = needle.size();
    int nInd = 0;

    for (int hInd = 0; hInd < haystack.size(); hInd++)
    {
        while (nInd > 0 && haystack[hInd] != needle[nInd])
        {
            nInd = next[nInd - 1];
        }

        if (haystack[hInd] == needle[nInd])
        {
            nInd++;
        }
        if (nInd == len)
        {
            cout << hInd - len + 1 << endl;
            return hInd - len + 1;
        }
    }

    cout << -1 << endl;
    return -1;
}