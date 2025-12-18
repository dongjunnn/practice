// https://leetcode.com/problems/maximum-students-taking-exam/

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        // DP[row][mask of previous row used to achieve max at this state]
        int R = seats.size();  
        int C = seats[0].size();

        vector<int> masks(R, 0);
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                if (seats[r][c]=='#') {
                    masks[r] |= 1<<c;
                }
            }
        }

        vector<vector<int>> dp(R+1, vector<int>(1<<C, -1)); 
        dp[0][0] = 0;
        for (int r = 1; r <= R; r++) { 
            int broken = masks[r-1];
            
            for (int curr = 0; curr < (1 << C); curr++) {                
                if ((curr & broken) == 0 && (curr & (curr >> 1)) == 0) {
                    for (int prev = 0; prev < (1 << C); prev++) {
                        if (dp[r-1][prev] == -1) continue;
                        if ((curr & (prev << 1)) == 0 && (curr & (prev >> 1)) == 0) {
                            int students = __builtin_popcount(curr);                            
                            dp[r][curr] = max(dp[r][curr], dp[r-1][prev] + students);
                        }
                    }
                }
            }
        }
        int max_students = 0;
        for (int mask = 0; mask < (1 << C); mask++) {
            max_students = max(max_students, dp[R][mask]);
        }
        return max_students;
    }
};

// strat: bitmask DP
// DP from first row to last row
// Preprocess by finding broken seats in each row as a bitmask
// For DP, with all possible config of curr row, check all possible config of row above
// config is represented by a bitmask
// O(R * 2^C * 2^C) = O(R * 4^C)