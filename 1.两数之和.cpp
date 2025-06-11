/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hash; 
       for (int i = 0; i < nums.size(); i++)
       {
            int t = target - nums[i];
            if (hash.count(t)) return {hash[t], i};
            hash[nums[i]] = i;
       }
       return {-1, -1};
    }
};
// @lc code=end

