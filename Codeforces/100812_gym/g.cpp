#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 100010;
int ste[N];
vector <int> g[N];
vector<int> w[N];
ll dis[N];
vector<int> prd[N];
int n, m;

struct State {
    ll w;
    int v, from;

    State (){}
    State (ll w, int v, int from) : w(w), v(v), from(from) {}

    bool operator < (const State& b) const {
        return w > b.w;
    }
};

void pre () {
    priority_queue <State> q;
    memset (dis, -1, sizeof dis);
    
    for (int i = 0; i < n; ++i) {
        if (ste[i]) {
            dis[i] = 0;
            q.push(State(0, i, i));
        }
    }

    while (!q.empty()) {
        State next = q.top(); q.pop();
        int x = next.v;
        if (dis[x] < next.w) continue;
        for (int i = 0; i < g[x].size(); ++i) {
            ll ww = w[x][i];
            int y = g[x][i];
            if (dis[y] == -1 or dis[y] >= dis[x] + ww) {
                if (dis[y] > dis[x] + ww) {
                    prd[y].clear();
                }
                dis[y] = dis[x] + ww;
                if (prd[y].size() <= 1) {
                    prd[y].push_back(next.from);
                    q.push( State(dis[x] + ww, y, next.from));
                }
            }
        }
    }
}

int main (void) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> ste[i];
    for (int i = 0; i < m; ++i) {
        int a, b, ww;
        cin >> a >> b >> ww;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(ww);
        w[b].push_back(ww);
    }

    pre ();
    int pa, pb;
    ll res = -1;
    for (int i = 0; i < n; ++i) {
        if (ste[i]) {
            // Caso em que a resposta é uma aresta entre dois 1
            for (int j = 0; j < g[i].size(); ++j) {
                int k = g[i][j];
                if (ste[k]) {
                    if (res == -1 or w[i][j] < res) res = w[i][j], pa = i, pb = k;
                }
            } 
        } else {
            for (int j = 0; j < g[i].size(); ++j) {
                int k = g[i][j];
                for (auto x : prd[i]) {
                    if (ste[k]) {
                        if (k == x) continue;
                        else {
                            if (w[i][j] + dis[i] < res or res == -1) {
                                res = w[i][j] + dis[i];
                                pa = x;
                                pb = k;
                            }
                        }
                    } else {
                        for (auto y : prd[k]) {
                            if (x != y) {
                                if (w[i][j] + dis[k] + dis[i] < res or res == -1) {
                                    res = w[i][j] + dis[k] + dis[i];
                                    pa = x;
                                    pb = y;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (res == -1) cout << "No luck at all\n";
    else {
        cout << res << endl;
        cout << (pa+1) << " " << (pb+1) << endl;
    }
    
    return 0;
}
