#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int v[N][N];
int n, m;

int get_lin (int i) {
    int res = v[i][0];
    for (int j = 1; j < m; ++j) {
        if (v[i][j] < res) {
            res = v[i][j];
        }
    }
    return res;
}

int main (void) {
    ios::sync_with_stdio (false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }   

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max( ans, get_lin(i) );
    }

    cout << ans << endl;
}
