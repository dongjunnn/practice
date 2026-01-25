// https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int bfs(vector<vector<int>>& adj, int start);
vector<int> bfs_dist(vector<vector<int>>& adj, int start);

vector<int> res;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    res = vector<int>(n, 0);
    int furthest_1 = bfs(adj, 1);
    int furthest_2 = bfs(adj, furthest_1);
    vector<int> dist_1 = bfs_dist(adj, furthest_1);
    vector<int> dist_2 = bfs_dist(adj, furthest_2);
    for (int i=0; i<n; i++) {
        cout << max(dist_1[i], dist_2[i]) << " ";
    }
    cout << "\n";
    return 0;

}

int bfs(vector<vector<int>>& adj, int start) {
    
    unordered_set<int> visited;
    visited.insert(start);
    queue<int> q;
    q.push(start);
    int curr;
    while (!q.empty()) {
        int length = q.size();
        for (int i=0; i<length; i++) {
            curr = q.front();
            q.pop();
            for (int i: adj[curr]) {
                if (visited.find(i)!=visited.end()) {
                    continue;
                }
                visited.insert(i);
                q.push(i);
            }
        }
    }
    return curr;
}

vector<int> bfs_dist(vector<vector<int>>& adj, int start) {
    vector<int> res_sub(adj.size()-1, 0);
    unordered_set<int> visited;
    visited.insert(start);

    queue<pair<int, int>> q;
    q.push({start, 0});
    int curr;
    while (!q.empty()) {
        int length = q.size();
        for (int i=0; i<length; i++) {
            auto [node, d] = q.front();
            q.pop();
            res_sub[node-1] = max(res_sub[node-1], d);
            for (int i: adj[node]) {
                if (visited.find(i)!=visited.end()) {
                    continue;
                }
                visited.insert(i);
                q.push({i, d+1});
            }
        }
    }
    return res_sub;
}

// Notes: bfs twice. First time to find one endpoint of the diameter, second time to find the other endpoint.
// Then do bfs from both endpoints to get the distances from either endpoint to every other nodes. 
// The max distance from either endpoint is the distance to the farthest node in the tree.