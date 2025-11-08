// https://leetcode.com/problems/maximize-the-minimum-powered-city/description/?envType=daily-question&envId=2025-11-08

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        vector<long long> line_sweep(stations.size(), 0);
        vector<long long> total_power;
        for (long long i=0; i<stations.size(); i++) {
            line_sweep[max(0LL, i-r)]+=stations[i];
            if (i+r+1<line_sweep.size()) {
                line_sweep[i+r+1]-=stations[i];
            }
        }
        long long curr = 0;
        for (long long i:line_sweep) {
            curr += i;
            total_power.push_back(curr);
        }
        // for (long long i: line_sweep) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        // for (long long i: total_power) {
        //     cout << i << " ";
        // }
        long long  l = -1;
        long long R = accumulate(stations.begin(), stations.end(), 0LL) + k+1;
        while (l + 1<R) {
            long long mid = (R-l)/2+l;
            if (check(stations.size(), r, total_power, k, mid)) {
                l = mid;
            } else {
                R= mid;
            }
        }
        return l;
    }

    bool check(long long n, long long r, const vector<long long>& initial_power, long long k, long long target) {
        vector<long long> add_effect(n + 1, 0);
        long long k_used = 0;
        long long current_added_power = 0; 
        for (long long i = 0; i < n; i++) {
            current_added_power += add_effect[i];
            long long current_city_power = initial_power[i] + current_added_power;
            if (current_city_power < target) {
                long long needed = target - current_city_power;
                k_used += needed;
                if (k_used > k) {
                    return false;
                }
                current_added_power += needed;
                long long stop_index = min(n, i + 2 * r + 1);
                add_effect[stop_index] -= needed;
            }
        }        
        return true;
    }
};