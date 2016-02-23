#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long int ll;

using namespace std;

const int N = 200010;
ll v[N];


int main (void) {
    
    ios::sync_with_stdio (false);
    ll n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll mi = v[0], mp = 0;
    for (int i = 1; i < n; ++i) {
        mi = min (mi, v[i]);
    }

    for (int i = 0; i < n; ++i) {
        v[i] -= mi;
    }
    
    ll gd = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] != 0) ++gd;
        else break;
    }
    for (int j = n-1; j >= 0; --j) {
        if (v[j] != 0) ++gd;
        else break;
    }

    ll res =  gd * (mi + 1) + (n - gd) * mi;
    int lastx = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            if (lastx != -1) {
                ll A = i - lastx - 1;
                res = max (res, A * (mi +1) + (n - A) * mi);
            }
            lastx = i;
        }
    }
    cout << res << endl;
    
    return 0;
}
