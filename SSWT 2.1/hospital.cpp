#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
vector<int> g[N];
int sub1[N],sub2[N];
ll dp0[N],dp1[N];
void dfs0(int u,int v)
{
    sub1[u]=1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            dp0[u]+=dp0[it]+sub1[it];
            sub1[u]+=sub1[it];
        }
    }
}
void dfs1(int u,int v)
{
    ll all=dp1[u];
    sub2[u]++;
    int sz=0;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            all+=dp0[it];
            sz+=sub1[it];
        }
    }
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dp1[it]=(all-dp0[it])+(1ll*sz-sub1[it]+sz-sub1[it]+sub2[u]);
            sub2[it]=(sz-sub1[it]+sub2[u]);
            dfs1(it,u);
        }
    }
}
int main()
{
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,0);
    dfs1(1,0);
    ll ans=1e18 ;
    for(i=1;i<=n;i++)
    {
        ans=min(ans,dp1[i]+dp0[i]);
        //printf("a %lld %lld\n",dp0[i],dp1[i]);
    }
    cout << ans ;
}
