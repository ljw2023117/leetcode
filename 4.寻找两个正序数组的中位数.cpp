/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2) return dfs(nums1, 0, nums2, 0, n / 2 + 1); 
        else return (dfs(nums1, 0, nums2, 0, n / 2) + dfs(nums1, 0, nums2, 0, n / 2 + 1)) / 2.0;
    }

    int dfs(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return dfs(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int t = min((int)nums1.size() - i, k / 2);
        if (nums1[i + t - 1] < nums2[j + k - t - 1]) return dfs(nums1, i + t, nums2, j, k - t);
        else if (nums1[i + t - 1] > nums2[j + k - t - 1]) return dfs(nums1, i, nums2, j + k - t, t);
        else return nums1[i + t - 1];
    }
};
// @lc code=end