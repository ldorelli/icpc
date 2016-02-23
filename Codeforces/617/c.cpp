#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 2001;
int px[2], py[2];
int vx[N], vy[N];
int n;

// i : centro, j : ponto
ll dist (int i, int j) {
    return (vx[i]-px[j])*(vx[i]-px[j])  + (vy[i]-py[j])*(vy[i]-py[j]);
}

ll f (ll r, int k) {
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (dist(i, k) > r) {
            res = max (res, dist (i, !k));
        }
    }
    return res + r;
}

ll solve (int k) {
    ll lo = 0;
    ll hi = 1000000000000000000;

    while (lo != hi) {
        ll mi = (hi + lo)/2;
        if ( f(mi, k) - f(mi + 1, k) > 0 ) lo = mi + 1;
        else hi = mi;
    }
    return f (lo, k);
}

int main (void) {
    
    cin >> n >> px[0] >> py[0] >> px[1] >> py[1];
    
    for (int i = 0; i < n; ++i) {
        cin >> vx[i] >> vy[i];
    }

    ll ans = solve (0);
    ans = min ( ans, solve (1) );

    cout << ans << endl;

    return 0;
}
