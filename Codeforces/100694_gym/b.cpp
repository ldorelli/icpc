#include <bits/stdc++.h>

using namespace std;

int go_forward (int p, int n, int x) {
    int r = x/p;
    return x - r*p + r;
}   

int go_back (int p, int n, int x) {
    int r = x/p;
    int nv = min(n, (r+1)*p);
    return (r + 1) + nv - x;
}

int the_smart_play (int p, int n, int x) {
    int r = n/p;
    if (r*p != n) ++r;
    return r +  min( go_back(p, n, n-x), go_forward(p, n, n-x) );
}

int solve (int p, int n, int x) {
    return min (go_forward(p, n, x) , go_back(p, n, x) );
}

int main (void) {

    int p, n, x;
    while ( cin >> p >> n >> x ) {
        cout << min ( solve (p, n, x), the_smart_play(p, n, x) ) << endl;
    }

    return 0;
}   
