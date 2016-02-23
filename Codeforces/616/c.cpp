#include <bits/stdc++.h>

using namespace std;

const int  N = 1010;
const int  M = N*N;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int compsz[M];
int cmp[N][N];
char v[N][N];
int n, m;

void dfs (int i, int j, int cc) {
    cmp[i][j] = cc;
    compsz[cc]++;

    for (int d = 0; d < 4; ++d) {
        int ii = i + dir[d][0];
        int jj = j + dir[d][1];
        
        if (ii >= 0 and ii < n and jj >= 0 and jj < m and v[ii][jj] == '.') {
            if (cmp[ii][jj] == -1) 
                dfs (ii, jj, cc);
        }
    }
}

int main (void) {
    scanf ("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf ("%s", v[i]);
    }

    memset (cmp, -1, sizeof cmp);


    int cc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cmp[i][j] == -1 and v[i][j] == '.') {
                dfs (i, j, cc);
                cc++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '*') {
                set <int> join;
                for (int d = 0; d < 4; ++d) {
                    int ii = i + dir[d][0];
                    int jj = j + dir[d][1];
                    if (ii >= 0 and ii < n and jj >= 0 and jj < m and v[ii][jj] == '.') {
                        join.insert ( cmp[ii][jj] );
                    }
                }
                int ans = 0;
                for (auto &x  : join) {
                    ans += compsz[x];
                }
                printf ("%d", (ans + 1)%10);
            } else {
                printf (".");
            }
        }
        printf ("\n");
    }
}
