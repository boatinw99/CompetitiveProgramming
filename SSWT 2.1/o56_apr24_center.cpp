#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
const ll MAX = 1e18 ;
const int N = 1e5+9,LOG = log(N)+1 ;
vector<int> g[N];
vector<pair<int,ll> > vec ; ///m+c
int p[N],dist[N][LOG];
ll ans=0;
int rnk[N],par[N],sub[N];
bool vst[N];
struct cht
{
    struct line
    {
        ll m,c ;
        line(ll m,ll c):m(m),c(c) {}
        ll f(ll x)
        {
            return m*x+c;
        }
    };
    vector<line> l;
    bool bad(line a,line b,line c)
    {
        return 1.0*(c.c-a.c)/(a.m-c.m)<=1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(ll m,ll c)
    {
        line now(m,c);
        if(!l.empty()&&now.m==l.back().m&&now.c<=l.back().c)l.pop_back();
        while(l.size()>1&&bad(l[l.size()-2],l.back(),now))l.pop_back();
        l.emplace_back(now);
    }
    ll query(ll x)
    {
        if(l.empty())return MAX ;
        int L=0,R=l.size()-1;
        while(L<R)
        {
            int mid=L+R>>1;
            if(l[mid].f(x)<l[mid+1].f(x))R=mid;
            else L=mid+1;
        }
        return l[R].f(x);
    }

}hull[N];
void dfs1(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])if(!vst[it])dfs1(it),sub[u]+=sub[it];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&!vst[it]&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int depth,int cst)
{
    dist[u][rnk[u]-depth]=cst ;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs3(it,depth,cst+1);
    vst[u]=0;
}
void dfs4(int u,int cst)
{
    if(p[u])vec.push_back({p[u],1ll*p[u]*cst});
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs4(it,cst+1);
    vst[u]=0 ;
}
void clearvec(int u)
{
    sort(vec.begin(),vec.end(),greater<pair<int,ll> >());
    for(auto it:vec)hull[u].add(it.fi,it.se);
    vec.clear();
}
void dcp(int u,int v,int depth)
{
    dfs1(u);
    int ctd = dfs2(u,v,sub[u]);
    vst[ctd]++;
    par[ctd]=v;
    rnk[ctd]=depth;
    for(auto it:g[ctd])if(!vst[it])dcp(it,ctd,depth+1);
    dfs3(ctd,depth,0);
    ///
    dfs4(ctd,0);
    clearvec(ctd);
    ///
}
ll getmax(int u)
{
    ll mn = MAX ;
    int x = u ;
    while(u)
    {
        mn=min(mn,hull[u].query(dist[x][rnk[x]-rnk[u]]));
        u=par[u];
    }
    return mn;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,n,k,u,v ;
    cin >> n >> k ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=k;i++)
    {
        cin >> u  ;
        cin >> p[u];
    }
    dcp(1,0,0);
    for(i=1;i<=n;i++)
    {
        ll ret = getmax(i);
        ans=max(ans,ret);
    }
    cout << ans ;
}
