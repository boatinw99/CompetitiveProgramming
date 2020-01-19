#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e5+9,inf = 2e9 ;
vector<pii> g[N],gt[N];
vector<int> Q[N];
int edge[N],st[N<<2],n,ty[N];
bool vst[N];
pii query[N];
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=edge[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int x,int y,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=y ;
        return ;
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int getmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y||l>r)return inf ;
    if(l>=x&&r<=y)return st[m];
    return min(getmin(l,mid,x,y,m<<1),getmin(mid+1,r,x,y,m<<1|1));
}
int brute_force(int u,int v,int x)
{
    vst[u]=1;
    int ret = 1 ;
    for(auto it:g[u])
    {
        if(!vst[it.fi]&&edge[it.se]>=x)
        {
            ret+=brute_force(it.fi,u,x);
        }
    }
    return ret ;
}
int getl(int u,int v)
{
    int l = 0 ,r=u;
    while(l+1<r)
    {
        int mn = getmin(1,n-1,mid,u-1,1);
        if(mn>=v)r=mid;
        else l=mid;
    }
    return r ;
}
int getr(int u,int v)
{
    int l=u,r=n+1;
    while(l+1<r)
    {
        int mn = getmin(1,n-1,u,mid-1,1);
        if(mn>=v)l=mid;
        else r=mid ;
    }
    return l ;
}
int chain(int u,int v)
{
    int lmost = getl(u,v);
    int rmost = getr(u,v);
    return rmost-lmost+1;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,q ;
    cin >> n >> m ;
    for(int i=1;i<=m;i++)
    {
        int u,v,x ;
        cin >> u >> v >> x ;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
        edge[i]=x;
    }
    cin >> q ;
    if(m*q<=40000000)
    {
        while(q--)
        {
            for(int i=1;i<=n;i++)vst[i]=0;
            int typ,u,v ;
            cin >> typ >> u >> v ;
            if(typ==1)edge[u]=v;
            else cout << brute_force(u,u,v) << '\n' ;
        }
        return 0 ;
    }
    bool tyq = 0 ;
    for(int i=1;i<=q;i++)
    {
        cin >> ty[i] >> query[i].fi >> query[i].se ;
        if(ty[i]==1)tyq=1;
    }/*
    if( tyq==0)
    {
        for(int i=1;i<=q;i++)
        {
            Q[query[i].fi].emplace_back(query[i].se,i);
        }
        dfs0(1,1);
        sack(1);
        for(int i=1;i<=q;i++)cout << ans[i] << '\n' ;
        return 0 ;
    }*/
    construct(1,n-1,1);
    for(int i=1;i<=q;i++)
    {
        int typ = ty[i],u=query[i].fi,v=query[i].se;
        if(typ==1)update(1,n-1,u,v,1);
        else cout << chain(u,v) << '\n' ;
    }
    return 0 ;
}
