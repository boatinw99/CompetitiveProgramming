#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ,md = 1e9+7 ;
int f[N<<1],inv[N<<1],sub[N],pos1[N],pos2[N],par[N],ans=0,n;
vector<int> g[N];
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    if(p==1)return a ;
    int ret = pow2(a,p>>1);
    ret=1ll*ret*ret%md ;
    if(p&1)ret=ret*1ll*a%md;
    return ret ;
}
int possible(int p,int q)
{
    return 1ll*f[p+q]*inv[p]%md*inv[q]%md;
}
int inverse(int d)
{
    return pow2(d,md-2);
}
void dfs0(int u,int v)
{
    int sz=0 ;
    pos1[u]=1 ;
    sub[u]=1;
    par[u]=v;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            pos1[u]=1ll*pos1[u]*possible(sz,sub[it])%md*pos1[it]%md;;
            sz+=sub[it];
            sub[u]+=sub[it];
        }
    }
}
void dfs1(int u,int v)
{
    int sz=sub[u]-1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            int tmp = 1ll*possible(sz-sub[it],sub[it])*pos1[it]%md;
            int psb = 1ll*pos1[u]*inverse(tmp)%md;
            pos2[it]=1ll*pos2[u]*possible(n-sub[u],sub[u]-sub[it]-1)%md*psb%md;
            dfs1(it,u);
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v ;
    f[0]=1;
    for(i=1;i<N*2;i++)f[i]=1ll*f[i-1]*i%md ;
    for(i=0;i<N*2;i++)inv[i]=inverse(f[i]);
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        u++;
        v++;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    pos2[1]=1;
    dfs1(1,1);
    for(i=1;i<=n;i++)
    {
        int sz = n-sub[i];
        int psb = pos2[i];
        for(auto it:g[i])
        {
            if(it!=par[i])
            {
                psb=1ll*psb*possible(sz,sub[it])%md*pos1[it]%md;
                sz+=sub[it];
            }
        }
        ans=(ans+psb)%md;
    }
    cout << ans ;
}
