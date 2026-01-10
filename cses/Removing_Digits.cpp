// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> dp(n+1, 1e9);
    dp[n] = 0;
    for (int i=n+1; i>=0; i--) {
        if (dp[i-1]==1e9) {
            continue;
        } 
        int num = i-1;
        for (int curr=num; curr>0; curr/=10) {
            int digit = curr%10;
            // cout << digit << "\n";
            dp[num-digit] = min(dp[num-digit], dp[num] + 1);
        }
    }
    // for (int i: dp) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << dp[0] << "\n";
    return 0;
}