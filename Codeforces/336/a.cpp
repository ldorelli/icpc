#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;


const int N = 101;
int t[N], f[N];

int main (void) {
 
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> f[i] >> t[i];
    }
    
    int ct = 0;
    while (s != 0) {
        int wait_time = 0;
        for (int i = 0; i < n; ++i) {
            if (f[i] == s) {
                wait_time = max(wait_time, t[i]);
            }
        }
        if (wait_time > ct) ct = wait_time;
        ct++;
        --s;
    }

    cout << ct << endl;

    return 0;
}
