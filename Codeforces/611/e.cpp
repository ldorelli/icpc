#include <bits/stdc++.h>

using namespace std;

const int N = 200001;
typedef long long int ll;
ll S[3];


int main (void) {

    int n; 
    cin >> n;

    for (int i = 0; i < 3; ++i) cin >> S[i];

    map <ll, int> Q;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        if (x > S[0] + S[1] + S[2]) {
            cout << -1 << endl;
            return 0;
        }
        Q[x]++;
    }


    ll ans = 0;

    while (Q.size()) {
        
        vector <int> rmv;
        vector <int> best;


        sort (S, S + 3);
        do {
            ll T[3] = { S[0], S[1], S[2] };
            for (int i = 0; i < 3; ++i) {
                auto it = Q.upper_bound(T[i]);
                if (it == Q.begin()) {
                    if (i != 2) T[i+1] += T[i];
                } else {
                    rmv.push_back(it->first);
                }
            }
            if (rmv.size() > best.size()) best = rmv;
        } while (next_permutation (S, S + 3));

            
        for (auto& q : best) {
            auto x = Q.find(q);
            --x;
            Q[x->first]--;
            if (Q[x->first] == 0) Q.erase ( x );
        }

        ++ans;
    }
    cout << ans << endl;

    return 0;
}
