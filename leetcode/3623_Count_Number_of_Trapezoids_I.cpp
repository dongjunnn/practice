// https://leetcode.com/problems/count-number-of-trapezoids-i/?envType=daily-question&envId=2025-12-02

inline long long C2(long long n) {
    return (n < 2) ? 0 : ( (__int128)n * (n - 1) ) / 2;
}

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> hashtable;
        for (vector<int> i: points) {
            hashtable[i[1]]++;
        }
        vector<int> temp;
        for (auto [key,val]: hashtable) {
            if (val>=2) {
                temp.push_back(val);
            }
        }
        long long res = 0;
        long long cum = 0;
        for (int i=0; i<temp.size(); i++) {
            // cout << "i: " << temp[i] << "\n";
            if (cum==0) {
                // cum = temp[0];
                cum += C2(temp[i]);
                // cout << "cum: " << cum << "\n";
                // cout << "res: " << res << "\n";
                continue;
            }
            res += C2(temp[i]) * cum;
            res %= (long long) (1e9+7);
            cum += C2(temp[i]);
            // cout << "cum: " << cum << "\n";
            // cout << "res: " << res << "\n";
        }
        // for (int i: temp) cout << i << "\n";
        return res;
    }
};
