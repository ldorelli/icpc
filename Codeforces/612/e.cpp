#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int p[N], vis[N];
vector< vector<int> > P[N];

int main (void) {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &p[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        
        vector <int> cycle;
        int x = i;
        do {
            cycle.push_back(x);
            vis[x] = true;
            x = p[x];
        } while (!vis[x]);
        P[cycle.size()].push_back(cycle);
    }

    for (int i = 0; i < P[1].size(); ++i) {
        for (int j = 0; j < P[1][i].size(); ++j) { 
            p[P[1][i][j]] = P[1][i][j];
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (P[i].size()%2 == 1 and i%2 == 0) {
            printf ("-1\n");
            return 0;
        }
    }   

    for (int t = 2; t <= n; ++t) {
        if (t%2 == 0) {
            for (int i = 0; i < P[t].size(); i += 2) {
                for (int j = 0; j < t; ++j) {
                    p[P[t][i][j]] = P[t][i+1][j];
                    p[P[t][i+1][j]] = P[t][i][(j+1)%t];
                }
            }
        } else {
            for (int i = 0; i < P[t].size(); ++i) {
                int m = t/2;
                for (int j = 0; j < m; ++j) {
                    p[P[t][i][j]] = P[t][i][m+1+j];
                    p[P[t][i][m+1+j]] = P[t][i][j+1];
                }
                p[P[t][i][m]] = P[t][i][0];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf ("%d ", p[i]);
    }
    printf ("\n");
}
