#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long int ll;

using namespace std;

ll get (ll x) {
    ll res = 2*x*x*x +  3 *x*x - 26*x + 24;
    return res/24;
}

int main (void) {
    ll x;
    cin >> x;

    if (x%2 == 1) {
        cout << 0 << endl;
    } else {
        if (x%4 == 0) {
            cout << x/4 - 1 << endl;
        } else cout << x/4 << endl;
    }

    return 0;
}
