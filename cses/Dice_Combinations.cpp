// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int num=1; num<=6; num++) {
            if (i-num>=0) dp[i] += dp[i-num];
            dp[i] %= (ll)(1e9+7);
        }
    }
    // for (int i: dp) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << dp.back() % (ll)(1e9+7) << "\n";
    return 0;
}