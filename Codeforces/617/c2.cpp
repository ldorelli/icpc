#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 2001;
ll px[2], py[2];
ll vx[N], vy[N];
int n;

// i : centro, j : ponto
ll dist (int i, int j) {
    return (vx[i]-px[j])*(vx[i]-px[j])  +(vy[i]-py[j])*(vy[i]-py[j]);
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

int main (void) {
    
    cin >> n >> px[0] >> py[0] >> px[1] >> py[1];
    
    for (int i = 0; i < n; ++i) {
        cin >> vx[i] >> vy[i];
    }

    ll ans = f (0, 0);
    for (int i = 0; i < n; ++i) {
        ans = min (ans, f (dist(i, 0), 0));
    }
    cout << ans << endl;

    return 0;
}
