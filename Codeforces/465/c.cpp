#include <bits/stdc++.h>

using namespace std;

int n, p;

bool check_pos (string &s, int i) {
    if (i > s.size() or i < 0) return true;
    char j = s[i];
    if (i + 2 < s.size() and s[i+2] == j) return false;
    if (i + 1 < s.size() and s[i+1] == j) return false;
    if (i - 1 >= 0 and s[i-1] == j) return false;
    if (i - 2 >= 0 and s[i-2] == j) return false;
    return true;
}

bool good (string& s, int i) {
    return  check_pos(s, i) and check_pos(s, i-1) and check_pos(s, i-2) and check_pos(s, i+1) and check_pos(s, i+2);
}

 int main (void) {

    string s;

    cin >> n >> p;
    cin >> s;

    if (p == 2 and n > 2) {
        cout << "NO\n";
        return 0;
    }

    string ans = "";
    for (int i = s.size()-1; i >= 0; --i) {
        for (char c1 = 'a'; c1 < 'a'+p; ++c1) {
            if (ans != "") break;
            for (char c2 = 'a'; c2 < 'a' + min(p, 4); ++c2) {
                if (ans != "") break;
                for (char c3 = 'a'; c3 < 'a' + min(p, 4); ++c3) {
                    if (ans != "") break;
                    string ss = s;
                    ss[i] = c1;
                    if (i + 1 < n) ss[i+1] = c2;
                    if (i + 2 < n) ss[i+2] = c3;
                    if (ss < s) continue;
                        string ord = "abc";
                        do {
                            int c = 0;
                            string T = ss;
                            for (int p = i + 3; p < n; ++p) {
                                T[p] = ord[c];
                                c = (c+1)%3;
                            }   
                            if ( good(T, i) and good(T, i+1) and good(T, i+2) and good(T, i+3) and T > s) {
                                if (ans == "") ans = T;
                                else ans = min(ans, T);
                            }
                        } while (next_permutation(ord.begin(), ord.end()) );
                }
            }
        }
    }

    if (ans == "") {
        cout << "NO\n";
    } else cout << ans << endl;
    return 0;
 }