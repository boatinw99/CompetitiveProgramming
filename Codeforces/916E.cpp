#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N)+1;
typedef long long ll ;
vector<int>G[N];
ll st[N*4],lazy[N*4],pa[N],a[N],val;
int up[N][LOG];
int newt[N],pin[N],pout[N],tin[N],tout[N],depth[N];
int n,root=1,p=1,x,y,times=0;
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)st[m]=pa[l];
    else
    {
        construct(l,mid,m<<1); construct(mid+1,r,m<<1|1);
        st[m]=st[m<<1]+st[m<<1|1];
    }
}
void update(int l,int r,int m)
{
    int mid=l+r>>1;
    if(lazy[m])
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l<r)lazy[m<<1]+=lazy[m],lazy[m<<1|1]+=lazy[m];
        lazy[m]=0;
    }
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]+=val*(r-l+1);
        if(l<r)lazy[m<<1]+=val,lazy[m<<1|1]+=val;
        return ;
    }
    update(l,mid,m<<1); update(mid+1,r,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
ll findans(int l,int r,int m)
{
    int mid=l+r>>1;
    if(lazy[m])
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l<r)lazy[m<<1]+=lazy[m],lazy[m<<1|1]+=lazy[m];
        lazy[m]=0;
    }
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return findans(l,mid,m<<1)+findans(mid+1,r,m<<1|1);
}
void dfs(int u,int v)
{
    tin[u]=++times; up[u][0]=v; depth[u]=depth[v]+1;
    pa[p]=a[u]; pin[u]=pout[u]=p; newt[p++]=u ;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:G[u])if(it!=v){
        dfs(it,u); pout[u]=max(pout[u],pout[it]);
    }
    tout[u]=++times;
}
bool Islca(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v]; }
int nth(int u,int cnt)
{
    if(!cnt)return u ;
    for(int i=0;i<LOG;i++)if((1<<i)&cnt)u=up[u][i];
    return u ;
}
int findlca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
void in(int u,int v)
{
    int lca=0,d ;
    if(Islca(u,v))lca=u;
    else if(Islca(v,u))lca=v;
    else lca=findlca(u,v);
    if(depth[u]>depth[v])swap(u,v);
    if(Islca(lca,root)&&(Islca(root,u)||Islca(root,v)))
            x=1,y=n,update(1,n,1);
    else if(Islca(lca,root))
    {
        x=1; y=n; update(1,n,1); d=root;
        for(int i=LOG-1;i>=0;i--)
            if(!Islca(up[d][i],u)&&!Islca(up[d][i],v)
               &&!Islca(up[d][i],lca))d=up[d][i];
        x=pin[d]; y=pout[d]; val*=-1;
        update(1,n,1);
    }
    else x=pin[lca],y=pout[lca],update(1,n,1);
}
ll qans(int u)
{
    int lca ;
    if(u==root)return st[1];
    if(Islca(u,root))
    {
        lca = nth(root,depth[root]-depth[u]-1);
        x=pin[lca]; y=pout[lca];
        return st[1]-findans(1,n,1);
    }
    x=pin[u]; y=pout[u] ;
    return findans(1,n,1);
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,u,v,T,t ;
    cin >> n  >> T ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1,1); construct(1,n,1);
    while(T--)
    {
        cin >> t ;
        if(t==1)cin >> root ;
        else if(t==2)cin >> u >> v >> val,in(u,v);
        else cin >> u,cout <<qans(u)<<'\n';
    }
}
