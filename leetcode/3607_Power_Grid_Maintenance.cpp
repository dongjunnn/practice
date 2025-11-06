#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);
const ll MOD = 1e9 + 7;

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


class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        cout << "test";
        vector<priority_queue<int, vector<int>, greater<int>>> min_list(c);
        for (int i=0; i<c; i++) {
            min_list[i].push(i+1);
        }
        cout << "test";
        vector<int> isAlive(c, true);
        for (vector<int>& connection: connections) {
            int n1 = connection[0];
            int n2 = connection[1];
            dsu.unite(n1-1, n2-1);
            // if (n1<n2) {
            //     min_list[n2-1].push(n1);
            // } else {
            //     min_list[n1-1].push(n2);
            // }
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> min_map(c);
        for (int i=1; i<=c; i++) {
            min_map[dsu.find(i-1)].push(i);
        }
        vector<int> res;
        for (vector<int>& query: queries) {
            int op = query[0];
            int n = query[1];
            if (op == 1 && isAlive[n-1]) {
                res.push_back(n);
            } else if (op==1) {
                while (!min_map[dsu.find(n-1)].empty() && !isAlive[min_map[dsu.find(n-1)].top()-1]) {
                    min_map[dsu.find(n-1)].pop();
                }
                if (min_map[dsu.find(n-1)].empty()) {
                    res.push_back(-1);
                } else {
                    res.push_back(min_map[dsu.find(n-1)].top());
                }
            } else {
                isAlive[n-1] = false;
            }
        }
        // for (bool i: isAlive) {
        //     cout << i << " ";
        // }
        return res;
    }
};