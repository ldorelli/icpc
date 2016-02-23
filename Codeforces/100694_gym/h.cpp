#include <bits/stdc++.h>

using namespace std;

int main (void) {
    ios::sync_with_stdio (false);

    int n, x;
    cin >> n;

    int r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        r = max(r, x);
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
    }

    int m;
    cin >> m;
    int ans = m * r;

    for (int i = 0; i < m; ++i) {
        cin >> x;
        ans += x;
    }

    cout << ans << endl;
}
