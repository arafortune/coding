/*
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
 * 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 * 示例：
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4

 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/binary-search
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "common.h"

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize;
    int mid;

    // 理解搜索区间和边界条件的时间，常见的错误是left和right赋值逻辑与边界条件不匹配
    // 搜索区间为[left, right]时，left可以等于right，下一步搜索区间为[left, mid-1]或[mid+1, right]
    // 搜索区间为[left, right)时，left不能等于right，下一步搜索区间为[left, mid)或[mid+1, right)
    // 区间的定义就是不变量，在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return INVAL;
}

int testcase1() {
    int nums[] = {};
    ASSERT(search(nums, 0, 1), INVAL);
}

int testcase2() {
    int nums[] = {199};
    ASSERT(search(nums, 1, 100), INVAL);
}

int testcase3() {
    int nums[] = {199};
    ASSERT(search(nums, 1, 199), 0);
}

int testcase4() {
    int nums[] = {-1, 0, 3, 5, 9,12};
    ASSERT(search(nums, 6, 9), 4);
}

int testcase5() {
    int nums[] = {-1, 0, 3, 5, 9,12};
    ASSERT(search(nums, 6, 2), INVAL);
}

int main() {
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();
    return SUCCESS;
}
