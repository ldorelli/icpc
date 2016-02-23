#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int N = 200001;
ll  v[N];
ll pre[N];


int main (void) {
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            cout << (i+1) << " " << 1 << endl;
            return 0;
        }
    }

    int as;
    int best = -1;

    map <ll, int> m;
    pre[0] = v[0];
    m[v[0]] = 0;
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i-1] + v[i];
        
        if (pre[i] == 0) {
            if (best == -1) {
                best = (i+1);
                as = 1;
            }
        } 
        
        if (m.count(pre[i])) {
            int s = m[pre[i]]+2;
            int f = (i+1);
            if (f -s + 1 < best or best == -1) best = f-s+1, as = s;
        }
        m[pre[i]] = i;
    }

    if (best == -1)  cout << -1 << endl;
    else cout << as << " " << best << endl;


    return 0;
}
