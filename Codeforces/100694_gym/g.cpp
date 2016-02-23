#include <bits/stdc++.h>

using namespace std;

int main (void) {

    ios::sync_with_stdio (false);

    int n;
    cin >> n;

    stack <int> s;

    for (int i = 0; i < 2*n; ++i) {

        string op;
        int x;
        cin >> op >> x;

        if (op == "in") {
            if (!s.empty()) {
                cout << x << " " << s.top() << endl;
            } 
            s.push(x);
        } else {
            s.pop();
        }
    }

    return 0;
}
