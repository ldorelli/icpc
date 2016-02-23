#include <bits/stdc++.h>

using namespace std;

int main (void) {

    int n; 
    cin >> n;

    set <long long int> vis;
    vector <long long int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long long int ans = 0;
    sort (v.begin(), v.end());

    for (int i = n-1; i >= 0; --i) {
        while (v[i] != 0 and vis.count(v[i]) != 0) {
            v[i]--;
        }
        vis.insert(v[i]);
        ans += v[i];
    }
    cout << ans << endl;

    return 0;
}
