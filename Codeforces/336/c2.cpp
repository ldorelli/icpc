#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back 
#define fi first
#define se second
const int INF = 0x3f3f3f3f;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
const int N=1e5+10;

ii vec[N];
int n;

int main(){
        ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>vec[i].fi>>vec[i].se;

    sort(vec, vec+n);

    vi dp(n+1,0);

    for(int i=0;i<n;i++) {
        int p=lower_bound(vec, vec+n, ii(vec[i].fi-vec[i].se,-1))-vec;
    //  cout<<p<<"@\n";
        --p;
        int dx=i-p-1;
        dp[i]=dx;
        if(p>=0)dp[i]+=dp[p];
        // cout 
     cout<<i<<": "<<dp[i]<<"@\n";
    }

    int ans=n;
    for(int i=0;i<n;i++)
        ans=min(ans, dp[i]+(n-i-1));
    cout<<ans<<endl;

        return 0;
}