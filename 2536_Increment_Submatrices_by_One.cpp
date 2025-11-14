// https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (vector<int>& query: queries) {
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
           
            for (int r=r1; r<=r2; r++) {
                matrix[r][c1]++;
                if (c2+1<n) {
                    matrix[r][c2+1]--;
                }
            }

        }
        for (int r=0; r<n; r++) {
            int accum = 0;
            for (int c=0; c<n; c++) {
                accum += matrix[r][c];
                res[r][c] = accum;
            }   
        }
        return res;
    }
};