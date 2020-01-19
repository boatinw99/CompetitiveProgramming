#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1;
int st[N*LOG*4],L[N*LOG*4],R[N*LOG*4],root[N],pos[N];
int n,id=1;
pii edge[N];
vector<pii> g[N];
void re()
{
    id=1;
    for(int i=1;i<N;i++)g[i].clear();
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=0 ;
        return ;
    }
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
    st[m]=0;
}
int update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return m ;
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=cst ;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,cst,L[m]);
    R[tmp]=update(mid+1,r,x,cst,R[m]);
    st[tmp]=st[L[tmp]]^st[R[tmp]];
    return tmp ;
}
int findxor(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return findxor(l,mid,x,y,L[m])^findxor(mid+1,r,x,y,R[m]);
}
void dfs(int u,int v)
{
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            int tmp = pos[it.se];
            root[it.fi]=update(1,n,tmp,edge[tmp].fi,root[u]);
            dfs(it.fi,u);
        }
    }
}
int qans(int u,int v,int x)
{
    int tmp = upper_bound(edge+1,edge+n,make_pair(x,INT_MAX))-edge-1;
    return findxor(1,n,1,tmp,root[u])^findxor(1,n,1,tmp,root[v]);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T,i,j,m,u,v,x ;
    cin >> T ;
    while(T--)
    {
        re();
        cin >> n;
        for(i=1;i<n;i++)
        {
            cin >> u >> v >> x ;
            edge[i]={x,i};
            g[u].emplace_back(v,i);
            g[v].emplace_back(u,i);
        }
        sort(edge+1,edge+n);
        for(i=1;i<n;i++)pos[edge[i].se]=i;
        root[1]=1;
        construct(1,n,1);
        dfs(1,0);
        cin >> m ;
        while(m--)
        {
            cin >> u >> v >> x ;
            cout << qans(u,v,x) << '\n' ;
        }
    }
}
