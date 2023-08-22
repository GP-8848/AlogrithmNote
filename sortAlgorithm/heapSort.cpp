#include <bits/stdc++.h>
#include <iostream>
#include "out.h"
using namespace std;

// 堆排序 升序排序
// 大顶堆，每次取最大值放最后面
// https://cuijiahua.com/blog/2018/01/algorithm_6.html

// 堆调整：从后向前，遇到不符合规则的话从当前调整到底
void heapAdjust(vector<int> &vec, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        int father = i;
        while (father < len)
        {
            // 左右儿子
            int left = 2 * father + 1;
            int right = 2 * father + 2;

            if (left >= len)
            {
                // 无左右儿子
                break;
            }
            else if (right >= len)
            {
                // 只有左儿子
                if (vec[father] < vec[left])
                {
                    swap(vec[father], vec[left]);
                    father = left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                // 左右儿子都存在
                if (vec[father] >= max(vec[left], vec[right]))
                {
                    break;
                }
                else if (vec[left] > vec[father] && vec[left] >= vec[right])
                {
                    swap(vec[father], vec[left]);
                    father = left;
                }
                else
                {
                    swap(vec[father], vec[right]);
                    father = right;
                }
            }
        }
    }
}
void heapSort(vector<int> &vec)
{
    int len = vec.size();
    while (len > 0)
    {
        heapAdjust(vec, len);

        swap(vec[0], vec[len - 1]);
        len--;
    }
}

int main()
{
    vector<int> vec = {9, 3, 45, 5, 2, 34, 6788, 5};
    printVec(vec);
    heapSort(vec);
    printVec(vec);
    return 0;
}