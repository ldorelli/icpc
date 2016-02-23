#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
vector <int> g[N], e[N];
int vis[N];
int vis_node[N];
bool did;
vector <int> res;

int dfs (int x) {
    vis_node[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        int id = e[x][i];
        if (vis[id]) continue;
        did = true;
        vis[id] = 1;
        if (res.size() == 0) res.push_back(x);
        else if (res.back() != x) res.push_back(x);
        if (res.back() != y) res.push_back(y);
        dfs (y);
    }
    
}

int main (void) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        e[a].push_back(i);
        e[b].push_back(i);
    }

    for (int k = 1; k <= sqrt(n); k += 2) {
        for (int i = 0; i < n; ++i) {
            if (!vis_node[i] and g[i].size() == k) {
                dfs (i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis_node[i]) {
             dfs (i);
        }
    }
    
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
}
