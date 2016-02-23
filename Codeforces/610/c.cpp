#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long int ll;

using namespace std;

const int N = 9;
int ans[1<<N][1<<N];

int solve (int n, int i, int j, int v) {
    if (n == 1) {
        ans[i][j] = v;
    } else if (n%2 == 0) {
        solve (n/2, i, j, v);
        solve (n/2, i + n/2, j, v);
        solve (n/2, i, j + n/2, v);
        solve (n/2, i + n/2, j + n/2, -v);
    }
}

int main (void) {
    int k; 
    cin >> k;
    
    solve (1<<k, 0, 0, 1);
    for (int i = 0; i < (1<<k); ++i) {
        for (int j = 0; j < (1<<k); ++j) 
            cout << (ans[i][j] == 1 ? '+' : '*');
        cout << endl;
    }

    return 0;
}
