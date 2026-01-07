class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num: nums) {
            int index = bin_search(tails, num);
            if (index==tails.size()) {
                tails.push_back(num);
            } else {
                tails[index] = num;
            }
            // for (int i: tails) {
            //     cout << i << " ";   
            // }
            // cout << "\n\n";
        }

        
        return tails.size();
    }

    int bin_search(vector<int> tails, int target) {
        int l = -1;
        int r = tails.size();
        while (l+1<r) {
            int mid = (r-l)/2 + l;
            // cout << "tails[mid]: " << tails[mid] << "\n";
            // cout << "target: " << target << "\n";
            if (tails[mid]>=target) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};

// Note:
// LIS in O(n log n) time using patience sorting idea
