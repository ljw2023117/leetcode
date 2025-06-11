/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        unsigned long long temp = x, res = 0;
        while (temp)
        {
            res = res * 10 + temp % 10;
            temp /= 10;
        }
        if (res == x) return true;
        else return false;
    }
};
// @lc code=end

