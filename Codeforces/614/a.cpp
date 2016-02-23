#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main (void) {
    ll L, R, K;
    cin >> L >> R >> K;

    ll x = 1;

    bool good = false;
    if (x >= L and x <= R) {
        cout << x << " ";
        good = true;
    }

    while (x <= R/K) {
        if (x >= (L+K-1)/K) {
            cout << x*K << " ";
            good = true;
        }
        x *= K;
    }
    if (!good) {
        cout << -1;
    }   
    cout << endl;
}
