/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;
        string res;
        int t = 0;
        while(t < s.size()) res.push_back(s[t]), t += 2 * n - 2;
        for (int i = 1; i < n - 1; i++)
        {
            int a = (n - i - 1) * 2, b = i * 2;
            int t = i;
            bool st = true;
            while (t < s.size())
            {
                res.push_back(s[t]);
                if (st) t += a, st = !st;
                else t += b, st = !st;
            }
        }
        t = n - 1;
        while(t < s.size()) res.push_back(s[t]), t += 2 * n - 2;
        return res;
    }
};
// @lc code=end

