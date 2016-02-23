#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 100001;
string in[N];
ll ans[N], res[N];
ll cnt[N];
int n, m, v;

void up (int x) {
    ans[1] += x;
    cnt[x]++;
    ++v;
}

int main (void) {
    cin >> n >> m;
    int k = max(n, m);

    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    // horizontais 
    v = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if (in[i][j] == '+') {
                if (cur != 0)  up(cur);
                cur = 0;
            } else ++cur;
        }
        if (cur != 0) up(cur);
    }
    res[1] = ans[1];
    for (int i = 2; i <= k; ++i) {
        ans[i] = ans[i-1] - v;
        v -= cnt[i-1];
        res[i] = ans[i];
    }

    v = 0;
    memset (ans, 0, sizeof ans);
    memset (cnt, 0, sizeof cnt);
    // Separado pls 
    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (in[j][i] == '+') {
                if (cur > 1) up(cur);
                cur = 0;
            } else ++cur;
        }
        if (cur != 0) up(cur);
    }
    for (int i = 2; i <= k; ++i) {
        ans[i] = ans[i-1] - v;
        v -= cnt[i-1];
        res [i] += ans[i];
    }
    
    for (int i = 1; i <= k; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}
