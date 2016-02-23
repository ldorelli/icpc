#include <bits/stdc++.h>

using namespace std;

int cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int howm (int x) {
    int ans = 0;
    while (x > 0) {
        ans += cnt[x%10];
        x /= 10;
    }
    return ans;
}

int main (void) {
    
    int a, b;
 
    cin >> a >> b;
    int res = 0;
    for (int x = a; x <= b; ++x) {
        res += howm (x);
    }
    cout << res << endl;
}
