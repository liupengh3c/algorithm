#include "lp_array.h"
#include <iostream>
#include <vector>

using namespace std;
// 题目：存在一个有序数组nums，请删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度
// 要求：不使用额外的数组空间，必须在原地修改输入数组，并在使用O(1)额外空间的条件下完成
// 解析：双指针问题，左指针用于改变数组的值，右指针移动进行遍历。
int lp_array::removeDuplicates(vector<int> &nums)
{
    // 初始值，这里注意，只要数组存在，即使数组元素全部相同，长度为1,所以初始值不能为0
    int len = 1;
    // 判断nums是否为空
    if (nums.size() == 0)
    {
        return 0;
    }
    vector<int>::iterator left, right;
    left = right = nums.begin();
    for (int i = 0; i < nums.size(); i++)
    {
        if (*left != *right)
        {
            left++;
            // if (left != right)
            // {
            //     *left = *right;
            // }

            // 直接赋值性能好一点
            *left = *right;
            len++;
        }
        // 如果相等，右指针移动，左指针不动
        right++;
    }
    return len;
}