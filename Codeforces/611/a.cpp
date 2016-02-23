#include <bits/stdc++.h>

using namespace std;

int months[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int weeks[] = { 52, 52, 52, 52, 53, 53, 52 };

int main (void) {
    
    int d;
    string s;
    cin >> d >> s >> s;

    if (s == "week") {
        cout << weeks[d-1] << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < 12; ++i) {
            if (months[i] >= d) {
                ++ans;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
