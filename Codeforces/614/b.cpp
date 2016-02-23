#include <bits/stdc++.h>

using namespace std;

bool isPerfect (string &s) {
    int ones = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '1' and s[i] != '0') return true;
        if (s[i] == '1') ones++;
    }
    if (ones != 1) return true;
    return false;
}

int main (void) {

    vector <int> numbers;

    string P;

    int n;
    
    ios::sync_with_stdio (false);

    cin >> n;

    vector <string> V;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        V.push_back(s);

        if (n == 1) {
            cout << s << endl;
            return 0;
        }

        if (s == "0") {
            cout << "0\n";
            return 0;
        }   

        int countOnes = 0;
        int count = 0;
        int nu = 0;

        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') {
                nu = s.size() - 1 - j;;
                countOnes++;
            } else if (s[j] != '0') {
                count++;
            } 
        }
        if (countOnes > 1 or count > 0) {
            P = s;
        } else {
            numbers.push_back (nu);
        }
    }

    if (P == "") {
        P = V[n-1];
        numbers.pop_back();
    }

    for (int i = 0; i < numbers.size(); ++i) {
        for (int k = 0; k < numbers[i]; ++k) P += '0';
    }

    int noz = false;
    for (int i = 0; i < P.size(); ++i) {
        if (P[i] != '0') noz = true;
        if (noz){
            cout << P[i];
        }
    }
}
