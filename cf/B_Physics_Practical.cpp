// https://codeforces.com/problemset/problem/253/B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    vector<ll> measures;
    for (ll i=0;i<n;++i) {
        ll j;
        cin>>j;
        measures.push_back(j);
    }
    sort(measures.begin(), measures.end());
    ll l=0;
    ll res=measures.size();
    for (ll r=0; r<measures.size(); r++) {
        while (measures[l]*2<measures[r]) {
            l++;
        }
        // cout << l << " " << r << " " << measures[l] << " " << measures[r] << "\n";
        res = min(res, n-(r-l+1));
    }
    cout << res;
    return 0;
}