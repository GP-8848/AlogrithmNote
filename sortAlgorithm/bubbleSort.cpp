#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 冒泡排序：升序排列
// 每次找到最大的值放在数组最右边
// https://cuijiahua.com/blog/2017/12/algorithm_1.html
void bubbleSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}
int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    printVec(vec);
    bubbleSort(vec);
    printVec(vec);
    return 0;
}
