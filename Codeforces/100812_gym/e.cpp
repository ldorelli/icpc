#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int vis[N];

struct card {
    int c, r, id;
    card (){}
    card (int c, int r, int id) : c(c), r(r), id(id) {}

    bool operator< (const card& b) const {
        return c < b.c;
    }
};

vector <card> v;

int main (void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(card(a, b, i));
    }

    vector <int> ans;
    sort (v.begin(), v.end());

    int res = 1;
    int i = 0;
    bool good = false;
    while (1) {
        int cand = -1;
        for (; i < n; ++i) {
            if (v[i].c > res) break;
            else {
                if (v[i].id == n) {
                    cand = i;
                    ++i;
                    break;
                }  
                if (v[i].r > res) {
                    if (cand == -1) cand = i;
                    else if (v[cand].r < v[i].r) cand = i;
                }
            }
        }
        if (cand == -1) break;
        if (v[cand].id == n) good = true;
        ans.push_back(v[cand].id);
        res = v[cand].r;
    }

    if (!good) cout << "No such luck\n";
    else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
}
