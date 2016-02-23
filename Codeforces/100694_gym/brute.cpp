#include <bits/stdc++.h>

using namespace std;

int vis[10000];

int main (void) {
    int p, n, x;
    while ( cin >> p >> n >> x ) {

        memset (vis, -1, sizeof vis);
        vis[0] = 0;

        queue <int> q;
        q.push( 0 );
    
        while (!q.empty()) {

            int next = q.front(); q.pop();
            
            int v[4] = {  1, -1, p, -p };
            
            for (int i = 0; i < 4; ++i) { 
                int p = v[i];
                int nv = next + p;
                if (nv > n) nv = n;
                if (nv < 0) nv = 0;
                if (nv <= n and vis[nv] == -1) {
                    vis[nv] = vis[next] + 1;
                    q.push ( nv );
                }
            }
        }
        cout << vis[x] << endl;
    }
}

