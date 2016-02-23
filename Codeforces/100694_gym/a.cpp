#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 10010;
const int M = 1200;

ll dp[N][M][3];
ll w[N], p[N], d[N];
int n, m;

const ll inf = -100000000000000;

ll solve (int i, int k, int g) {

    if (i == n) {
        if (k-200 > m) {
            return inf;
        } else {
            return 0;
        }
    }
    
    ll &res = dp[i][k][g];

    if (res != -1) return res;
    //  N pega
    res = solve (i + 1, k, g);
    // Pega sem ativar
    if (w[i] + k < M) {
        res = max(res, p[i] + solve (i + 1, k + w[i], g));
    }
    // Pega ativando
    int W = w[i] - d[i] + k;
    if (g < 2 and W >= 0 and W < M) {
        res = max(res, p[i] + solve (i + 1, W, g + 1));
    }
    
    return res;
}


int main (void) {

    ios :: sync_with_stdio (false);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> w[i] >> d[i];
    }

    memset (dp, -1, sizeof dp);
    cout << solve(0, 200, 0) << endl;

    return 0;
}
