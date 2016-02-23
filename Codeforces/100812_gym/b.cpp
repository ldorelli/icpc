#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
string in[N];

int cnt (string& x) {
    int res = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == '1') res++;
        if (res > 15) return res;
    }
    return res;
}

int main (void) {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    map <string, int> s;
    for (int i = 0; i < n; ++i) {
        int c = cnt(in[i]);
        if (c >= 8 and c <= 15) s[in[i]]++;
    }
    
    string ans;
    for (int i = 0; i < 8; ++i) ans += '1';
    for (int i = 0; i < m-8; ++i) ans += '0';
    int best = 0;
    for (auto &x : s) {
        if (x.second > best) {
            best = x.second;
            ans = x.first;
        }
    }
    cout << ans << endl;
}

