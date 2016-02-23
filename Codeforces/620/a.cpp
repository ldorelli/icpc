#include <bits/stdc++.h>

using namespace std;

int main (void) {
    long long int x, y;
    long long int gx, gy;
    cin >> x >> y;
    cin >> gx >> gy;

    long long ans = min ( abs (x - gx), abs (y - gy) );

    if (x < gx) x += ans;
    else x -= ans;

    if (y < gy) y += ans;
    else y -= ans;

    cout << ans + abs (gx - x) + abs ( gy - y) << endl;
}
