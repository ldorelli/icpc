#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n, k;
    
    scanf ("%d %d", &n, &k);

    vector <int> v (n);

    for (int i = 0; i < n; ++i) {
        scanf ("%d", &v[i]);
    }

    map <int, int> m;
    int j = 0;
    int ans = 0;
    int ansl = -1;
    for (int i = 0; i < n; ++i) {
        while (j < n) {
            if (m.size() < k or (m.size() == k and m.count(v[j]))) {
                m[v[j]]++;
                j++;
            } else {
                break;
            }
        }

        if (ans < j-i) {
            ans = j-i;
            ansl = i;
        }
        m[v[i]]--;
        if (m[v[i]] == 0) {
            m.erase(v[i]);
        }
    }

    printf ("%d %d\n", ansl+1, ansl+ans);

    return 0;
}
