// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/?envType=daily-question&envId=2026-01-19

class Solution {
public:
    int R;
    int C;
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        R = mat.size();
        C = mat[0].size();

        vector<vector<int>> prefix(R, vector<int>(C, 0));
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                prefix[r][c] = mat[r][c];
                if (c-1>=0) {
                    prefix[r][c] += prefix[r][c-1];
                }
                if (r-1>=0) {
                    prefix[r][c] += prefix[r-1][c];
                }
                if (r-1>=0 && c-1>=0) {
                    prefix[r][c] -= prefix[r-1][c-1];
                }
                cout << prefix[r][c] << " ";
            }
            cout << "\n";
        }

        int l = 0;
        int r = min(R, C)+1;

        while (l+1<r) {
            int mid = (r-l)/2+l;
            cout << "mid: " << mid << "\n";
            cout << "check: " << check(prefix, mid, threshold) << "\n";
            if (check(prefix, mid, threshold)) {
                l = mid;
            } else {
                r = mid;
            }
        }
    
        return l;
    }

    int check(vector<vector<int>>& prefix, int target, int threshold) {
        for (int r=target-1; r<R; r++) {
            for (int c=target-1; c<C; c++) {
                //if (r-target+1<0 || c+target+1<0) continue;

                int area = prefix[r][c];
                if (r-target>=0) {
                    area -= prefix[r-target][c];
                }
                if (c-target>=0) {
                    area -= prefix[r][c-target];
                }
                if (c-target>=0 && r-target>=0) {
                    area += prefix[r-target][c-target];
                }
                if (area<=threshold) {
                    cout << "\n";
                    cout << "r: " << r << " ";
                    cout << "c: " << c << "\n";
                    return 1;
                }
            }
        }

        return 0;
    }
};

// note: prefix sum + binary search
// 2d prefix sum: prefix[i][j] = arr[i][j] + prefix[i-1][j]  + prefix[i][j-1] - prefix[i-1][j-1]