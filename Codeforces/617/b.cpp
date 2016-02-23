#include <bits/stdc++.h>

using namespace std;

const int N = 110;

typedef long long int ll;

ll dp[N];
int v[N];
int n;

ll solve (int x) {
    if (x == n) return 1;
    ll &res = dp[x];
    if (res != -1) return res;
    res = 0;
    int su = 0;
    for (int i = x; i < n; ++i) {
        if (v[i] == 1) su++;
        if (su == 1) {
            res += solve (i + 1);
        }
        if (su == 2) {
            break;
        }
    }
    return res;
}


int main (void) {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    memset (dp, -1, sizeof dp);

    cout << solve (0) << endl;

    return 0;
}
