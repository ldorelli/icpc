#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        ans = max(ans, x);
    }

    cout << ans << endl;
}
