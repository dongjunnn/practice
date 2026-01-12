// https://cses.fi/problemset/task/1653

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> weights;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }

    vector<int> ride_num(1<<n, 1e9);
    vector<int> space_used(1<<n, 0);
    ride_num[0] = 1; 
    space_used[0] = 0; 

    for (int i=0; i<1<<n; i++) {
        for (int j=0; j<n; j++) {
            if (1<<j&i) {
                int prev_mask = i ^ (1 << j);
                int prev_rides = ride_num[prev_mask];
                int prev_space = space_used[prev_mask];

                int current_rides;
                int current_space;

                if (prev_space + weights[j] <= x) {
                    current_rides = prev_rides;
                    current_space = prev_space + weights[j];
                } else {
                    current_rides = prev_rides + 1;
                    current_space = weights[j];
                }

    
                if (current_rides < ride_num[i]) {
                    ride_num[i] = current_rides;
                    space_used[i] = current_space;
                } else if (current_rides == ride_num[i]) {
                    if (current_space < space_used[i]) {
                        space_used[i] = current_space;
                    }
                }
            }
        }
    }

    cout << ride_num[(1 << n) - 1] << endl;

    return 0;
}