#include <bits/stdc++.h>

using namespace std;

#define F fisrt
#define S second

typedef long long int ll;

string a, b;
const int N = 5010;
ll B[2] = { 37, 73 };
ll  pot[2][N];
ll  H[2][2][N];
ll mod = 1000000009;

void calc_hash (string &s, int id) {
    for (int i = 0; i < s.size(); ++i) {
        for (int b = 0; b < 2; ++b) {
            if (i == 0) H[id][b][0] = (s[0] - 'a' + 1);
            else H[id][b][i] = ((H[id][b][i-1] * B[b])%mod + (s[i] - 'a' + 1)) % mod;
        }
    }
}

pair<ll, ll> get_hash (int id, int i, int j) {
    ll res[2] = { H[id][0][j], H[id][1][j] };
    if (i > 0) {
        res[0] = (res[0] - (pot[0][j-i+1] * H[id][0][i-1])%mod  + mod ) % mod;
        res[1] = (res[1] - (pot[1][j-i+1] * H[id][1][i-1])%mod  + mod ) % mod;
    }
    return make_pair( res[0], res[1] );
}


bool good (int x) {

    map < pair<ll, ll>, int > s1, s2;
    
    for (int i = 0; i+x-1 < a.size(); ++i) {
        int j = i+x-1;
        auto h = get_hash (0, i, j);
        s1[h]++;
    }

    for (int i = 0; i+x-1 < b.size(); ++i) {
        int j = i+x-1;
        auto h = get_hash (1, i, j);
        s2[h]++;
    }

    for (auto& x : s1) {
        if (x.second == 1) {
            auto it = s2.find(x.first);
            if (it == s2.end()) continue;
            if (it->second == 1) return true;
        }
    }

    return false;
}

int main (void) {

    ios::sync_with_stdio (false);

    for (int i = 0; i < 2; ++i) {
        pot[i][0] = 1;
        for (int j = 1; j < N; ++j) {
            pot[i][j] = (pot[i][j-1]*B[i])%mod;
        }
    }

    cin >> a >> b;
    
    calc_hash(a, 0);
    calc_hash(b, 1);

    int res = -1;
    for (int i = 1; i <= min(a.size(), b.size()); ++i) {
        if (good(i)) {
            res = i;
            break;
        }
    }
    cout << res << endl;

    return 0;
}
