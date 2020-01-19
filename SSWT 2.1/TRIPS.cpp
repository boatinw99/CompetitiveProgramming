#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1,SQ=sqrt(N)+1 ;
int up[N][LOG],tin[N],tout[N],times=0,sq ;
int jump[N][LOG];
int depth[N],dist[N],ans[N];
int fijump[N][SQ]; /// fi -> first
vector<pii> g[N];
vector<pair<pii,pii> > query ;
void dfs(int u,int v)
{
    up[u][0]=v;
    for(int i=2,cnt=0,p=u;i<=sq;i++)
    {
        while(cnt+dist[p]-dist[up[p][0]]<=i&&p!=1)
        {
            cnt+=dist[p]-dist[up[p][0]];
            p=up[p][0];
        }
        fijump[u][i]=p ;
    }
    for(int i=1;i<LOG;i++) up[u][i]=up[up[u][i-1]][i-1];
    tin[u]=++times;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dist[it.fi]=dist[u]+it.se ;
            dfs(it.fi,u);
        }
    }
    tout[u]=++times ;
}
void dfschge(int u,int p)
{
    jump[u][0]=fijump[u][p];
    for(int i=1;i<LOG;i++)jump[u][i]=jump[jump[u][i-1]][i-1];
    for(auto it:g[u])if(it.fi!=up[u][0])dfschge(it.fi,p);
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int lifting(int u,int p)
{
    for(int i=LOG-1;i>=0;i--)
    {
        int tmp=up[u][i];
        if(dist[u]-dist[tmp]<=p)
        {
            p-=dist[u]-dist[tmp];
            u=tmp;
        }
    }
    return u ;
}
pii uplift(int u,int lca,int p)
{
    /// depth[lca] < depth[u]
    int cnt = 0;
    while(dist[u]-dist[lca]>p)
    {
        u=lifting(u,p);
        cnt++;
    }
    return {cnt,dist[u]-dist[lca]};
}
pii lowlift(int u,int lca)
{
    int cnt=0 ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(jump[u][i],lca))
        {
            u=jump[u][i];
            cnt+=(1<<i);
        }
    }
    return {cnt,dist[u]-dist[lca]};
}
int upperq(int u,int v,int p)
{
    int lca=findlca(u,v);
    pii l=uplift(u,lca,p),r=uplift(v,lca,p);
    return l.fi+r.fi+(l.se+r.se)/(p+1);
}
int lowerq(int u,int v,int p)
{
    int lca=findlca(u,v);
    pii l=lowlift(u,lca),r=lowlift(v,lca);
    return l.fi+r.fi+(l.se+r.se)/(p+1);
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,i,j,u,v,d,T,p ;
    cin >> n ;
    sq = sqrt(n);
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> d ;
        g[u].emplace_back(v,d);
        g[v].emplace_back(u,d);
    }
    dfs(1,1);
    cin >> T ;
    for(i=0;i<T;i++)
    {
        cin >> u >> v >> p ;
        query.push_back({{p,i},{u,v}});
    }
    sort(query.begin(),query.end());
    int l=0 ;
    for(auto it:query)
    {
        p=it.fi.fi; u = it.se.fi , v=it.se.se ; i = it.fi.se;
        if(p>sq)ans[i]=upperq(u,v,p)+1;
        else
        {
            if(l!=p)l=p,dfschge(1,l);
            ans[i]=lowerq(u,v,p)+1;
        }
    }
    for(i=0;i<T;i++)cout << ans[i] << '\n';
}
