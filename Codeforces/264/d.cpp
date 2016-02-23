#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int K = 6;

int pos[N][5];
int dp[N][N];
int v[N][K];
int n, k;

int solve (int p, int l) {
    
    if (p > n) return 0;
   
    int  &res = dp[p][l];
    if (res != -1) return res;
    
    res = solve (p + 1, l);

    bool good = true;

    for (int i = 0; i < k; ++i) {
        if (pos[v[p][0]][i] < pos[l][i]) {
            good = false;
        }
    }
    if (good) {
        res = max(res, solve(p + 1, v[p][0]) + 1);
    }
    return res;
}

int main (void) {
    
    ios::sync_with_stdio (false);
    
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> v[j][i];
            pos[v[j][i]][i] = j+1;
        }
    }

    memset ( dp, -1, sizeof dp );
    cout << solve (1, 0) << endl;
}
