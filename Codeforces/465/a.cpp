#include <bits/stdc++.h>

using namespace std;

int main (void) {
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    int c = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1' and c) ans++;
        else {
            if (c) ans++;
            c = 0;
        }
    }
    cout << ans << endl;
}
