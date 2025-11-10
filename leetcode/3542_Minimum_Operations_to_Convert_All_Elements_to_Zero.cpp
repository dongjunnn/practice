//https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/?envType=daily-question&envId=2025-11-10
// Note: the intuition is to count the number of segments
// this can be done with a monotonic stack in O(N)
// keyword: segments -> monotonic stack

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stack;
        int res=0;
        for (int num: nums) {
            while (!stack.empty() && num<stack.back()) {
                stack.pop_back();
            } 
            if (stack.empty()) {
                stack.push_back(num);
                if (num!=0) {
                    ++res;
                }
            
            } else if (num>stack.back()) {
                stack.push_back(num);
                ++res;
            }
            //cout << res << " " << num << "\n";
        }
        return res;
    }
};