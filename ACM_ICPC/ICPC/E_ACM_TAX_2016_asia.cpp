#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 1e5+9 , LOG = log2(N)+1 , mxval = 1e5 ; 
vector<pii> g[N] ;
int st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],tin[N],tout[N],root[N];
int depth[N],up[N][LOG],times=0,idx=0;
void init()
{
    for(int i=0;i<N;i++)g[i].clear();
    memset(depth,0,sizeof depth);
    memset(up,0,sizeof up);
    memset(st,0,sizeof st);
    memset(L,0,sizeof L);
    memset(R,0,sizeof R);
    memset(tin,0,sizeof tin);
    memset(tout,0,sizeof tout);
    memset(root,0,sizeof root);
    times = 0 ;
    idx = 1 ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=0 ;
        return ; 
    }
    L[m]=++idx;
    R[m]=++idx;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
    st[m]=0 ;
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m ;
    int nw = ++idx ;
    if(l==r)
    {
        st[nw]=st[m]+1;
        return nw ;
    }
    L[nw]=update(l,mid,x,L[m]);
    R[nw]=update(mid+1,r,x,R[m]);
    st[nw]=st[L[nw]]+st[R[nw]];
    return nw ;
}
int kth(int l,int r,int k,int m1,int m2,int m3)/// u,v,lca -> u+v-2*lca
{
    if(l==r)return l ;
    int suml = st[L[m1]]+st[L[m2]]-2*st[L[m3]];
    if(k<=suml)return kth(l,mid,k,L[m1],L[m2],L[m3]);
    else return kth(mid+1,r,k-suml,R[m1],R[m2],R[m3]);
}
void dfs(int u,int v)
{
    depth[u]=depth[v]+1;
    tin[u]=++times ;
    up[u][0]=v ;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            root[it.fi]=update(1,mxval,it.se,root[u]);
            dfs(it.fi,u);
        }
    }
    tout[u]=++times ; 
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int getlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u][i],v))
        {
            u=up[u][i];
        }
    }
    return up[u][0];
}
float solve(int x,int y)
{
    int lca = getlca(x,y);
    int len = depth[x]+depth[y]-depth[lca]*2;
    //return kth(1,mxval,1,root[x],root[y],root[lca]);
    return 1.0*(kth(1,mxval,(len+1)/2,root[x],root[y],root[lca])+kth(1,mxval,(len+2)/2,root[x],root[y],root[lca]))/2;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ;
    while(T--)
    {
        init();
        int n,m ;
        cin >> n ;
        for(int i=1,u,v,x ;i<n;i++)
        {
            cin >> u >> v >> x ;
            g[u].emplace_back(v,x);
            g[v].emplace_back(u,x);
        }
        dfs(1,1);
        root[1]=1 ;
        construct(1,mxval,1);
        cin >> m ;
        while(m--)
        {
            int u,v ;
            cin >> u >> v ;
            cout << fixed ;
            cout << setprecision(1) << solve(u,v) << '\n' ;
        }
    }
    return 0 ;
}