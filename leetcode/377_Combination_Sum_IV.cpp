// https://leetcode.com/problems/combination-sum-iv/description/

#define ll unsigned int

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ll> dp(target + 1, 0);
        dp[0] = 1; 
        for (int c = 1; c < target + 1; c++) {
            for (int num : nums) {
                if (c - num >= 0) {
                    dp[c] += dp[c - num];
                }
            }
        }
        return dp[target];
    }
};

// Note 2D:
// Order DOES NOT matter (Combinations): (1, 2) is the same as (2, 1).
// OR You can only use each item ONCE (0/1 Knapsack).

// Note 1D:
// Order DOES matter (Permutations): (1, 2) is distinct from (2, 1).
// AND You can reuse items infinitely.