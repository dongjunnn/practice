// https://codeforces.com/problemset/problem/2160/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;

        if (n == 0) {
            cout << "YES\n";
            continue;
        }

        while (n > 0 && (n % 2 == 0)) {
            n >>= 1; 
        }

        string binary_n;
        while (n > 0) {
            binary_n.push_back((n & 1) + '0'); 
            n >>= 1;
        }
       
        string binary_n_reversed = binary_n;
        reverse(binary_n_reversed.begin(), binary_n_reversed.end());

        if (binary_n != binary_n_reversed) {
            cout << "NO\n";
            continue;
        }

        int len = binary_n_reversed.length();
        if (len % 2 != 0 && binary_n_reversed[len / 2] == '1') {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}