#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 3e4+9 , K = 20 ,LOG = log2(N)+1;
ll cnt[N],dist[N][LOG],sum1[N][K],sum2[N][K],num[N][K],cc[K];
///sum1 -> count sum in sub ;
///sum2 -> count sum for par ;
///num -> number in that sub ;
int a[N],par[N],sub[N],rnk[N];
bool vst[N];
vector<pair<int,ll> > g[N];
void dfs1(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])if(!vst[it.fi])dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0 ;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it.fi!=v&&!vst[it.fi]&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,int depth,ll cst)
{
    vst[u]++;
    dist[u][rnk[u]-depth]=cst;
    for(auto it:g[u])if(!vst[it.fi])dfs3(it.fi,depth,cst+it.se) ;
    vst[u]=0;
}
void dcp(int u,int v,int depth)
{
    dfs1(u);
    int ctd = dfs2(u,v,sub[u]);
    rnk[ctd]=depth;
    par[ctd]=v;
    vst[ctd]++;
    for(auto it:g[ctd])if(!vst[it.fi])dcp(it.fi,ctd,depth+1);
    dfs3(ctd,depth,0);
    vst[ctd]=0 ;
}
void getans(int u,int mul)
{
    ll psum=0,pnum=0;
    int clr=a[u],x=u;
    while(u)
    {
        cnt[clr]+=mul*((dist[x][rnk[x]-rnk[u]])*(num[u][clr]-pnum)
                       +sum1[u][clr]-psum);
        pnum=num[u][clr];
        psum=sum2[u][clr];
        u=par[u];
    }
}
void update(int u,int cst)
{
    int clr=a[u],x=u ;
    while(u)
    {
        num[u][clr]+=cst;
        sum1[u][clr]+=cst*dist[x][rnk[x]-rnk[u]];
        sum2[u][clr]+=cst*dist[x][rnk[x]-rnk[u]+1];
        u=par[u];
    }
    cc[clr]+=cst;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,k,u,v,typ ;
    ll x ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    dcp(1,0,0);
    for(i=1;i<=n;i++)
    {
        getans(i,1);
        update(i,1);
    }
    cin >> m ;
    while(m--)
    {
        cin >> typ ;
        if(typ==1)
        {
            cin >> u ;
            ///printf("aaa %lld %d\n",cnt[u],cc[u]);
            double ans = (cc[u]>1?1.0*cnt[u]/(cc[u]*(cc[u]-1)/2):0);
            printf("%.12lf\n",ans);
        }
        else
        {
            cin >> u >> v ;
            update(u,-1);
            getans(u,-1);
            a[u]=v;
            getans(u,1);
            update(u,1);
        }
    }
}
