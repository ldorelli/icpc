#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main (void) {
    int n;
    cin >> n;
    map <int, int> m;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x; m[x]++;
    }
    int ans = 0;
    int tot = 0;
    for (auto& x : m) {
        int t = tot + x.second - 1;
        if (t >= x.first) {
            ans = tot + x.second;
        }
        tot += x.second;
    }
    cout << ans << endl;
}

