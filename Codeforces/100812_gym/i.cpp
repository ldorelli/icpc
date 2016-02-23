#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

typedef long long int ll;
ll dp[N], t[N];
int n;
ll c, d;

ll solve (int x) {
    if (x == n) return 0LL;
    ll& res = dp[x];
    if (res != -1) return res;
    res = solve(x + 1) + d;
    ll tim_dec = 0;
    for (int i = x + 1; i < n; ++i) {
        tim_dec += (i-x) * (t[i] - t[i-1]);
        res = min(res, solve (i + 1) + tim_dec * c + d);
    }
    return res;
}

int main (void) {
    cin >> n >> d >> c;
    for (int i = 0; i < n; ++i) cin >> t[i];
    memset (dp, -1, sizeof dp);
    cout << solve(0) << endl;
}
