#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1;
int a[N],pseg[N],tin[N],tout[N],up[N][LOG],pos[N];
int st[N*LOG+N*4],L[N*LOG+N*4],R[N*LOG+N*4],root[N];
int n,id=1,p=1,times=0;
vector<int> g[N];
vector<pii> sortv ;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=1;
        return tmp ;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,L[m]);
    else R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp ;
}
void dfs(int u,int v)
{
    tin[u]=++times ;
    up[u][0]=v;
    root[p]=update(1,n,pos[u],root[pseg[v]]);
    pseg[u]=p++;
    for(int i=1;i<LOG;i++)up[u][i]=up[up[u][i-1]][i-1];
    for(auto it:g[u])if(it!=v)dfs(it,u);
    tout[u]=++times ;
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
int qans(int l,int r,int m1,int m2,int m3,int m4,int k)
{
    if(l==r)return l ;
    int tmp = st[L[m1]]+st[L[m2]]-st[L[m3]]-st[L[m4]];
    int mid=l+r>>1 ;
    if(tmp>=k)return qans(l,mid,L[m1],L[m2],L[m3],L[m4],k);
    else return qans(mid+1,r,R[m1],R[m2],R[m3],R[m4],k-tmp);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v,k ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        sortv.push_back({a[i],i});
    }
    sort(sortv.begin(),sortv.end());
    i=1;
    for(auto it:sortv)pos[it.se]=i++;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    root[0]=1;
    construct(1,n,1);
    tout[0]=INT_MAX ;
    dfs(1,0);
    while(m--)
    {
        cin >> u >> v >> k ;
        int lca = findlca(u,v);
        cout << sortv[qans(1,n,root[pseg[u]],root[pseg[v]],
                root[pseg[lca]],root[pseg[up[lca][0]]],k)-1].fi << '\n';
    }
}
