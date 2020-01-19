#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N)+1;
struct Q
{
    int U,V,K,K1,K2 ;
};
vector<Q> query;
vector<int> g[N];
int st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],root[N];
int ti[N],up[N][LOG],tin[N],tout[N],depth[N],times=0;
int m,id=1 ;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m ;
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=1;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,L[m]);
    R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
int findsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return findsum(l,mid,x,y,L[m])+findsum(mid+1,r,x,y,R[m]);
}
void dfs(int u)
{
    depth[u]=depth[up[u][0]]+1;
    root[u]=root[up[u][0]];
    tin[u]=++times;
    if(ti[u])root[u]=update(1,m,ti[u],root[u]);
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])dfs(it);
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0];
}
int findans(int u,int v,int k,int l,int r)
{
    int uu=u,pu=up[u][0],su=findsum(1,m,l,r,root[pu]);
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))
        {
            int x=up[u][i],y=up[x][0];
            int tmp=su-findsum(1,m,l,r,root[y]);
            int sum = depth[uu]-depth[x]-tmp ;
            if(sum<k)u=x;
        }
    }
    int ans = up[u][0];
    if(ans==v)return -1 ;
    return ans ;
}
int findansinv(int u,int v,int k,int l,int r)
{
    int uu=u,sv=findsum(1,m,l,r,root[v]) ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))
        {
            int x=up[u][i];
            int tmp = findsum(1,m,l,r,root[x])-sv;
            int sum = depth[x]-depth[v]-tmp ;
            if(sum>k-1)u=x ;
        }
    }
    if(u==uu)return -1;
    return u ;
}
int qans(int u,int v,int k,int l,int r)
{
    if(Islca(v,u))return findans(u,v,k,l,r);
    if(Islca(u,v))return findansinv(v,u,k,l,r);
    int lca=findlca(u,v);
    int t1=up[lca][0];
    int tmp = findsum(1,m,l,r,root[up[u][0]])-findsum(1,m,l,r,root[t1]);
    int sum = depth[u]-depth[lca]-tmp;
    if(sum>=k)return findans(u,t1,k,l,r);
    return findansinv(v,lca,k-sum,l,r);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,t,u,v,k,y ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> up[i][0];
        g[up[i][0]].emplace_back(i);
    }
    ///Online
    cin >> m ;
    root[0]=1;
    construct(1,m,1);
    for(i=1;i<=m;i++)
    {
        cin >> t ;
        if(t==1)
        {
            cin >> u ;
            ti[u]=i;
        }
        else
        {
            cin >> u >> v >> k >> y ;
            query.push_back({u,v,k,y+1,i});
        }
    }
    dfs(0);
    for(auto it:query)cout << qans(it.U,it.V,it.K,it.K1,it.K2) << '\n' ;
}
