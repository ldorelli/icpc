#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 100001;
ll v[N];

int main (void) {

    int n;
    ll A, cf, cm, m;

    cin >> n >> A >> cf >> cm >> m;


    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort (v, v + n);

    int lo = 0; 
    int hi = n-2;

    while (lo != hi) {
        int mi = (hi + lo)/2;

        ll r = calc (mi+1) - calc (mi);
        if (r > 0) lo = mi + 1;
        else hi = mi;
    }

    cout << calc (lo) << endl;

    return 0;
}
