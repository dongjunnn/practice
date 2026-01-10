// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    vector<ll> coins;
    cin >> n;
    cin >> x;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    vector<ll> dp(x+1, 1e9);
    dp[0] = 0;
    for (int i=1; i<=x; i++) {
        for (ll coin: coins) {
            if (i-coin>=0) {
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }
    // for (int i: dp) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << (dp.back() == 1e9 ? -1 : dp.back()) << "\n";
    return 0;
}