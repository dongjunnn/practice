// https://codeforces.com/contest/893/problem/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

struct DSU {
    vector<ll> parent, size;

    DSU(ll n) {  
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0); 
    }

    ll find(ll x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; 
        if (size[a] < size[b]) swap(a, b); 
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }
};

const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;

    vector<ll> cost(n+1);
    vector<ll> best(n+1, INF);
    for (ll i = 0; i < n; i++) cin >> cost[i+1]; 
    DSU dsu(n+1);
    while (m--) {
        ll l, r;
        cin >> l >> r; 
        dsu.unite(l,r);
    }
    for (ll i=1; i<n+1; i++) {
        ll r = dsu.find(i);
        best[r] = min(best[r], cost[i]);
    }
    ll res = 0;
    for (ll i = 1; i < n+1; i++) {
        if (best[i] != INF) res += best[i];
    }
    cout << res;
    return 0;
}

