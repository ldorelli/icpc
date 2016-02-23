#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll cnt[11];
ll MOD = 1e9+7;;


struct Matrix {
    int n, m;
    ll coef[200][200];

    Matrix (int n, int m) {
        this->n = n;
        this->m = m;
        memset (coef, 0, sizeof coef);
    }

    Matrix (int n, int m, ll val) : n(n), m(m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                coef[i][j] = val;
    }

    static Matrix identity (int n) {
        Matrix res (n, n);
        for (int i = 0; i < n; ++i) {
            res.coef[i][i] = 1LL;
        }
    }

    Matrix operator* (const Matrix& b) const {
        Matrix res (n, b.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    res.coef[i][j] = ( res.coef[i][j] +  (coef[i][k] * b.coef[k][j])%MOD)%MOD;
                }
            }
        }
        return res;
    }

    Matrix operator^ (int p) const {
        if (p == 0) return Matrix::identity (n);
        if (p == 1) return *this;
        Matrix r = (*this)^(p/2);
        r = r * r;
        if (p%2) r = r * (*this);
        return r;
    }
};

int main (void) {

    ios::sync_with_stdio (false);

    int n;
    ll b, k, x;
    cin >> n >> b >> k >> x;

    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        cnt[v]++;
    }

    Matrix M (x, x);
    for (int d = 0; d <= 9; ++d) {
        for (int i = 0; i < x; ++i) {
            int v = (d + 10*i)%x;
            M.coef[v][i] = (M.coef[v][i] + cnt[d])%MOD;
        }
    }

    Matrix f0 (x, 1);
    f0.coef[0][0] = 1;

    Matrix res = (M^b);
    cout << res.coef [k][0];

    return 0;
}

