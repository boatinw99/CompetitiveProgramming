#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const ll MAX = 1e14 ;
const int N = 2e5+9 , med = 1e5+1 ;
struct line
{
    ll m,c ;
};
line st[N*4];
int n,vst[N*4],sub[N],tin[N],tout[N],times=1,t1=1,sz=2e5,p[N] ;
ll dp[N],a[N],b[N];
vector<int> g[N];
ll f(line a,ll x)
{
    return a.m*x+a.c ;
}
void update(int l,int r,int m,line nw)
{
    if(vst[m]<times)
    {
        vst[m]=times;
        st[m]=nw ;
        return ;
    }
    bool L = f(nw,l-med)<f(st[m],l-med),M = f(nw,mid-med)<f(st[m],mid-med);
    if(M)swap(nw,st[m]);
    if(l==r)return ;
    else if(L!=M)update(l,mid,m<<1,nw);
    else update(mid+1,r,m<<1|1,nw);
}
ll findmin(int l,int r,int pos,int m)
{
    if(vst[m]<times)return MAX ;
    ll ret = f(st[m],pos-med);
    if(l==r)return ret ;
    else if(pos<=mid)return min(ret,findmin(l,mid,pos,m<<1));
    else return min(ret,findmin(mid+1,r,pos,m<<1|1));
}
void dfs0(int u,int v)
{
    tin[u]=++t1;
    p[t1]=u ;
    sub[u]=1;
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it];
    tout[u]=t1;
}
void dfs1(int u,int v,bool kp)
{
    int mx=0,tmp=0 ;
    for(auto it:g[u])if(it!=v&&sub[it]>mx)mx=sub[it],tmp=it ;
    for(auto it:g[u])if(it!=tmp&&it!=v)dfs1(it,u,0);
    if(tmp)dfs1(tmp,u,1);
    for(auto it:g[u])
    {
        if(it!=v&&it!=tmp)
        {
            for(int i=tin[it];i<=tout[it];i++)
            {
                update(1,sz,1,{b[p[i]],dp[p[i]]});
            }
        }
    }
    dp[u]=findmin(1,sz,a[u]+med,1);
    if(g[u].size()==1&&u!=1)dp[u]=0 ;
    update(1,sz,1,{b[u],dp[u]});
    if(!kp)times++;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int u,v ;
    cin >> n ;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i] ;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    memset(dp,-1,sizeof dp);
    dfs0(1,1);
    dfs1(1,1,1);
    for(int i=1;i<=n;i++)cout << dp[i] << " " ;
}
