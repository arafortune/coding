/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.58%)
 * Likes:    6561
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start

#include "common.h"

int searchPalindrome(char *s, int sLen, int left, int right, int *start) {
    while (left >= 0 && right < sLen && s[left] == s[right]) {
        left--;
        right++;
    }
    *start = left+1;
    return right-left-1;
}

char * longestPalindrome(char * s){
    int sLen = strlen(s);
    int resultStart = 0;
    int resultLen = 0;
    int s1Start = 0, s2Start = 0;
    for (int i = 0; i < sLen; i++) {
        int s1Len = searchPalindrome(s, sLen, i, i, &s1Start);
        int s2Len = searchPalindrome(s, sLen, i, i+1, &s2Start);
        if (s1Len > resultLen) {
            resultStart = s1Start;
            resultLen = s1Len;
        }

        if (s2Len > resultLen) {
            resultStart = s2Start;
            resultLen = s2Len;
        }
    }
    s[resultStart+resultLen] = '\0';
    return s+resultStart;
}

// @lc code=end


