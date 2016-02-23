#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;;
const int N = 200010;
const int M = 21;

int uf[N];

vector <int> g[N], w[N];
int dis[N], lca[M][N];
ll ans[N];
ll lcw[M][N];

int find (int x) {
    if (uf[x] < 0) return x;
    return uf[x] = find(uf[x]);
}

struct Edge {
    int a, b;
    int w, id;
    Edge(){}
    Edge(int _a, int _b, int _w, int _id) : a(_a), b(_b), w(_w), id(_id) {}
    bool operator < (const Edge& b) const {
        return w < b.w;
    }
};

void dfs (int x, int p, int l) {
    lca[0][x] = p;
    dis[x] = l;
    for (int i = 0; i < g[x].size(); ++i) {
        int u = g[x][i];
        if (u != p) {
            lcw[0][u] = w[x][i];
            dfs (u, x, l + 1);
        }       
    }
}

void pre (int n) {
    for (int m = 1; m <= 20; ++m) {
        for (int i = 0; i < n; ++i) {
            lca[m][i] = lca[m-1][lca[m-1][i]];
            lcw[m][i] = max(lcw[m-1][i], lcw[m-1][lca[m-1][i]]);
        }
    }
}

ll query (int a, int b) {

    if (dis[a] > dis[b]) swap(a, b);
 
    ll ans = 0;
    int d = dis[b] - dis[a];
    
    for (int i = 0; i <= 20; ++i) {
        if ((d>>i)&1) {
            ans = max(ans, lcw[i][b]);
            b = lca[i][b];
        }
    }

    if (a == b) {
        return ans;
    }

    for (int i = 20; i >= 0; --i) {
        if (lca[i][a] != lca[i][b]) {
                ans = max(ans, max(lcw[i][a], lcw[i][b]));
                a = lca[i][a];
                b = lca[i][b];
        }
    }
    return max (ans, max(lcw[0][a], lcw[0][b]));
}


int main (void) {

    ios::sync_with_stdio(false);
    memset (uf, -1, sizeof uf);
    
    int n, m;
    cin >> n >> m;

    vector <Edge> v;
    for (int i = 0; i < m; ++i) {

        int a, b, w; 
        cin >> a >> b >> w;
        --a, --b;
        v.push_back ( Edge(a, b, w, i) );
    }
    
    sort (v.begin(), v.end());
    ll tot = 0;

    for (int i = 0; i < v.size(); ++i) {

        int a = v[i].a;
        int b = v[i].b;

        if (find(a) != find(b)) {
            
            g[a].push_back(b);
            g[b].push_back(a);
            w[a].push_back(v[i].w);
            w[b].push_back(v[i].w);
            
            tot += v[i].w;
            uf[find(a)] = find(b);
        } 
    }
    
    dfs (0, 0, 0);
    pre(n);

    for (int i = 0; i < v.size(); ++i) {
        ans[v[i].id] =  tot + v[i].w - query(v[i].a, v[i].b);
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
}
