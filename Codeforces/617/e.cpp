#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 100010;
int v[N];
ll  ac[N];
ll zeros[N];
ll  prefs[N];
ll pre[N];

int main (void) {
    int n, m, k;
    scanf ("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &v[i]);
    }

    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ac[i] = ac[i-1] xor v[i];
    }
    
    int z = 0;
    int p = 0;
    zeros[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (ac[i] == 0) z++;
        if (ac[i] == k) p++;
        zeros[i] = z + p;
        prefs[i] = p;
        pre[i] = pre[i-1] + z + p;
    }
    

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf ("%d %d", &a, &b);
        --a;
        --b;
        long long int ans = 0;
        if (a == 0) {
            ans = pre[b];
        } else {
            ans = pre[b];
            if (a - 2 >= 0) {
               ans -= zeros[a-2] * (prefs[b] - prefs[a]);
            }
        }
        cout << ans << endl;
    }

    
    return 0;
}
