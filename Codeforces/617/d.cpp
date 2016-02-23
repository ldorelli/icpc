#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];



int needs (int i, int j) {
    if (x[i] == x[j]) return 1;
    if (y[i] == y[j]) return 1;
    return 2;
}


bool share_coor (int i, int j) {
    return x[i] == x[j] or y[i] == y[j];
}

int in_between (int c, int a, int b) {
    int xa = min(x[a], x[b]);
    int xb = max(x[a], x[b]);
    int ya = min (y[a], y[b]);
    int yb = max (y[a], y[b]);
    if (y[a] == y[b] and (x[c] > xa and x[c] < xb)) return 3;
    if (x[a] == x[b] and (y[c] > ya and y[c] < yb)) return 3;
    return 2;
}

int solve (int a, int b, int c) {
    if (x[a] == x[b] and x[a] == x[c]) return 1;
    if (y[a] == y[b] and y[a] == y[c]) return 1;

    if (share_coor(a, b) or share_coor (a, c)) {
        return in_between (c, a, b);
    }
    if (share_coor(b, c) or  share_coor (b, a)) {
        return in_between (c, a, b);
    }
    if (share_coor(c, a) or  share_coor (c, b)) {
        return in_between (c, a, b);
    }

    return 3;
}

int main (void) {
    
    vector < pair<int,int> > v;
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
        v.push_back( make_pair(x[i], y[i]));
    }
    sort (v.begin(), v.end());
    for (int i = 0; i < 3; ++i) {
        x[i] = v[i].first;
        y[i] = v[i].second;
    }

    int ans = solve(0, 1, 2);
    cout << ans << endl;

    return 0;
}
