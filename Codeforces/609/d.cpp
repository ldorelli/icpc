#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int N = 200001;

ll p[3][N];
int id[3][N];
ll c[3][N];
int cnt[3];
int n, m, k;
ll s;

vector < pair<int, int> > ans;

struct Buyo {
    ll cost;
    int id, day;

    Buyo (){}
    Buyo (ll _cost, int _id, int _day) : cost(_cost), id(_id), day(_day) {}
    bool operator < (const Buyo& b) const {
        return cost > b.cost;
    }
};


bool good (int day) {
    ll best[3] = { inf, inf, inf }; 
    int bd[3];
    
    for (int i = 0; i <= day; ++i) 
        for (int d = 1; d <= 2; ++d) {
            if (c[d][i] < best[d]) {
                best[d] = c[d][i];
                bd[d] = i+1;
            } 
        }

    priority_queue <Buyo> q;
    for (int d = 1; d <= 2; ++d) {
        for (int i = 0; i < cnt[d]; ++i) {
            q.push( Buyo(p[d][i] * best[d], id[d][i], bd[d]));
        }
    }
    
    int tot = 0;
    ll X = s;
    while (!q.empty()) {
        Buyo next = q.top(); q.pop();
        //cout <<  "DAY " << day+1 << " Cost: " << next.cost << " " << tot << "/" << k << endl;
        // ve se da pra comprar
        if (X - next.cost >= 0) {
            X -= next.cost;
            ans.push_back( make_pair(next.id, next.day) );
            tot++;
            if (tot == k) return true;
        } else {
            break;
        }
    }
    return false;
}



int main (void) {
    
    ios::sync_with_stdio(false);

    cin >> n >> m >> k >> s;
    
    for (int i = 0; i < n; ++i) {
        cin >> c[1][i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> c[2][i];
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        id[a][cnt[a]] = i+1;
        p[a][cnt[a]++] = b;
    }

    int lo = 0, hi = n-1;
    if (!good(n-1)) {
        cout << -1 << endl;
        return 0;
    }
 
    while (lo != hi) {
        int mi = (lo + hi)/2;
        ans.clear();
        if (good(mi)) hi = mi;
        else lo = mi + 1;
    }
    ans.clear();
    good(lo);
 //   assert(ans.size() == k);
    cout << lo+1 << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

