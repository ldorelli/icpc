#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 400001;

ll seg[8*N];
ll lazy[8*N];
vector <int> g[N];
int col[4*N];
int L[8*N], R[8*N];
int k;

void dfs (int x) {
    L[x] = k++;
    for (int i = 0; i < g[x].size(); ++i) {
        if (L[g[x][i]] == -1) {
            dfs (g[x][i]);
        }
    }
    R[x] = k++;
}

void prop (int x, int l, int r) {
    if (lazy[x]) {
        seg[x] = lazy[x];
        if (l != r) {
            lazy[2*x] = lazy[x];
            lazy[2*x+1] = lazy[x];
        }
        lazy[x] = 0LL;
    }
}

ll query (int x, int l, int r, int a, int b, ll v) {

    prop (x, l, r);
    
    if (l > b or r < a)  return 0LL;
    if (l >= a and r <= b) {
        if (v) {
            lazy[x] = v;
            prop (x, l, r);
        }
        return seg[x];
    }
    
    ll A = query (2*x, l, (l+r)/2, a, b, v);
    ll B = query (2*x+1, (l+r)/2+1, r, a, b, v);
    seg[x] = seg[2*x+1] | seg[2*x];
    return A | B;            
}

int main (void) {

    ios::sync_with_stdio (false);
    int n, m;
    scanf ("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf ( "%d", &col[i]);
    }

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf ("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset (L, -1, sizeof L);
    k = 0;
    dfs (1);
    k--;

    for (int i = 1; i <= n; ++i) {
        query (1, 0, k, L[i], L[i], (1LL<<col[i]));
        query (1, 0, k, R[i], R[i], (1LL<<col[i]));
    }


    for (int i = 0; i < m; ++i) {
        int q;
        scanf ("%d", &q);

        if (q == 1) {
            int v, c;
            scanf ("%d %d", &v, &c);
            query (1, 0, k, L[v], R[v], (1LL<<c));
        } else {
            int v;
            scanf ("%d", &v);
            cout << __builtin_popcountll(query (1, 0, k, L[v], R[v], 0LL)) << endl;
        }
    }

    return 0;
}
