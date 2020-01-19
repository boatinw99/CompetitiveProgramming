#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e4+9 ,K = 11;
bool vst[N];
int dp1[N],dp2[N];
vector<pii> g[N];
pair<pii,int> edge[K];
void dfs(int u,int v)
{
    dp1[u]=dp2[u]=0;
    for(auto it:g[u])if(it.fi!=v)dfs(it.fi,u),dp2[u]+=dp1[it.fi];
    dp1[u]=dp2[u];
    for(auto it:g[u])if(it.fi!=v)
    {
        if(!vst[u]&&!vst[it.fi])
        dp1[u]=max(dp1[u],dp2[u]-dp1[it.fi]+it.se+dp2[it.fi]);
    }
    dp1[u]=max(dp1[u],dp2[u]);
}
main()
{
    int n,k,i,j,u,v,x,cst=0 ;
    cin >> n >> k ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    for(i=0;i<k;i++)
    {
        cin >> edge[i].fi.fi >> edge[i].fi.se >> edge[i].se ;
    }
    int bits=1<<k,ans=0 ;
    for(i=0;i<bits;i++)
    {
        cst=0 ;
        for(j=0;j<k;j++)
        {
            if(((1<<j)&i)&&!vst[edge[j].fi.fi]&&!vst[edge[j].fi.se])
            {
                vst[edge[j].fi.fi]++;
                vst[edge[j].fi.se]++;
                cst+=edge[j].se ;
            }
        }
        dfs(1,0);
        ans=max(ans,cst+dp1[1]);
        for(j=0;j<k;j++)vst[edge[j].fi.fi]=vst[edge[j].fi.se]=0;
    }
    cout << ans ;
}
