// https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll MOD = 1e9+7;

    ll half_total = 0;
    for (int i=1; i<=n; i++) {
        half_total += i;
    }
    if (half_total%2==1) {
        cout << 0 << "\n";
        return 0;
    }
    half_total/=2;
    vector<vector<ll>> dp(n+1, vector<ll>(half_total+1, 0));
    dp[0][0] = 1;
    for (int r=1; r<=n; r++) {
        for (int c=0; c<half_total+1; c++) {
            dp[r][c] = dp[r-1][c];
            if (c-r>=0 && dp[r-1][c-r]>0) {
                dp[r][c] += dp[r-1][c-r];
                dp[r][c] %= MOD;
            }
        }
    }
    // for (int r=0; r<=n; r++) {
    //     for (int c=0; c<half_total+1; c++) {
    //         cout << dp[r][c] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n-1][half_total] << "\n";
    return 0;
}