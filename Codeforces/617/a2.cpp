#include <bits/stdc++.h>

using namespace std;

int v[5] = { 1, 2, 3, 4, 5 };

const int N = 10000010;
int ans[N];

int main (void) {
    int x;
    cin >> x;
    
    int ans = x/5;
    x = x%5;
    if (x != 0) ++ans;
    cout << ans << endl;

    return 0;
}
