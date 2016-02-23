#include <bits/stdc++.h>

using namespace std;

const int N = 504;

vector <int> g[N];
bool G[N][N];
int n, m;
char T[N];

bool solve (int x) {

    T[x] = 'a';
    
    for (int i = 0; i < n; ++i) {
        if (T[i] != -1) continue;
        bool connects = false;
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] == x) connects = true;
        }
        if (!connects) T[i] = 'c';
    }



    for (int i = 0; i < n; ++i) {
        if (T[i] == -1) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (T[i] != -1) {
                    break;
                }
                int k = g[i][j];
                if (T[k] == 'c') {
                    if (T[k] == 'a') return false;
                    T[i] = 'b';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (T[i] == -1) T[i] = 'a';
    }


    vector <int> A, B, C;
    for (int i = 0; i < n; ++i) { 
        if (T[i] == 'a') A.push_back(i);
        else if (T[i] == 'b') B.push_back(i);
        else C.push_back(i);
    }
    
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i+1; j < A.size(); ++j) {
            if (G[A[i]][A[j]] == 0) return false;
        }
        for (int j = 0; j < C.size(); ++j) {
            if (G[A[i]][C[j]] == 1) return false;
        }
        for (int j = 0; j < B.size(); ++j) {
            if (G[A[i]][B[j]] == 0) return false;
        }
    }

    for (int i = 0; i < C.size(); ++i) {
        for (int j = i+1; j < C.size(); ++j) {
            if (G[C[i]][C[j]] == 0) {
                return false;
            }
        }
        for (int j = 0; j < A.size(); ++j) {
            if (G[C[i]][A[j]] == 1) {
                return false;
            }
        }
        for (int j = 0; j < B.size(); ++j) {
            if (G[C[i]][B[j]] == 0) {
                return false;
            }
        }
    }

    for (int i = 0; i < B.size(); ++i) {
        for (int j = i + 1; j < B.size(); ++j) {
            if (G[B[i]][B[j]] == 0) return false;
        }
    }

    return true;
}

int main (void) {

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    bool good = false;
    for (int i = 0; i < n; ++i) {
        memset (T, -1, sizeof T);
        if ( solve(i) ) {
            good = true;
            break;
        }
    }

    if (!good) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) {
            cout << T[i];
        }
        cout << endl;
    }

    return 0;
}
