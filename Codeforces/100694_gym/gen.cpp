#include <bits/stdc++.h> 

using namespace std;

int main (void) {
    srand ( time(0) );

    for (int i = 0; i < 10000; ++i) {
        int p = rand()%1000+1;
        int n = rand()%1000+1;
        int x = rand()%n + 1;
        cout << p << " " << n << " " << x << endl;
    }
}
