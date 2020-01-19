#include<bits/stdc++.h>
using namespace std ;
typedef long long ll  ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
const ll MAX = 1e16 ;
int tin[N],tout[N],times=0 ;
int euler[N],pos[N],out[N],weight[N],up[N],sub[N],ch[N],hd[N];
int no=1,p=0,p1=0,n,poshld[N],a[N];
ll f[N],st[N*4],lazy[N*4];
pii edge[N],bedge[N];
vector<pii> g[N];
void updatelazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]+=lazy[m];
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void updateseg(int l,int r,int x,int y,int cst,int m)
{
    int mid=l+r>>1 ;
    updatelazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]+=cst ;
        if(l<r)
        {
            lazy[m<<1]+=cst ;
            lazy[m<<1|1]+=cst ;
        }
        return ;
    }
    updateseg(l,mid,x,y,cst,m<<1),updateseg(mid+1,r,x,y,cst,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
    /// st[]->store MinJumpToRoot;
}
ll findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    updatelazy(l,r,m);
    if(r<x||l>y)return MAX ;
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m<<1),findmin(mid+1,r,x,y,m<<1|1));
}
void update(int i,int cst)
{
    for(;i<=n;i+=i&-i)f[i]+=cst;
}
ll getval(int i)
{
    ll x = 0 ;
    for(;i;i-=i&-i)x+=f[i];
    return x ;
}
void dfs(int u,int cst)
{
    tin[u]=++times ;
    euler[++p]=u; pos[u]=p ; sub[u]=1;
    for(auto it:g[u])dfs(it.fi,it.se),sub[u]+=sub[it.fi];
    out[u]=p ;
    update(pos[u],cst),update(out[u]+1,-cst);
    tout[u]=++times ;
}
void hld(int u)
{
    int tmp=0,mx = 0;
    if(!hd[no])hd[no]=u;
    ch[u]=no,poshld[u]=++p1;
    for(auto it:g[u])if(sub[it.fi]>sub[u])mx=sub[it.fi],tmp=it.fi;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it.fi!=tmp)no++,hld(it.fi);
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
void chwi(int i,int v)
{
    if(i<=n-1)
    {
        int u = edge[i].se;
        update(pos[u],v-weight[i]);
        update(out[u]+1,weight[i]-v);
        updateseg(1,n,pos[u],out[u],v-weight[i],1);
        weight[i]=v;
    }
    else
    {
        i-=n-1;
        int u = bedge[i].fi ;
        updateseg(1,n,pos[u],pos[u],v-a[pos[u]],1);
        a[pos[u]]=v;
    }
}
ll qans(int u,int v)
{
    if(Islca(u,v))return getval(pos[v])-getval(pos[u]);
    return findmin(1,n,pos[u],out[u],1)-getval(pos[u])+getval(pos[v]);
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=getval(l)+a[l];
        return ;
    }
    int mid=l+r>>1 ;
    construct(l,mid,m<<1),construct(mid+1,r,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);;
    int u,v,i,j,T,wi,t ;
    cin >> n >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> wi ;
        edge[i]={u,v}; weight[i]=wi ;
        g[u].emplace_back(v,wi);
    }
    dfs(1,0),hld(1);
    fill(st,st+N*4-1,MAX);
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> wi ;
        bedge[i]={u,wi} ;
        up[u]=i ;
        a[pos[u]]=wi ;
    }
    construct(1,n,1);
    while(T--)
    {
        cin >> t >> u >> v ;
        if(t==1)chwi(u,v) ;
        else cout << qans(u,v) << '\n' ;
    }
}
