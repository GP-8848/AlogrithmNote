#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 希尔排序
// 使用不同步长进行插入排序，最后使用步长为1使得全局有效
// https://cuijiahua.com/blog/2017/12/algorithm_3.html
void stepInsertSort(vector<int> &vec, int step)
{
    int len = vec.size();
    for (int i = 0; i < step; i++)
    {
        for (int j = i + step; j < len; j += step)
        {
            int cur = vec[j];
            int k = j - step;
            while (k >= 0 && vec[k] > cur)
            {
                vec[k + step] = vec[k];
                k -= step;
            }
            vec[k + step] = cur;
        }
    }
}

int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    printVec(vec);

    int len = vec.size();
    int step = len / 2;
    while (step >= 1)
    {
        stepInsertSort(vec, step);
        step /= 2;
    }
    printVec(vec);
    return 0;
}