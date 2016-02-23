#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int v[N];

int main (void) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 0; i < n; ++i) cin >> v[i], tot += v[i];
    sort (v, v + n);
    int med = tot/n;
    int rest = tot%n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = v[i];
        if (i >= n-rest) --x;
        ans += abs(x - med);
    }
    cout << ans/2 << endl;
}
