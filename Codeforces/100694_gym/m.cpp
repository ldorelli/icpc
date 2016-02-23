#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int r, l;
        cin >> l >> r;
        int ci = r + l;
        if (r == l) { 
            cout << n/r << endl;
        } else {
            if (n/ci == 0) {
                if (n >= l) cout << 1 << " ";
                else cout << 0 << endl;
            } else {
                int A = (n/ci) * 2 - 1;
                int B = 1;
                if (n%ci >= l) B = 2 ;
                cout << (A + B) << " ";
            }
        }
    }
    cout << endl;
    return 0;

}
