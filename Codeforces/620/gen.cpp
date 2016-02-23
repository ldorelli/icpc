#include <bits/stdc++.h>

using namespace std;

int main (void) {

    srand ( time(0) );

    int n = 300000;
    cout << n << endl;

    for (int i = 0; i < n; ++i) {
        cout << rand() << " ";
    }
    cout << endl;
}
