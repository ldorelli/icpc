#include <bits/stdc++.h>

using namespace std;

const int N = 100010;


struct Queue {
    int index, p, c;
    int v[2];

    Queue (int i) {
        index = i;
        v[0] = 0, v[1] = 0;
        p = 0;
        c = 0;
    }

    bool operator < (const Queue& b) const {
        if (c*p != b.c* b.p) return c * p > b.c * b.p;
        return index > b.index;
    }

    void addElement (int val) {
        v[0] = v[1];
        v[1] = val;
        c++;
        if (c == 1) {
            p = 2*v[1];
        } else {
            p = (v[1] + v[0]);
        }
    }
};

int main (void) {
    
    priority_queue  <Queue> q;

    int n, x, k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        q.push( Queue(i + 1) );
    }

    for (int i = 0; i < n; ++i) {
        cin >> x;
        Queue v = q.top(); q.pop();
        cout << v.index << " ";
       // cout << " [" <<  v.c * (v.v[0] + v.v[1]) << "] ";
        v.addElement(x);
        q.push(v);
    }

    return 0;
}
