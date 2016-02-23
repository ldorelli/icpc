#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
int v[N];
int prox[N];

int main (void) {
    
    int n ;
    cin >> n;
    
    map <int, int> last;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector < pair<int,int> > ans;

    for (int i = n-1; i >= 0; --i) {
        if (last.count(v[i]) != 0) {
            prox[i] = last[v[i]];
        } else {
            prox[i] = -1;
        }
        last[v[i]] = i;
    }   

    bool good = false;
    for (int i = 0; i < n; ++i) {
        if (prox[i] != -1) {
            good = true;
        }
    }

    if (!good) {
        cout << -1 << endl;
        return 0;
    }

    int b =  0;
    for (int i = 0; i < n; ) {
        if (prox[i] != -1) {
            ans.push_back ( make_pair(b + 1, prox[i]+1) );
            b = prox[i]+1;
            i = prox[i]+1;
        } else {
            ++i;
        }
    }

    if (ans[ans.size()-1].second != n) {
        ans[ans.size()-1].second = n;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}
