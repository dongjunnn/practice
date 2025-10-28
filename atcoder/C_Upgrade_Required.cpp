// https://atcoder.jp/contests/abc426/tasks/abc426_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;

    int oldest = 1;
    vector<int> pc_os(n+1, 1);
    for (int i=0; i<q; i++) {
        int x,y;
        cin >> x >> y;
        int running_sum = 0;
        for (int j=oldest; j<=x; j++) {
            pc_os[y] += pc_os[j];
            running_sum += pc_os[j];
            pc_os[j] = 0;
        }
        // oldest = max(x, oldest)+1;
        if (x+1>oldest) {
            oldest = x+1;
        }
        cout << running_sum << "\n";
    }

    return 0;
}