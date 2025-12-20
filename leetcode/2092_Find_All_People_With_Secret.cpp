// https://leetcode.com/problems/find-all-people-with-secret/submissions/1860210632/?envType=daily-question&envId=2025-12-19

#define ll long long 
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> res;
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2]; 
        });
        DSU dsu = DSU(n);
        dsu.unite(0, firstPerson);
        int prev_t = -1;
        for (int i = 0; i < meetings.size(); ) {
            int currentTime = meetings[i][2];
            vector<int> time_group;
            int j = i;
            while (j < meetings.size() && meetings[j][2] == currentTime) {
                dsu.unite(meetings[j][0], meetings[j][1]);
                time_group.push_back(meetings[j][0]);
                time_group.push_back(meetings[j][1]);
                j++;
            }
            // reset connection            
            for (int p : time_group) {
                if (dsu.find(p) != dsu.find(0)) {
                    dsu.parent[p] = p; 
                    dsu.size[p] = 1; // Reset size
                }
            }
            
            i = j; 
        }
        for (int i=0; i<n; i++) {
            if (dsu.find(i)==dsu.find(0)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// Note: Union-Find with Reset
// sort all pairs by increasing time
// connect all pairs -> disconnect those pairs that do not lead to secret