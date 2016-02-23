#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long int ll;

using namespace std;

const int N = 200100;

int bit[N];
int M, n;

int add (int x, int v = 1) {
    while (x < N) {
        bit[x] += v;
        x += (x & -x);
    }
}

int query (int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= (x & -x);
    }
    return ans;
}

typedef pair <int, int> pii;

struct Event {
    int x, t, a, b;

    Event () {}
    Event (int _x, int _t, int _a = 1, int _b = 1) : x(_x), t(_t), a(_a), b(_b) {}

    bool operator < (const Event& b) const {
        if (x != b.x) return x < b.x;
        return t < b.t;
    }
};

map <int, vector <pii>> hor, ver;
vector <Event> v;

void sweep (map <int, vector<pii> >& m, int t, ll &tot) {

    for (auto& it : m) {
     
        int y = it.fi;
        auto& H = it.se;
        
        sort ( H.begin(), H.end());
        
        int b = H[0].fi;
        int e = H[0].se;

        for (int i = 1; i < H.size(); ++i) {
        
            if (H[i].se < e) continue;
            
            if (H[i].fi > e) {
                tot += e - b + 1;

                if (t == 0) {
                    v.push_back ( Event( b, 0, y ) );
                    v.push_back ( Event( e, 2, y ) );
                } else {
                    v.push_back ( Event( y, 1, b, e) );
                }
                b = H[i].fi;
                e = H[i].se;
            } else {
                // Extende o end
                e = H[i].se;
            }
        }

        tot += e - b + 1;
        if (t == 0) {
            v.push_back ( Event( b, 0, y ) );
            v.push_back ( Event( e, 2, y ) );
        } else {
            v.push_back ( Event( y, 1, b, e) );
        }
    }
}

// comprime só os Y's 
void compress (vector<Event>& v) {
    vector <int> cm;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].t == 1) {
            cm.push_back (v[i].a);
            cm.push_back (v[i].b);
        } else cm.push_back (v[i].a);
    }
    sort (cm.begin(), cm.end());
    
    auto p = unique (cm.begin(), cm.end());
    for (int i = 0; i < v.size(); ++i) {
        v[i].a = lower_bound(cm.begin(), p, v[i].a) - cm.begin() + 2;
        if (v[i].t == 1) {
            v[i].b = lower_bound(cm.begin(), p, v[i].b) - cm.begin() + 2;
        } 
    }
}

int main (void) {
    
    memset (bit, 0, sizeof bit);

    scanf ("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf ("%d %d %d %d", &a, &b, &c, &d);
        if (a == c) {
            ver[a].push_back(  make_pair( min(b, d), max(b, d) ) );
        }  else {
            hor[b].push_back( make_pair( min(a, c), max(a, c) ) );
        }
    }

    ll ans = 0;  
    sweep (ver, 1, ans);
    sweep (hor, 0, ans);

    compress (v);
    // Find intersections
    sort (v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        int Y = v[i].a;
        if (v[i].t == 0) {
            add (v[i].a, 1);
        } else if (v[i].t == 2) {
            add (v[i].a, -1);
        } else {
            ans -= (ll) query(v[i].b) - query(v[i].a - 1);
        }
    }

    cout << ans << endl;

    return 0;
}
