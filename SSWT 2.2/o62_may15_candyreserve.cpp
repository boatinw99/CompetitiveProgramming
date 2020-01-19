#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 3e5+9 ;
vector<int> cc ;
pair<pii,int> V[N] ;
int dp[N][5],val[N];
int main()
{
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        int u,v,x ;
        cin >> u >> v >> x ;
        V[i]={{u,v},x};
        cc.push_back(u);
        cc.push_back(v);
    }
    sort(cc.begin(),cc.end());
    int sz = cc.size();
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    for(int i=1;i<=n;i++)
    {
        V[i].fi.fi=lower_bound(cc.begin(),cc.end(),V[i].fi.fi)-cc.begin()+1;
        V[i].fi.se=lower_bound(cc.begin(),cc.end(),V[i].fi.se)-cc.begin()+1;
        val[V[i].fi.fi]+=V[i].se;
        val[V[i].fi.se]+=V[i].se;
    }
    for(int i=1;i<=sz;i++)
    {
        dp[i][1]=max(val[i],dp[i-1][1]);
        if(i>=2)
        {
            dp[i][1]=max(dp[i][1],val[i]+dp[i-2][0]);
            dp[i][2]=max(dp[i-1][2],val[i]+dp[i-2][1]);
            dp[i][3]=max(dp[i-1][3],val[i]+dp[i-2][2]);
        }
    }
    cout << dp[sz][3] ;
    return 0 ;
}
