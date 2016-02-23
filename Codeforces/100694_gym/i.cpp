#include <bits/stdc++.h>

using namespace std;


int D[4][2] = { {0, 1} , {0, -1} , {-1, 0}, {1,  0} };

bool arrives (int t, int gx, int gy, int x, int y, int d) {
    int goal[2] = { gx + t*D[d][0], gy + t*D[d][1] };
    
    int dx = abs (goal[0] - x);
    int dy = abs (goal[1] - y);

    dx = dx/2 + dx%2;
    dy = dy/2 + dy%2;

    return dx + dy <= t;
}


int solve (int gx, int gy, int x, int y, int d) {

    int lo = 0, hi = 1000000;
    while (lo != hi) {
        int mi = (lo + hi)/2;
        if ( arrives (mi, gx, gy, x, y, d) ) hi = mi;
        else lo = mi + 1;
    }
    return lo;
}

int main (void) {

    ios::sync_with_stdio (false);

    map <string, int> dir;
    dir["LEFT"] = 2;
    dir["RIGHT"] = 3;
    dir["UP"] = 0;
    dir["DOWN"] = 1;

    int gx, gy;
    cin >> gx >> gy;

    string where;
    cin >> where;

    string winner = "";
    
    int n, best = -1;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        int x, y;
        cin >> x >> y;

        int S = solve (gx, gy, x, y, dir[where]);
        if (best == -1 or S  < best) {
            best = S; 
            winner = s;
        }
    }

    cout << winner << endl;

    return 0;
}
