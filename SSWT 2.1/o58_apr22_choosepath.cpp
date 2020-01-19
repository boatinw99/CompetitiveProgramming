#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
vector<pii> g[N];
ll a[N],dp[2][2]; /// D=even,- | D=even,+ | D=odd,- | D=odd,+
int sub[N];
bool vst[N];
ll ans = 0 ;
void dfs1(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])if(!vst[it.fi])dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it.fi!=v&&!vst[it.fi]&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,int dist)
{
    vst[u]++;
    int mul=-1;
    if(dist==0)mul=1;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)
        ans+=max(0ll,a[u]*mul*dp[i][j]);
/*
    if(dist&&a[u]<0)ans+=-a[u]*(dp[0][0]+dp[1][1]);
    else if(dist&&a[u]>0)ans+=-a[u]*(dp[0][1]+dp[1][0]);
    else if(!dist&&a[u]<0)ans+=a[u]*(dp[0][1]+dp[1][0]);
    else ans+=a[u]*(dp[0][0]+dp[1][1]);
*/
    //printf("ans = %lld \n",ans);
    for(auto it:g[u])if(!vst[it.fi])dfs3(it.fi,(dist+it.se)&1);
    vst[u]=0;
}
void dfs4(int u,int dist)
{
    vst[u]++;
    dp[dist][a[u]<0]+=a[u]*(dist==0?1:-1);
    //printf("aa %d %d\n",u,dist);
    for(auto it:g[u])if(!vst[it.fi])dfs4(it.fi,(dist+it.se)&1);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    dp[0][a[ctd]<0]+=a[ctd];
    for(auto it:g[ctd])
    {
        if(!vst[it.fi])
        {
            dfs3(it.fi,it.se&1);
            dfs4(it.fi,it.se&1);
        }
    }
    memset(dp,0,sizeof dp) ;
    for(auto it:g[ctd])if(!vst[it.fi])dcp(it.fi);
}
main()
{
    int n,i,j,u,v ;
    cin >> n ;
    cin >> a[0];
    for(i=1;i<n;i++)
    {
        cin >> a[i] >> u >> v ;
        g[u].emplace_back(i,v);
        g[i].emplace_back(u,v);
    }
    dcp(0);
    cout << ans ;
}
