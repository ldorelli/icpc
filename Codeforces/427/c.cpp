#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

const int N = 200010;

typedef long long int ll;
const ll inf = (ll)1e15;

vector <int> g[N];
int num, n, m;
int dfsnum[N];
int dfslow[N];
int napilha[N], pilha[N], ps;
int cost[N];
int c_scc;
ll scc_count[N], scc_val[N];


void tarjan (int p, int l) {

    dfsnum[p] = dfslow[p] = num++;
    pilha[ps++] = p;
    napilha[p] = 1;

    for (int i = 0; i < g[p].size(); ++i) {
        int v = g[p][i];
        // if (v == l) continue;
        if (dfsnum[v] == 0) {
            tarjan (v, p);
        }
        if (napilha[v]) 
            dfslow[p] = min(dfslow[p], dfslow[v]);
    }   

    if (dfsnum[p] == dfslow[p]) {
        // cout << "Sou o " << p << endl;
        scc_val[c_scc] = inf;
        while (1) {
            int v = pilha[ps-1];
            --ps;
            if (scc_val[c_scc] > cost[v]) {
                scc_val[c_scc] = cost[v];
                scc_count[c_scc] = 0;
            } 
            if (scc_val[c_scc] == cost[v]) scc_count[c_scc]++;
            napilha[v] = 0;
            if (v == p) break;
        }
        c_scc++;
    }

}

vector <int> adj[N];

typedef long long int ll;

int main (void) {
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> cost[i];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
    }

    memset(dfsnum, 0, sizeof dfsnum);
    ps = 0; 
    num = 1;

    num = 1;
    for (int i = 0; i < n; ++i) {
        if (dfsnum[i] == 0) {
            tarjan (i, -1);
        }
    }

    ll ways = 1LL;
    ll mi = 0;
    ll mo = 1000000000+7;
    for (int i = 0; i < c_scc; ++i) {
        ways = (ways * (scc_count[i]) ) % mo;
        mi += scc_val[i];
    }

    // cout << c_scc << endl;
    cout << mi << " " << ways << endl;

    return 0;
}
