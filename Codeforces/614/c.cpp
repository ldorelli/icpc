#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


const int N = 100010;

struct vec2 {
    long double x, y;

    vec2 () {}
    vec2 (long double x, long double y) : x(x), y(y) {}

    vec2 operator+ (vec2 b) const {
        return vec2 (x + b.x, y + b.y);
    }
    vec2 operator- (vec2 b) const {
        return vec2 (x - b.x, y - b.y);
    }
    long double dot (vec2 b) {
        return x * b.x + y * b.y;
    }
    vec2 operator* (long double t) {
        return vec2 (x*t, y*t);
    }
    long double len2 () {
        return x*x + y*y;
    }
    long double distance (vec2 b) {
        return sqrt ( (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};

vec2 P;
vec2 in [N];

long double  minimum_distance(vec2 v, vec2 w, vec2 p) {
    long double l = (w-v).len2();
    
    if (fabs(l) < 1e-14) return p.distance(v);
    long double t = (p - v).dot(w - v)/l;
    
    if (t < 0.0) return p.distance(v);
    else if (t > 1.0) return p.distance(w);
    vec2 prj = v + (w - v) * t;  
    
    return p.distance(prj); 
}

long double area (long double d) {
    return d*d * acos(-1);
}

int main (void) {

    int n;
    cin >> n >> P.x >> P.y;

    long double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> in[i].x >> in[i].y;;
    }

    long double bigD = 0.0;
    long double smallD = -1;

    for (int i = 0; i < n; ++i) {
        if (in[i].distance(P) > bigD) bigD = in[i].distance (P);
        long double dd = minimum_distance (in[i], in [(i+1)%n], P);
        if (dd < smallD or smallD == -1) {
            smallD = dd;
        }
    }

    cout<<fixed<<setprecision(20) << (area(bigD) - area(smallD)) << endl;
}
