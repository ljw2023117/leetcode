/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        while (s.size() && s[0] == ' ') s.erase(0, 1);
        bool st = true;
        if (s[0] == '+') s.erase(0, 1);
        else if (s[0] == '-') s.erase(0, 1), st = false;
        while (s.size() && s[0] == '0') s.erase(0, 1);
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int t = s[i] - '0';
            if (t < 0 || t > 9) break;
            if (!st) t = -t;
            if (st && res > (INT_MAX - t) / 10) return INT_MAX;
            if (!st && res < (INT_MIN - t) / 10) return INT_MIN;
            res = res * 10 + t;
        }
        return res;
    }
};
// @lc code=end

