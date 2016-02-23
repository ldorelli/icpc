#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
int v[N];
int prox[N];
int n;
int dp[N][2];
int best[N][2];
const int inf = 0x3f3f3f3f;

int solve (int p, int b) {

    if (p == n) {
        return b ? 0 : -inf;
    }
    int &res = dp[p][b];

    if (res != -1) return res;

    res = -inf;
    // Tenta manter o atual
    res = solve (p + 1, b);
    if (prox[p] != -1) {
        res = max(res, 1 + solve (prox[p] + 1, 1));
    }
    return res;
}

int main (void) {
    
    cin >> n;
    
    map <int, int> last;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = n-1; i >= 0; --i) {
        if (last.count(v[i]) != 0) {
            prox[i] = last[v[i]];
        } else {
            prox[i] = -1;
        }
        last[v[i]] = i;
    }   

    bool good = false;
    for (int i = 0; i < n; ++i) {
        if (prox[i] != -1) {
            good = true;
        }
    }

    if (!good) {
        cout << -1 << endl;
        return 0;
    }

    memset (dp, -1, sizeof dp);

    cout << solve(0, 0) << endl;
    int b, e;
    b = e = 0;

    for (int i = 0; i < n; ) {
        if (i == n-1) {
            cout << b+1 << " " << n << endl;
            ++i;
        } else {
            if (prox[i] != -1 and dp[i][0] == dp[prox[i]+1][0]+1) {
                cout << b+1 << " " << prox[i]+1 << endl;
                b = prox[i]+1;
                i = prox[i]+1;
            } else ++i;
        }
    }   
}
