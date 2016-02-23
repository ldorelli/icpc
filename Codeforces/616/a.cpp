#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
char a[N], b[N];

string get (char * s, int l) {
    
    string res;
    bool ins = false;
    for (int i = 0; i < l; ++i) {
        if (s[i] != '0') ins = true;
        if (ins) res += s[i];
    }
    return res;
}

int main (void) {
   scanf ("%s%s", a, b);
   
   int A = strlen(a);
   int B = strlen(b);

   string aa;
   string bb;
 
   string x = get (a, A);
   string y = get (b, B);

   if (x.size() != y.size()) {
        if (x.size() < y.size()) {
            printf ("<\n");
        } else {
            printf (">\n");
        }
   } else {
       if (x == y) {
            printf ("=\n");
       } else {   

           if (x < y) {
               printf ("<\n");
           } else {
               printf (">\n");
           }
       }
   }
}
