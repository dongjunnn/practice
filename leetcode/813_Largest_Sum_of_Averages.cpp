// https://leetcode.com/problems/largest-sum-of-averages/

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(), vector<double>(nums.size(), 0));

        for (int r=0; r<nums.size(); r++) {
            double curr = 0;
            for (int c=r; c<nums.size(); c++) {
                curr += nums[c];
                dp[r][c] = curr/(c-r+1);
            }
        }

        // for (int r=0; r<nums.size(); r++) {
        //     for (int c=0; c<nums.size(); c++) {
        //         cout << dp[r][c] << " ";
        //     }
        //     cout << "\n";
        // }
        vector<vector<double>> dp1(k, vector<double>(nums.size(), 0));
        for (int j=0; j<nums.size(); j++) {
            dp1[0][j] = dp[0][j];
        }
        for (int r=1; r<k; r++) {
            for (int i=r; i<nums.size(); i++) {
                for (int j=i; j<nums.size(); j++) {
                    dp1[r][j] = max(dp1[r][j], dp[i][j]+dp1[r-1][i-1]);
                }
            }
        }
        // cout << "\n";
        // for (int r=0; r<k; r++) {
        //     for (int c=0; c<nums.size(); c++) {
        //         cout << dp1[r][c] << " ";
        //     }
        //     cout << "\n";
        // }
        return dp1.back().back();

    }
};

// Note:
// create lookup table -> table[start_ind][end_ind]
// do dp partition style for k partitions with triple for loop 
// row -> start -> end