#include <bits/stdc++.h>

using namespace std;

const int N = 200001;
const int M = 101;
const int inf = 0x3f3f3f3f;

int dp[M][N];
int v[N];
int n, m;


int solve (int i, int s) {
    if (s >= m) return 0;
    if (i >= n) return inf;
    int &res = dp[i][s];
    if (res != -1) return res;
    return res = min(solve(i + 1, s), solve(i + 1, s + v[i]) + 1);
}


int main (void) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    memset (dp, -1, sizeof dp);
    cout << solve (0, 0)  << endl;
}
