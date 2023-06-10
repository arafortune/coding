#include "common.h"

/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
int removeDuplicates(int* nums, int numsSize) {
    int single_size = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[single_size] != nums[i]) {
            nums[++single_size] = nums[i];
        }
    }
    return single_size+1;
}

void test(int* nums, int* expectedNums, int size) {
    int expectedSize = removeDuplicates(nums, size);
    for (int i = 0; i < expectedSize; i++) {
        ASSERT(nums[i], expectedNums[i]);
    }
}

void testcase1() {
    int nums[] = {1, 1, 2};
    int expectedNums[] = {1, 2};
    test(nums, expectedNums, ARRAY_SIZE(nums));
}

void testcase2() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int expectedNums[] = {0, 1, 2, 3, 4};
    test(nums, expectedNums, ARRAY_SIZE(nums));
}

int main() {
    testcase1();
    testcase2();
    return 0;
}

