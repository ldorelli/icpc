#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], b[N];

int main (void) {

    ios::sync_with_stdio (false);

    int n, m, c;
    cin >> n >> m >> c;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int i = 0, j = 0;


    vector < vector<int> > ans;
    for ( ; i < n; ) {
       
        while (j < m and b[j] != a[i]) {
            j++;
        }

        vector <int> group;
        int tot = c;

        while (i < n and tot > 0) {
            if (a[i] == b[j]) {
                group.push_back(i + 1);
                ++i;
            } else {
                break;
            }
            tot--;
            ++j;
        }
        ans.push_back ( group );
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); ++j) cout << ans[i][j] << " ";
        cout << endl;
    }
}
