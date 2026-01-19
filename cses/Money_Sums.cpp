// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    vector<ll> coins;
    cin >> n;
    for (int i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        coins.push_back(temp);
    }
    ll sum = accumulate(coins.begin(), coins.end(), 0LL);
    vector<vector<ll>> dp(n, vector<ll>(sum+1, 0));
    dp[0][0] = 1;
    dp[0][coins[0]] = 1;
    for (int r=1; r<n; r++) {
        for (int c=0; c<sum+1; c++) {
            if (c-coins[r]>=0 && dp[r-1][c-coins[r]]==1) {
                dp[r][c] = dp[r-1][c-coins[r]];
            }
            if (dp[r-1][c]==1) {
                dp[r][c] = dp[r-1][c];
            }
            dp[r][coins[r]] = 1;
        }
    }
    unordered_set<ll> hashset;
    for (int r=0; r<n; r++) {
        for (int c=0; c<sum+1; c++) {
            if (dp[r][c]==1) {
                // cout << c << " ";
              
                hashset.insert(c);
            }
        }
    }
    // cout << "\n";
    // for (ll i: hashset) {
    //     cout << i << " ";
    // }
    vector<ll> output(hashset.begin(), hashset.end());
    sort(output.begin(), output.end());
    cout << output.size() - 1 << "\n";
    for (int i=1; i<output.size(); i++) {
        cout << output[i] << " ";
    }
    // cout << accumulate(hashset.begin(), hashset.end(), 0LL) << "\n";
    // cout << res;
    return 0;
}