#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;

const int N = 200010;
int v[N];

int main (void) {
    ios::sync_with_stdio (false);

    int n, c, t;
    cin >> n >> t >> c;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    int ans = 0;
    int big = 0;
    int j = 0;
    for (int i = 0; i+c-1 < n; ++i) {
        while (j <= i+c-1) {
            if (v[j] > t) big++;
            ++j;
        }
        if (!big) ans++;
        if (v[i] > t) big--;
    }

    cout << ans << endl;


    return 0;
}
