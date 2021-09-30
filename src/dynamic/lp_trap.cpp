#include "lp_dynamic.h"

#include <iostream>
#include <cmath>
// 题目：给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 要求：传统做法时间复杂度n方，动态规划n
// 解析：当前位置左右两边的最小值(min)大于当前值，才能接到雨水，两边不能接雨水，接到的雨水数量为：min-当前值，
int lp_dynamic::trap(vector<int> &height)
{

    int len = 0, sum = 0;
    len = height.size();
    // 判断height是否为空
    if (0 == len)
    {
        return 0;
    }
    vector<int> left_max(len);
    vector<int> right_max(len);
    left_max[0] = height[0];
    right_max[len - 1] = height[len - 1];
    // 计算左侧最大值
    for (int i = 1; i < len; i++)
    {
        left_max[i] = max(left_max[i - 1], height[i]);
    }
    // 计算右侧最大值
    for (int i = len - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], height[i]);
    }
    // 计算接水量
    for (size_t i = 0; i < len; i++)
    {
        // sum += (min(left_max[i], right_max[i]) - height[i] > 0) ? min(left_max[i], right_max[i]) - height[i] : 0;
        sum += min(left_max[i], right_max[i]) - height[i];
    }
    return sum;
}
