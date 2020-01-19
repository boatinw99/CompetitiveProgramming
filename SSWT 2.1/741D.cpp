#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 5e5+9,BIT=1<<('w'-'a'),mxbit='v'-'a';
vector<pii> g[N];
int sub[N],ans[N],cnt[BIT],a[N],tin[N],tout[N],odr[N],times=0,depth[N];
int findmax(int bits)
{
    int x=cnt[bits] ;
    for(int i=0;i<=mxbit;i++)
    {
        x=max(x,cnt[bits^(1<<i)]);
    }
    return x ;
}
void dfs0(int u,int bits)
{
    a[u]=bits;
    sub[u]=1;
    tin[u]=++times;
    odr[times]=u;
    for(auto it:g[u])
        depth[it.fi]=depth[u]+1,dfs0(it.fi,bits^it.se),sub[u]+=sub[it.fi];
    tout[u]=times ;
}
void dfs1(int u,bool kp)
{
    int mx=0,hc=0 ;
    for(auto it:g[u])if(sub[it.fi]>mx)mx=sub[it.fi],hc=it.fi;
    for(auto it:g[u])if(it.fi!=hc)dfs1(it.fi,0);
    if(hc)dfs1(hc,1);
    for(auto it:g[u])ans[u]=max(ans[u],ans[it.fi]);
    int tmp = findmax(a[u]);
    ans[u]=max(ans[u],tmp-depth[u]);
    cnt[a[u]]=max(depth[u],cnt[a[u]]);
    for(auto it:g[u])if(it.fi!=hc)
    {
        for(int i=tin[it.fi];i<=tout[it.fi];i++)
        {
            int tmp = findmax(a[odr[i]]);
            ans[u]=max(ans[u],depth[odr[i]]+tmp-2*depth[u]);
        }
        for(int i=tin[it.fi];i<=tout[it.fi];i++)
        {
            cnt[a[odr[i]]]=max(cnt[a[odr[i]]],depth[odr[i]]);
        }
    }
    if(!kp)
    {
        for(int i=tin[u];i<=tout[u];i++)
        {
            cnt[a[odr[i]]]=-N;
        }
    }
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j,u,v ;
    char c ;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> u >> c ;
        g[u].emplace_back(i,1<<(c-'a'));
    }
    fill(cnt,cnt+BIT-1,-N);
    dfs0(1,0),dfs1(1,1);
    for(i=1;i<=n;i++)cout << ans[i] << " " ;
}
