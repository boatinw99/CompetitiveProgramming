#include<bits/stdc++.h>
using namespace std ;
const int N = 4e4+9 , M = 1e5+9 ,LOG = log2(N)+1 , sq = sqrt(N<<1);
vector<int> cc;
vector<int> g[N];
int n,m ;
int tin[N],tout[N],id[N<<1],up[N][LOG],a[N],cur=0,depth[N],val[N],ans[M];
bool vst[N];
struct query
{
    int l,r,idx,lca ;
    bool operator < (const query& rhs)
    {
        return (l/sq==rhs.l/sq)?(r<rhs.r):(l/sq<rhs.l/sq);
    }
}Q[M];
void dfs0(int u,int v)
{
    up[u][0]=v;
    depth[u]=depth[v]+1;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    tin[u]=++cur,id[cur]=u;
    for(auto it:g[u])if(it!=v)dfs0(it,u);
    tout[u]=++cur,id[cur]=u;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
void check(int x,int &res)
{
    if(vst[x]&&(--val[a[x]]==0))res--;
    else if(!vst[x]&&(val[a[x]]++==0))res++;
    vst[x]^=1;
}
void solve()
{
    int curl = Q[1].l , curr = Q[1].l-1,res = 0 ;
    for(int i=1;i<=m;i++)
    {
        while(curl<Q[i].l)check(id[curl++],res);
        while(curl>Q[i].l)check(id[--curl],res);
        while(curr<Q[i].r)check(id[++curr],res);
        while(curr>Q[i].r)check(id[curr--],res);
        int u = id[curl],v=id[curr];
        if(Q[i].lca!=u&&Q[i].lca!=v)check(Q[i].lca,res);
        ans[Q[i].idx]=res;
        if(Q[i].lca!=u&&Q[i].lca!=v)check(Q[i].lca,res);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cc.push_back(a[i]);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(cc.begin(),cc.end(),a[i])-cc.begin()+1;
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v ;
        Q[i].lca=findlca(u,v);
        if(tin[u]>tin[v])swap(u,v);
        if(Q[i].lca==u)Q[i].l=tin[u],Q[i].r=tin[v];
        else Q[i].l=tout[u],Q[i].r=tin[v];
        Q[i].idx=i;
    }
    sort(Q+1,Q+1+m);
    solve();
    for(int i=1;i<=m;i++)cout << ans[i] << '\n' ;
    return 0 ;
}
