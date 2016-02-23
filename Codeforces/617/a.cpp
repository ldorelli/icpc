#include <bits/stdc++.h>

using namespace std;

int v[5] = { 1, 2, 3, 4, 5 };

const int N = 10000010;
int ans[N];

int main (void) {
    int x;
    cin >> x;
    
    ans[0] = 0;
    for (int i = 1; i <= x; ++i) {
        ans[i] = ans[i-1] + 1;
        for (int k = 2; k <= 5; ++k) {
            if (i - k >= 0) ans[i] = min(ans[i], ans[i-k] + 1);
        }
    }
    cout << ans[x] << endl;

    return 0;
}
