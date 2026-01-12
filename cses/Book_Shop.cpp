// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x, temp;
    cin >> n >> x;
    vector<int> prices;
    vector<int> pages;
    for (int i=0; i<n; i++) {
        cin >> temp;
        prices.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        cin >> temp;
        pages.push_back(temp);
    }
    vector<int> dp(x+1, 0);
    for (int i=0; i<n; i++) {
        vector<int> temp_dp(x+1, 0);
        for (int j=0; j<=x; j++) {
            if (j - prices[i] >= 0) {
                temp_dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
            } else {
                temp_dp[j] = dp[j];
            }
        }
        dp = temp_dp;
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}