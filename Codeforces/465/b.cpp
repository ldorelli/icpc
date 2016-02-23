#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int v[N];
int nx[N];
int dp[N];
int n;

int solve (int pos) {

    if (pos == n) return 0;
    int &res = dp[pos];

    if (res != -1) return res;
    
    if (nx[pos] == -1) return res = 0;

    res = solve (pos + 1) + 1;
    res = min (res, solve (nx[pos]) + 2 );

    return res;
    
}

int main (void) {

    scanf ("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf ("%d", &v[i]);
    }

    int last = v[n-1] == 1 ? n-1 : -1;
    nx[n-1] = -1;
    for (int i = n-2; i >= 0; --i) {
        nx[i] = last;
        if (v[i] == 1) last = i;
    }

    memset ( dp, -1, sizeof dp );
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1) {
            ans = 1 + solve(i);
            break;
        }
    }
    printf ("%d\n", ans);
}
