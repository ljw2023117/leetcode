/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s;
        p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector(m + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (j + 1 <= m && p[j + 1] == '*') continue;
                if (i && p[j] != '*')
                {
                    if (f[i - 1][j - 1] && (p[j] == s[i] || p[j] == '.'))
                        f[i][j] = true;
                }
                else if (p[j] == '*')
                {
                    for (int k = 0; k <= i; k++)
                    {
                        if (k > 0 && s[i - k + 1] != p[j - 1] && p[j - 1] != '.') break;
                        if (f[i - k][j - 2]) f[i][j] = true;
                    }
                }
            }        
        return f[n][m];
    }
};
// @lc code=end
