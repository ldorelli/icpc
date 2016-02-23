#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n, s;
    cin >> n >> s;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        if (a < s) {
            int change = 100 - b;
            if (change == 100) change = 0;
            if (ans == -1) ans = change;
            else ans = max(ans, change);
        } else if (a == s and b == 0) {
            ans = max(0, ans);
        }
    }

    cout << ans << endl;
}
