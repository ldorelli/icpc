#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

int solve (ll x) {
    if (x == 0) return 0;
    if (x == 1) return 0;
    
    int p;
    for (p = 63; p >= 0; --p) {
        if ((x>>p)&1) break;
    }
    
    int zer = 0;
    ll ans = 0;
    for (int i = 0; i < p; ++i) {
        ans += i;
        if (((x>>i)&1) == 0) zer++;
    }

    if (zer == 0) ans += p;
    else {
        int k;
        for (k  = p; ((x>>k)&1) != 0; --k);
        ans += p-k-1;
        if (zer == 1) ans++;
    }
    return ans;
}

int main (void) {
    ll a, b;
    cin >> a >> b;
    ll res = solve (b) - solve (a - 1);
    cout << res << endl;
    return 0;
}
