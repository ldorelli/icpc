#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

string s;
string p;
int n, m, k;
int S, T;

char changed[500];
int cnt[500][10][10];
int score[10][10], pos[10];

int l, r;

int b_size (int B) {
    return ((B + 1) * S) < n ? S : (n - B*S);
}

int last (int B) {
    return B*S + b_size(B) - 1;
}

void clear_block (int B) {
    for (int i = 0; i < b_size(B); ++i) {
        if (changed[B]) s[S*B+i] = changed[B];
    }
    changed[B] = 0;
}

bool inside_query (int pos) {
    return pos >= l and pos <= r;
}

void update_pos (int x, char c) {
    int b = x/S;

    if (changed[b]) s[x] = changed[b];

    if (x) {

        if (changed[(x-1)/S]) s[x-1] = changed[(x-1)/S];

        char A = inside_query(x-1) ? c : s[x-1];
        char B = inside_query(x) ? c : s[x];
        cnt[b][s[x]-'a'][s[x-1]-'a']--;
        cnt[b][B-'a'][A-'a']++;
    }

    if ( inside_query(x) ) {
        s[x] = c;
    }
}
    
void update_inside (int b, int e, char c) {  
    clear_block(b/S);
    
    for (int i = e; i >= b; --i) {
        update_pos (i, c);
    }
}

void update_bucket (int B, char c) {
    memset ( cnt[B] , 0, sizeof cnt[B]  );
    cnt[B][c-'a'][c-'a'] = b_size(B) - 1;
    changed[B] = c;
    if (S*B) {
        cnt[B][s[S*B]-'a'][s[S*B-1]-'a']++;
        update_pos (S*B, c);
    }
}

bool inside_block (int x, int b) {
    return x >= b*S and x < b*S + b_size(b);
}

void update (char c) {
    for (int i = T-1; i >= 0; --i) {
        
        if (l >= S*i + b_size(i) or r < (S*i)) continue;
        
        if (inside_block(l, i) and inside_block(r, i)) {
            update_inside (l, r, c); 
        } else if ( inside_block(l, i) ) {
            update_inside (l, S*i + b_size(i)-1, c);
        } else if ( inside_block(r, i) ) {
            update_inside (S*i, r, c);
        } else {
            update_bucket (i, c);
        }
    }
}

int query (string q) {
    int ans = 0;
    
    for (int i = 0; i < q.size(); ++i) {
        pos[q[i]-'a'] = i;
    }
    
    for (int i = 0; i < q.size(); ++i) {
        for (int j = 0; j < q.size(); ++j) {
            score[i][j] = (pos[i] <= pos[j]);
        }
    }
    

    for (int i = 0; i < T; ++i) {
        //printf ("BUC %d \n", i);
        for (int j = 0; j < q.size(); ++j) {
            for (int k = 0; k < q.size(); ++k) {
                ans += cnt[i][j][k] * score[j][k];
          //      if (cnt[i][j][k]) printf ("%c %c %d\n", j+'a', k+'a', cnt[i][j][k]);
            }
        }
    }

    return 1 + ans;
}


int main (void) {
    
    ios::sync_with_stdio (false);

    cin >> n >> m >> k;
    cin >> s;


    for (S = 1; S*S < n; ++S);
    T = n%S == 0 ? n/S : n/S+1;

    for (int i = 1; i < s.size(); ++i) {
        cnt[i/S][s[i]-'a'][s[i-1]-'a']++;
    }

    for (int i = 0; i < m; ++i) {
        int t; 
        cin >> t;

        if (t == 1) {
            string c;
            cin >> l >> r >> c;
            --l, --r;
            
            if (r + 1 < n) {
                update_pos (r + 1, c[0]);
            }
            update (c[0]);
        } else {
            string p;
            cin >> p;
            cout << query (p) << endl;
        }
    }

    return 0;
}
