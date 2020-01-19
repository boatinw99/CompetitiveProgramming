#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 4e4+9 ;
int a[N][2],dp[N][2];
vector<pair<pii,pii> > g ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,t,i,j,u,v ;
    cin >> n >> m >> t ;
    for(i=1;i<=n;i++)cin >> a[i][0];
    for(i=1;i<=m;i++)cin >> a[i][1];
    for(i=1;i<=t;i++)
    {
        cin >> u >> v ;
        g.push_back({{u,v},{0,1}});
    }
    sort(g.begin(),g.end());
    for(auto it:g)
    {
        int tmp = dp[it.fi.fi][it.se.fi]+a[it.fi.fi][it.se.fi];
        dp[it.fi.fi][it.se.fi]=max(dp[it.fi.fi][it.se.fi],
                dp[it.fi.se][it.se.se]+a[it.fi.se][it.se.se]);
        dp[it.fi.se][it.se.se]=max(dp[it.fi.se][it.se.se],tmp);
    }
    int ans=0 ;
    for(i=1;i<=max(n,m);i++)
    {
        ans=max(ans,dp[i][0]+a[i][0]);
        ans=max(ans,dp[i][1]+a[i][1]);
    }
    cout << ans ;
}
