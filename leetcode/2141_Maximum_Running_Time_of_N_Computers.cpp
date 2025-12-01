// https://leetcode.com/problems/maximum-running-time-of-n-computers/?envType=daily-question&envId=2025-12-01

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0;
        long long r = (long long) accumulate(batteries.begin(), batteries.end(), 0LL)+1;
        while (l+1<r) {
            long long mid = (r-l)/2+l;
            if (check(n, mid, batteries)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }

    bool check(int n, long long target, vector<int>& batteries) {
        long long res = 0;
        for (int i: batteries) {
            res+=min((long long) i, (long long) target);
        }
        return res>=n*target;
    }
};