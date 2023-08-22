#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 插入排序
// 每次保证前i个数据是有序的
// https://cuijiahua.com/blog/2017/12/algorithm_2.html
void insertSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 1; i < len; i++)
    {
        int cur = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > cur)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = cur;
    }
}
int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    printVec(vec);
    insertSort(vec);
    printVec(vec);
    return 0;
}