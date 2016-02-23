#include <bits/stdc++.h>

using namespace std;

const int N = 5020;
typedef long long int ll;

ll mo = (ll) 1e9+7;

int lcs[N][N];
ll dp[N][N];
ll cum[N][N];
string s;
int n;

bool cmp (int i, int j) {

    if (lcs[i][j] >= j-i) {
        return false;
    }
    int pos = lcs[i][j];
    return s[j+pos] > s[i+pos];
}

int main (void) {

    cin >> n >> s;

    // Precalc LCS
    for (int i = n; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (i == n or j == n) {
                lcs[i][j] = 0;
            } else if (s[i] == s[j]) {
                lcs[i][j] = lcs[i+1][j+1] + 1;
            } else {
                lcs[i][j] = 0;
            }
        }
    }

    ll res = 0;
    for (int i = n; i >= 0; --i) {
        for (int l = i-1; l >= 0; --l) {
            if (i == n) {
                dp[i][l] = 1LL;
                cum[i][l] = 1LL;
            } else if (s[i] == '0' or s[l] == '0') {
                cum[i][l] = cum[i+1][l];
                dp[i][l] = 0LL;
            } else {
                int len = i-l;
                if (i+len-1 < n) {
                    if (cmp (l, i)) {
                        dp[i][l] = (dp[i][l] + dp[i+len][i])%mo;
                    }
                    if (i + len - 1 != n-1) {
                        dp[i][l] = (dp[i][l] + cum[i+len+1][i])%mo;
                    }
                }
                cum[i][l] = (cum[i+1][l] + dp[i][l])%mo;    
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        res = (res + dp[i][0])%mo;
    }

    cout << res << endl;
}   
