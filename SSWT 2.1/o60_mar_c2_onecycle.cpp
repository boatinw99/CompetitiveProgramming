#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1 ;
int tin[N],tout[N],par[N],rnk[N],times=0;
int up[N][LOG],dist[N];
vector<pair<int,pii> > edge,nontree;
vector<pii> g[N];
vector<pair<pii,int> > ans;
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py)return 0 ;
    if(rnk[px]>=rnk[py])rnk[px]+=rnk[py],par[py]=px;
    else rnk[py]+=rnk[px],par[px]=py;
    return 1 ;
}
void dfs(int u,int v)
{
    up[u][0]=v;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    tin[u]=++times;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dist[it.fi]=dist[u]+it.se;
            dfs(it.fi,u);
        }
    }
    tout[u]=++times;
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
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v,x ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            {
                cin >> x ;
                if(i<j)
                {
                    edge.push_back({x,{i,j}});
                }
            }
        }
        par[i]=i;
    }
    sort(edge.begin(),edge.end());
    for(auto it:edge)
    {
        if(Union(it.se.fi,it.se.se))
        {
            g[it.se.fi].emplace_back(it.se.se,it.fi);
            g[it.se.se].emplace_back(it.se.fi,it.fi);
            ans.push_back({{it.se.fi,it.se.se},it.fi});
        }
        else nontree.push_back({it.fi,{it.se.fi,it.se.se}});
    }
    tout[0]=INT_MAX;
    dfs(1,0);
    for(auto it:nontree)
    {
        int lca=findlca(it.se.fi,it.se.se);
        if(dist[it.se.fi]+dist[it.se.se]-2*dist[lca]!=it.fi)
        {
            ans.push_back({{it.se.fi,it.se.se},it.fi});
            break;
        }
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout << it.fi.fi << " " << it.fi.se << " " << it.se << '\n' ;
    }
}
