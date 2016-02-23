#include <bits/stdc++.h>

using namespace std;

const int M = 12;
int n, m;
int cnt[M];

int main (void) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;    
        cnt[x]++;
    }
    int ans = 0;
    for (int f = 1; f <= m; ++f) {
        for (int s = f + 1; s <= m; ++s) {
            ans += cnt[f] * cnt[s];
        }
    }
    cout << ans << endl;
}
