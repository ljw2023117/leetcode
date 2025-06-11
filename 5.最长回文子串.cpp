/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int k = 0; k < s.size(); k++)
        {
            int i = k - 1, j = k + 1;
            while(i >= 0 && j < s.size() && s[i] == s[j]) 
                i--, j++;
            if (res.size() < j - i - 1) res = s.substr(i + 1, j - i - 1);

            i = k, j = k + 1;
            while(i >= 0 && j < s.size() && s[i] == s[j]) 
                i--, j++;
            if (res.size() < j - i - 1) res = s.substr(i + 1, j - i - 1);
        }
        return res;
    }
};
// @lc code=end

