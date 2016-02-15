#include <bits/stdc++.h>

using namespace std;

const int N = 40;

typedef long long int ll;

ll dp[N][2];
int n, K;

ll solve (int i, int z) {

	if (i == n) return dp[i][z] = 1LL;
	
	ll& res = dp[i][z];
	if (res != -1) return res;
	
	res = 0;
	
	for (int k = 0; k < K; ++k) {
		if (k == 0) { 
			if (z == 1 or i == 0) continue;
			res += solve (i + 1, 1); 
		} else {
			res += solve (i + 1, 0);
		}
	}
	return res;
}


int main (void) {
	cin >> n >> K;
	memset (dp, -1, sizeof dp);
	cout << solve (0, 0) << endl;
}	
