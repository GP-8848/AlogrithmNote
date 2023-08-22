#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 快速排序 升序排序
// pivot两侧的数据分别小于等于和大于vec[pivot]
// 左闭右闭区间
// https://cuijiahua.com/blog/2017/12/algorithm_4.html
void quickSort(vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;
    int orileft = left, oriright = right;

    int pivotV = vec[left];
    while (left < right)
    {
        // 首先得到一个可以放小于等于pivotV值的槽，所以先遍历右边
        // 将右侧比pivot小于等于的值放到左边
        while (left < right && vec[right] > pivotV)
        {
            right--;
        }
        if (left < right)
        {
            vec[left] = vec[right];
            left++;
        }

        while (left < right && vec[left] <= pivotV)
        {
            left++;
        }
        if (left < right)
        {
            vec[right] = vec[left];
            right--;
        }
    }

    // left==right时候找到pivot
    vec[left] = pivotV;
    quickSort(vec, orileft, left - 1);
    quickSort(vec, left + 1, oriright);
}

int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    printVec(vec);

    int len = vec.size();
    quickSort(vec, 0, len - 1);
    printVec(vec);
    return 0;
}