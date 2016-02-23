#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;



int main (void) {
    ll d, l, v1, v2;

    cin >> d >> l >> v1 >> v2;

    setprecision (10);
    cout << fixed << (l-d)/(long double)(v1+v2) << endl;

    return 0;
}
