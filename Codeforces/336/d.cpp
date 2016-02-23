#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;

const int N = 501;
int v[N];

int dp[N][N];

int main (void) {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int i = 0; i+1 < n; ++i)
        dp[i][i+1] = (v[i] == v[i+1]) ? 1 : 2;

    for (int s = 3; s <= n; ++s) {
        for (int i = 0; i+s-1 < n; ++i) {
            int j = i+s-1;
            int ans = 1 + dp[i+1][j];
            int ii = i;
            int jj = j;
            for ( ; ii+1 < jj; ++ii, --jj) {
                if (v[ii] != v[jj]) break;
                if (ii != jj) ans = min(ans,  dp[ii+1][jj-1]);
            }
            if (ii == jj) ans = 1;
            ii = i;
            for (ii = i; ii+1 <= j; ++ii) ans = min(ans, dp[i][ii] + dp[ii+1][j]);
            dp[i][j] = ans;
        }
    }

    cout << dp[0][n-1] << endl;
    return 0;
}
