#include "array/lp_array.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

const int MENU_MAX = 2;
int main(void)
{
    string menu = "\n\n算法学习:\n\
        1. 删除排序数组中的重复项.\n\
        2. quit.\n";

    int number;
    string file_name;
    lp_array algo_arr;
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
        default:
            cout << "user quit." << endl;
        }
    } while (number != MENU_MAX);
    return 0;
}