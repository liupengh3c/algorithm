// 本文件主要是通过【栈】这种数据结构，解决各种问题

#include <iostream>
#include <stack>
#include <cmath>
#include <ctime>
#include "lp_stack.h"

// 题目：给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 解析：使用栈，也用到了动态规划的思想，内层的while循环，计算当前元素与前面已经入栈的栈顶的两个元素所接到雨水
int lp_stack::trap(vector<int> &height)
{
    int sum = 0, current = 0, distance = 0, depth = 0;
    stack<int> st;

    while (current < height.size())
    {
        while (!st.empty() && height[current] > height[st.top()])
        {
            int top = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            // 如果相等的话，接不住雨水，结束本次循环，不再计算
            if (height[st.top()] == height[top])
            {
                continue;
            }

            distance = current - st.top() - 1;
            // depth 可以理解是楼层，每次计算所接的雨水是位于不同的楼层上的
            // 比如{3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 5}，4-1-2所接的雨水在一层，4-2-3所接的雨水是在二层
            depth = (min(height[st.top()], height[current]) - height[top]);
            sum += distance * depth;
        }
        st.push(current++);
    }
    return sum;
}