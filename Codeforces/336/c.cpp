#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long int ll;
typedef pair<int, int> pii;

const int N = 100001;
int ans[N];

int main (void) {

    int n; 
    cin >> n;
    vector<pii> v (n) ;
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i].F >> v[i].S;
    }

    sort (v.begin(), v.end());

    ans[0] = 0;
    for (int i = 1; i < n; ++i) {
        int p = lower_bound(v.begin(), v.begin()+i, make_pair(v[i].F - v[i].S, -1) ) - v.begin() - 1;
        int d = i - p - 1;
        ans[i] = d;
        if (p >= 0) ans[i] += ans[p];
    }
    int res = n;
    for (int i = 0; i < n; ++i) res =  min(res, ans[i] + n-i-1);
    cout << res << endl;
    return 0;
}
