#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;

const int N = 1000010;
ll v[N];
int n, m;

int main (void) {
    scanf ("%d %d", &n, &m);

    vector <int> w;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        scanf ("%lld", &v[i]);
        if (c == 0) w.push_back(i);
        c = (c + 1)%m;
    }

    ll ans = 0;
    int p = w[w.size()/2];
    for (int i = 0; i < n and v[i] < v[p]; i += m) {
        ans += (v[p]-v[i]) * 2LL;
    }
    for (int i = n-1; i >= 0 and v[i] > v[p]; i -= m) {
        ans += (v[i] - v[p]) * 2LL;
    }
    cout << ans << endl;
    return 0;
}
