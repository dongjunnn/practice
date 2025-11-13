//https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

class Solution {
public:
    int maxOperations(string s) {
        int curr_count = 0;
        int res = 0;
        int prev_i = s.length();

        for (int i=s.length()-1; i>=0; i--) {
            if (s[i]=='1' && prev_i-i>1) {
                curr_count++;
                res += curr_count;
                prev_i = i;
            } else if (s[i]=='1') {
                res += curr_count;
                prev_i = i;
            }
            // cout << res << "\n";
        }
        return res;
    }
};