#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> point;
#define x first
#define y second

const int N = 100001;
point xf[N], yf[N];
int n;

point fixpoint (point c) {
    point r;
    if (c.x != 0) 
        r.x = c.x - 1000000000;
    if (c.y != 0) 
        r.y = c.y - 1000000000;
    return r;
}

ll dist (point a, point b) {
    a = fixpoint(a);
    b = fixpoint(b);
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

ll solve (point v[N]) {
    sort (v, v + n);
    ll res = dist ( point(v[0].x, 0) , point(v[n-1].x, 0) );
    int my = -1;
    for (int i = n-1; i > 0; --i) {
        if (my == -1) {
            my = i;
        } else if (fixpoint(v[i]).y > fixpoint(v[my]).y) {
            my = i;
        }
        ll K = dist ( point(0, v[my].y), point (v[i-1].x, 0) );
        res = min( res, K );
    }
    return res;
}

int main (void) {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> xf[i].x >> xf[i].y;
        xf[i].x += 1000000000;
        xf[i].y += 1000000000;
        yf[i].x = xf[i].y;
        yf[i].y = xf[i].x;
    }
    cout << min ( solve(xf), solve(yf) ) << endl;
    return 0;
}
