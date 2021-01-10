#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<int> g[N];
vector<pii> query[N];
int sub[N],tin[N],tout[N],clr[N],f[N],ans[N],cnt[N],odr[N],times=0;
void update(int i,int cst)
{
    for(;i;i-=i&-i)f[i]+=cst;
}
int getsum(int i)
{
    int x=0 ;
    for(;i<N;i+=i&-i)x+=f[i] ;
    return x ;
}
void dfs0(int u,int v)
{
    sub[u]=1;
    tin[u]=++times;
    odr[times]=u;
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it];
    tout[u]=times;
}
void dfs1(int u,int v,bool kp)
{
    int mx=0,hc=0;
    for(auto it:g[u])if(it!=v&&sub[it]>mx)mx=sub[it],hc=it ;
    for(auto it:g[u])if(it!=v&&it!=hc)dfs1(it,u,0);
    if(hc)dfs1(hc,u,1);
    update(cnt[clr[u]],-1);
    cnt[clr[u]]++;
    update(cnt[clr[u]],1);
    for(auto it:g[u])if(it!=v&&it!=hc)
    {
        for(int i=tin[it];i<=tout[it];i++)
        {
            int tmp=clr[odr[i]];
            update(cnt[tmp],-1);
            cnt[tmp]++;
            update(cnt[tmp],1);
        }
    }
    for(auto it:query[u])ans[it.se]=getsum(it.fi);
    if(!kp)
    {
        for(int i=tin[u];i<=tout[u];i++)
        {
            int tmp=clr[odr[i]];
            update(cnt[tmp],-1);
            cnt[tmp]--;
            update(cnt[tmp],1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j,m,u,v,k ;
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> clr[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=m;i++)
    {
        cin >> u >> k ;
        query[u].emplace_back(k,i);
    }
    dfs0(1,0),dfs1(1,0,1);
    for(i=1;i<=m;i++)cout << ans[i] << '\n' ;
}
