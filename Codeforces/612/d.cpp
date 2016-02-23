#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

#define F first
#define S second


struct Event {
    int id;
    int t, x, y;

    Event () {}
    Event (int id, int t, int x, int y) : id(id), t(t), x(x), y(y) {}

    bool operator < (const Event& b) const {
        if (x != b.x)  return x < b.x;
        return t > b.t;
    }
};

int S[N][2];

int main (void) {
    
    int n, k;
    scanf ("%d %d", &n, &k);

    vector <Event> v;

    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf ("%d %d", &a, &b);
        S[i][0] = a;
        S[i][1] = b;
        v.push_back ( Event(i, 1, a, b) );
        v.push_back ( Event(i, 0, b, a) );
    }

    sort (v.begin(), v.end());

    vector < pair<int,int> > s;
    int count = 0;
    int lastx = -1;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].t == 1) {
            count++;
            if (count == k) {
                lastx = v[i].x;
            }
        } else {
            if (count == k) {
                int id = s.size();
                s.push_back ( make_pair( lastx, v[i].x ) );
            } 
            count--;
        }
    }

    sort (s.begin(), s.end());

    printf ("%d\n", (int)s.size());
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i].F << " " << s[i].S << endl;
    }
}
