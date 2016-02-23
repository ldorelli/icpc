#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;

const int N = 200010;
ll ac[N];

int main (void) {
    string a, b;
    cin >> a >> b;

    int n = b.size();
    int k = a.size();

    ac[0] = (b[0] == '1')  ? 1 : 0;
    // acumulado de 1s
    for (int i = 1; i < b.size(); ++i) {
        ac[i] = ac[i-1] + (b[i] == '1' ?  1 : 0);
    }

    ll res = 0;
    for (int i = 0; i < a.size(); ++i) {
        ll su = ac[n-k+i];
        if (i) su -= ac[i-1];
        if (a[i] == '0')  res += su;
        else res += n-k+1-su;
    }
    cout << res << endl;

    return 0;
}
