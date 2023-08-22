#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 选择排序
// 每次从余下的未排序数组中选择最小值放在数组前面
// https://cuijiahua.com/blog/2017/12/algorithm_5.html
void selectSort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 0; i < len - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < len; j++)
        {
            if (vec[j] < vec[minInd])
            {
                minInd = j;
            }
        }
        swap(vec[i], vec[minInd]);
    }
}

int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    printVec(vec);
    selectSort(vec);
    printVec(vec);
    return 0;
}