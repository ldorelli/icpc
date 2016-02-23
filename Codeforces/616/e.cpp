#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll MO = 100000007;
ll n, m;

ll sum (ll x, ll y, ll k) {
    ll A = x%n;
    ll B = y%n;
}

int main (void) {

    cin >> n >> m;

    ll ans = 0;
    if (m > n) {
        ans = (m - n)%MO;
        m = n;
    }

    ll B = n;
    for (ll x = 2; ; ++x) {
        if (n/x <= 1) break;

        ll lo = x;
        ll hi = n;
        while (lo != hi) {
            ll mi = (hi + lo + 1)/2;
            if (n/mi == n/x) lo = mi;
            else hi = mi-1;
        }
        x = lo;
        ll A = x + 1;
 //       ans = (ans + solve (A, B, x)) %MO;
    }

    cout << ans << endl;
}
