#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9,LOG=log2(N)+1,inf=2e9 ;
priority_queue<pair<int,pii> > pq ;
bool visited[N],nonmst[N];
int edge[N][3];
int lazy[N*4],st[N*4];
int up[N][LOG],MAX[N][LOG],tin[N],tout[N],times=0;
int sub[N],par[N],hd[N],ch[N],depth[N],pos[N],pathhld[N],ans[N];
int n,p=0,no=1;
vector<pii> g[N],mst[N];
vector<int> nmst;
void dfs(int u,int v)
{
    sub[u]=1; depth[u]=depth[v]+1; par[u]=v ;
    up[u][0]=v; tin[u]=++times;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        MAX[u][i]=max(MAX[u][i-1],MAX[up[u][i-1]][i-1]);
    }
    for(auto it:mst[u])if(it.fi!=v)
        MAX[it.fi][0]=edge[it.se][2]-1,dfs(it.fi,u),sub[u]+=sub[it.fi];
    tout[u]=++times ;
}
void hld(int u)
{
    int tmp=0,mx =0 ;
    if(!hd[no])hd[no]=u;
    ch[u]=no; pos[u]=++p; pathhld[p]=u ;
    for(auto it:mst[u])if(it.fi!=par[u]&&mx<sub[it.fi])
        mx=sub[it.fi],tmp=it.fi ;
    if(tmp)hld(tmp);
    for(auto it:mst[u])if(it.fi!=par[u]&&it.fi!=tmp)no++,hld(it.fi);
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
void uplazy(int l,int r,int m)
{
    if(lazy[m]<inf)
    {
        st[m]=min(st[m],lazy[m]);
        if(l<r)
        {
            lazy[m<<1]=min(lazy[m],lazy[m<<1]);
            lazy[m<<1|1]=min(lazy[m],lazy[m<<1|1]);
        }
        lazy[m]=inf;
    }
}
void update(int l,int r,int x,int y,int cst,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]=min(st[m],cst);
        if(l<r)
        {
            lazy[m<<1]=min(lazy[m<<1],cst);
            lazy[m<<1|1]=min(lazy[m<<1|1],cst);
        }
        return ;
    }
    int mid=l+r>>1;
    update(l,mid,x,y,cst,m<<1),update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int findmin(int l,int r,int x,int m)
{
    uplazy(l,r,m);
    if(r<x||l>x)return inf ;
    if(l==x&&r==x)return st[m];
    int mid=l+r>>1;
    return min(findmin(l,mid,x,m<<1),findmin(mid+1,r,x,m<<1|1));
}
void uphld(int u,int v,int cst)
{
    while(ch[u]!=ch[v])
    {
        update(1,n,pos[hd[ch[u]]],pos[u],cst,1);
        u=par[hd[ch[u]]];
    }
    if(u==v)return ;
    update(1,n,min(pos[u],pos[v]+1),max(pos[u],pos[v]+1),cst,1);
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u;
    if(Islca(v,u))return v;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int lift(int u,int cst)
{
    int mx = 0 ;
    for(int i=0;i<LOG;i++)if((1<<i)&cst)mx=max(mx,MAX[u][i]),u=up[u][i];
    return mx ;
}
int findout(int i)
{
    int u=edge[i][0],v=edge[i][1],cst=edge[i][2] ;
    int lca=findlca(u,v);
    uphld(u,lca,cst-1),uphld(v,lca,cst-1);
    return max(lift(u,depth[u]-depth[lca]),lift(v,depth[v]-depth[lca]));
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v,cst ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> cst ;
        edge[i][0]=u,edge[i][1]=v,edge[i][2]=cst ;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    ///create mst
    edge[0][0]=1,edge[0][1]=1,edge[0][2]=0;
    for(pq.push({0,{1,0}});!pq.empty();)
    {
        i=pq.top().se.se,cst=pq.top().fi*-1;
        u = pq.top().se.fi,v=edge[i][0] ;
        if(v==u)v=edge[i][1];
        pq.pop();
        if(!visited[u]++)
        {
            mst[u].emplace_back(v,i);
            mst[v].emplace_back(u,i);
            for(auto it:g[u])if(!visited[it.fi])
                pq.push({-edge[it.se][2],{it.fi,it.se}});
        }
        else nmst.emplace_back(i);
    }
    ///
    dfs(1,1),hld(1);
    fill(lazy,lazy+N*4,inf);
    fill(st,st+N*4,inf);
    for(auto it:nmst)ans[it]=findout(it),nonmst[it]=1;
    for(i=1;i<=m;i++)if(!nonmst[i])
        ans[i]=findmin(1,n,max(pos[edge[i][0]],pos[edge[i][1]]),1);
    for(i=1;i<=m;i++)
    {
        if(ans[i]<inf)cout << ans[i] << " " ;
        else cout << -1 << " " ;
    }

}
