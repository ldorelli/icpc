#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 5;
ll M;

struct Mat {
	int n, m;
	ll v[N][N];

	Mat (int n, int m) : n(n), m(m) {
		memset (v, 0, sizeof v);
	}

	Mat (int n, int m, ll r) : n(n), m(m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				v[i][j] = r;
			}
		}
	}

	Mat operator* (const Mat& b) const {
		Mat res (n, b.m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < b.m; ++j) {
				ll r = 0;
				for (int k = 0; k < m; ++k) {
					r = (r + (v[i][k] * b.v[k][j])%M)%M;
				}
				res.v[i][j] = r;
			}
		}	
		return res;
	}

	Mat operator^ (int x) {
		if (x == 0) return Mat(n, m, 1);
		if (x == 1) return (*this);
		Mat r = (*this)^(x/2);
		r = r * r;
		if (x%2 == 1) r = r * (*this);
		return r;
	}

	void print () const {
		cout << "===========\n";
		for (int i = 0; i < n; ++i, cout << endl)
			for (int j = 0; j < n; ++j)
				cout << v[i][j] << " ";
	}
};

int main (void) {
	ll n, k;

	cin >> n >> k >> M;
	
	Mat F (2, 2);
	F.v[0][0] = k-1;
	F.v[0][1] = k-1;
	F.v[1][0] = k-1;
	F.v[1][1] = 0;
	
	Mat S (2, 1);
	S.v[1][0] = (k-1)%M;
	S.v[0][0] = (k*(k-1))%M;


	if (n > 2) {
		Mat r = F^(n-2);
		Mat ans = r * S;
		cout << ans.v[0][0] << endl;
	} else {
		if (n == 0) cout << (k-1)%M << endl;
		else cout << ((k-1)*k)%M << endl;
	}

	return 0;
}
