#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;

int main (void) {

    ios::sync_with_stdio (false);

    int of = 0;
    int res = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            if (of) of--;
            else res++;
        }  else of += x;
    }

    cout << res << endl;

    return 0;

}
