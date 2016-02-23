#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

typedef long long int ll;

ll B[N][N];
ll S[N][N];

int D [4][2] = { {1, 1}, {1, -1} , {-1, 1} , {-1, -1} };

void diag (int i, int j, int dir, int n) {
    ll ans = 0;
    int ii = i, jj = j;
    while (ii >= 0 and jj >= 0 and ii < n and jj < n) {
        ans += B[ii][jj];
        ii += D[dir][0];
        jj += D[dir][1];
    }
    ii = i, jj = j;
    while (ii >= 0 and jj >= 0 and ii < n and jj < n) {
        S[ii][jj] += ans;
        ii += D[dir][0];
        jj += D[dir][1];
    }
}


int main (void) {
    int n;
    ios :: sync_with_stdio (false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        diag (0, i, 0, n);
        diag (0, i, 1, n);
        if (i != 0) {
            diag (i, 0, 0, n);
            diag (i, n-1, 1, n);
        }
    }

    ll ans[2] = { -1LL,  -1LL };
    int pos[2][2];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int P = (i+j)%2;
            if (S[i][j]-B[i][j]  > ans[P]) {
                ans[P] = S[i][j] - B[i][j];
                pos[P][0] = i+1;
                pos[P][1] = j+1;
            }
        }
    }

    cout << (ans[0]+ans[1]) << endl;
    cout << pos[0][0] << " " << pos[0][1] << " " << pos[1][0] << " " << pos[1][1] << endl;
}
