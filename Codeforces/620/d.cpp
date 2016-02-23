#include <bits/stdc++.h>

using namespace std;


const int N = 2001;

int A[N], B[N];

typedef long long int ll;

struct P {
    int i, j;
    ll s;

    P (int i, int j, ll s) : i(i), j(j), s(s) {}

    bool operator < (const P& b) const {
        if (s != b.s) return s < b.s;
        if (i != b.i) return i < b.i;
        return j < b.j;
    }   
};


pair<ll, pair<P, P> > solve (int *A, int *B, int n, int m) {

    ll sa = 0;
    ll sb = 0;

    vector <P> aa;
    for (int i = 0; i < n; ++i) {
        sa += A[i];
        for (int j = i + 1; j < n; ++j) {
            aa.push_back ( P (i, j, A[i] + A[j]) );
        }
    }   

    vector <P> bb;
    for (int i = 0; i < m; ++i) {
        sb += B[i];
        for (int j = i + 1; j < m; ++j) {
            bb.push_back( P(i, j, B[i] + B[j]) );
        }       
    }

    pair <ll, pair<P, P> > ans = make_pair ( 100000000000000LL, make_pair (-1, -1) );
    for (int i = 0; i < aa.size(); ++i) {
        int lo = 0;
        int hi = bb.size()-2;
        while (lo != hi) {
            int mi = (hi + lo)/2;
            ll l = abs(  (sa - aa[mi].s + bb[mi].s) - (sb - bb[mi].s + aa[mi].s) );
            ll r = abs(  (sa - aa[mi+1].s + bb[mi+1].s) - (sb - bb[mi+1].s + aa[mi+1].s) );
            if (l > r) hi = mi;
            else lo = mi + 1;
        }
        ll l = abs(  (sa - aa[lo].s + bb[lo].s) - (sb - bb[lo].s + aa[lo].s) );
        pair <ll, pair<P, P> > cans = make_pair ( l, make_pair (aa[i], bb[lo]) );
        if (cans < ans) ans = cans;
    }
    return ans;
}

int main (void) {

    int n, m;

    cin >> n;
    ll sa, sb;
    sa = sb = 0;
    for (int i = 0; i < n; ++i) cin >> A[i], sa += A[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> B[i], sb += B[i];

    
    if (sb > sa) {
        solve (A, B, n, m);
    } else {
        solve (B, A, m, n);
    }


    return 0;
}
