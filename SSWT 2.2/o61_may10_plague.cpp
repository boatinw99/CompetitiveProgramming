#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 , LOG = log2(N)+2;
vector<int> g[N];
int st[N*LOG*20],L[N*LOG*20],R[N*LOG*20];
int dist[N][LOG],sub[N],par[N],rnk[N],root1[N],root2[N],sz[N];
bool vst[N];
int n,id=1;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id ;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m ;
    int tmp = ++id ;
    if(l==r)
    {
        st[tmp]=st[m]+1;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m] ;
    return getsum(l,mid,x,y,L[m])+getsum(mid+1,r,x,y,R[m]);
}
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
    vst[u]++;
    dist[u][rnk[u]-depth]=cst;
    for(auto it:g[u])if(!vst[it])dfs3(it,depth,cst+1);
    vst[u]=0;
}
void dcp(int u,int v,int depth,int size)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    rnk[ctd]=depth;
    par[ctd]=v;
    sz[ctd]=size;
    vst[ctd]++;
    for(auto it:g[ctd])if(!vst[it])dcp(it,ctd,depth+1,size>>1);
    dfs3(ctd,depth,0);
}
void plague(int u,int k)
{
    int x = u ;
    while(u)
    {
        if(k-dist[x][rnk[x]-rnk[u]]>=0)
            root1[u]=update(0,sz[u],min(k-dist[x][rnk[x]-rnk[u]],sz[u]),root1[u]);
        if(k-dist[x][rnk[x]-rnk[u]+1]>=0)
            root2[u]=update(0,sz[par[u]],min(sz[par[u]],k-dist[x][rnk[x]-rnk[u]+1]),root2[u]);
        u=par[u];
    }
}
int qans(int u)
{
    int x=u,pre=0,ans=0;
    while(u)
    {
        ans+=getsum(0,sz[u],dist[x][rnk[x]-rnk[u]],sz[u],root1[u])-pre;
        pre=getsum(0,sz[par[u]],dist[x][rnk[x]-rnk[u]+1],sz[par[u]],root2[u]);
        u=par[u];
    }
    return ans ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v,k,typ ;
    cin >> n >> m ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dcp(1,0,1,n/2);
    for(i=0;i<=n;i++)root1[i]=root2[i]=1 ;
    construct(0,n,1);
    while(m--)
    {
        cin >> typ ;
        if(typ==1)
        {
            cin >> u >> k ;
            plague(u,k);
        }
        else
        {
            cin >> u ;
            cout << qans(u) << '\n' ;
        }
    }
}
