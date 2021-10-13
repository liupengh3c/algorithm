#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

#include "lp_array.h"
#include "lp_dynamic.h"
#include "lp_stack.h"
using namespace std;

const int MENU_QUIT = 0;
int main(void)
{
    string menu = "\n\n算法学习:\n\
        1. 删除排序数组中的重复项.\n\
        2. 接雨水问题.\n\
        0. quit.\n";

    int number;
    string file_name;
    lp_array algo_arr;
    lp_dynamic dynamic;
    lp_stack dy_stack;

    vector<int> nums;
    time_t start;
    do
    {
        cout << menu << endl;
        cout << "please select a number:";
        while (!(cin >> number))
        {
            // 重置cin以接受新的输入
            cin.clear();
            // 删除错误输入
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "please input a number:";
        }
        start = clock();
        switch (number)
        {
        case 1:
            int len;
            nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
            len = algo_arr.removeDuplicates(nums);
            for (size_t i = 0; i < len; i++)
            {
                cout << nums[i] << '\t';
            }
            cout << "\nthe time of algo cost: " << 1000.0 * float(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
            break;
        case 2:
            int sum;
            // nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
            nums = {3, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 5};
            sum = dynamic.trap(nums);
            cout << "\nthe time of algo(dynamic) cost: " << 1000.0 * float(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
            cout << "the total(dynamic) is: " << sum << endl;
            start = clock();
            sum = dy_stack.trap(nums);
            cout << "\nthe time of algo(stack) cost: " << 1000.0 * float(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
            cout << "the total(stack) is: " << sum << endl;
            break;
        default:
            cout << "user quit." << endl;
        }
    } while (number != MENU_QUIT);
    return 0;
}