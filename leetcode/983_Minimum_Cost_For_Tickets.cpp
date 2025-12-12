// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        dp[0] = costs[0];
        for (int c=0; c<days.size(); c++) {
            if (days[c]-days[0]+1<=7) {
                dp[c] = min(dp[c], costs[1]);
            }
            if (days[c]-days[0]+1<=30) {
                dp[c] = min(dp[c], costs[2]);
            }
        }
        // for (int i: dp) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        for (int c=1; c<days.size(); c++) {
            for (int i=c; i<days.size(); i++) {
                dp[c] = min(dp[c], dp[c-1]+costs[0]);
                if (days[i]-days[c]+1<=7) {
                    // cout << i<< " " <<days[i] << "\n";
                    dp[i] = min(dp[i], dp[c-1]+costs[1]);
                }
                if (days[i]-days[c]+1<=30) {
                    dp[i] = min(dp[i], dp[c-1]+costs[2]);
                }
            }
        }
        // for (int i: dp) {
        //     cout << i << " ";
        // }
        return dp.back();
    }
};

// Notes:
// each dp state represents minimum cost to get there...
// at each state, decide whether to buy and see how many days it can cover