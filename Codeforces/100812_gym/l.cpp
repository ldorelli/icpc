#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

void gcdEx(LL a, LL b, LL& x, LL& y, LL& g)
{
    if (!b) { x = 1; y = 0; g = a; return; }
    gcdEx(b, a%b, x, y, g);
    LL x1 = y;
    LL y1 = x-(a/b)*y;
    x = x1;
    y = y1;
}

LL gcd (LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main (void) {
    LL x, y, a, b;
    cin >> x >> y;
    LL xx = x, yy = y;
    LL lcm = (x*y)/gcd(x,y);
    
    if (x == 1 and y == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (x == 1 or y ==1) {
        cout << 2 << endl;
        return 0;
    }

    set <int> F;
    bool good = true;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x%i == 0)  {
            F.insert(i);
            while (x%i == 0) x /= i;
        }
    }
    F.insert(x);

    for (int i = 2; i <= sqrt(y); ++i) {
        if (y%i == 0)  {
            if (F.count(i)) good = false;
            while (y%i == 0) y /= i;
        }
    }
    if (F.count(y)) good = false;

    if (good) {
        x = xx, y = yy;
        LL g;
        gcdEx (x, y, a, b, g);
        LL va = x*a;
        LL vb = y*b;
        LL res;
        if (va < 0) res = vb;
        else if (vb < 0) res = va;
        else res = min(va, vb);
        cout << min(res, lcm) << endl;
    } else {
        cout << lcm << endl;
    }
}   
