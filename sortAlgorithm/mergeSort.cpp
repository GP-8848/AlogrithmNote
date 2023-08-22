#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 归并排序 升序排序
// 分部分排序后合并结果
// https://cuijiahua.com/blog/2018/01/algorithm_7.html
void merge(vector<int> &vec, int ll, int lr, int rl, int rr, vector<int> &cache)
{
    int orill = ll;

    int ind = ll;
    while (ll <= lr && rl <= rr)
    {
        if (vec[ll] < vec[rl])
        {
            cache[ind] = vec[ll];
            ll++;
        }
        else
        {
            cache[ind] = vec[rl];
            rl++;
        }
        ind++;
    }

    while (ll <= lr)
    {
        cache[ind] = vec[ll];
        ll++;
        ind++;
    }

    while (rl <= rr)
    {
        cache[ind] = vec[rl];
        rl++;
        ind++;
    }

    // cache用来辅助排序结果的合并
    // 合并比较大小使用的是vec，必须把结果写回vec
    for (int i = orill; i <= rr; i++)
    {
        vec[i] = cache[i];
    }
}

void mergeSort(vector<int> &vec, int left, int right, vector<int> &res)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid, res);
    mergeSort(vec, mid + 1, right, res);

    merge(vec, left, mid, mid + 1, right, res);
}

int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    int len = vec.size();
    vector<int> cache(len, 0);

    printVec(vec);
    mergeSort(vec, 0, len - 1, cache);
    printVec(vec);
    return 0;
}