// https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<long long, long long> hashtable;
        long long prefix_sum = 0;
        long long res = LLONG_MAX;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - total/p*p;
        if (target==0) return 0;
        // cout << target << "\n";
        hashtable[0] = -1;

        for (long long i=0; i<nums.size(); i++) {
            prefix_sum = prefix_sum+nums[i];
            // cout << "prefix_sum " << prefix_sum << "\n";
            // target = prefix_sum%p - hashed%p
            // if (hashtable.find(target-prefix_sum%p)!=hashtable.end()) {
            //     res = min(res, i-hashtable[target-prefix_sum%p]);
            // }
            if (hashtable.find((prefix_sum-target)%p)!=hashtable.end()) {
                res = min(res, i-hashtable[(prefix_sum-target)%p]);
            }
            hashtable[prefix_sum%p] = i;
            // cout << "key:" << prefix_sum%p << " val:" << i << "\n";
        }
        return res==nums.size()?-1:res;
    }
};