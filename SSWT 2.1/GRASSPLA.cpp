#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
int depth[N],sub[N],hd[N],ch[N],par[N],pos[N];
int n,p=0,no=1;
ll lazy[N*4],st[N*4] ;
vector<int> g[N];
void dfs(int u,int v)
{
    par[u]=v,sub[u]=1,depth[u]=depth[v]+1 ;
    for(auto it:g[u])if(it!=v)dfs(it,u),sub[u]+=sub[it];
}
void hld(int u)
{
    int tmp=0,mx=0;
    if(hd[no]==0)hd[no]=u ;
    ch[u]=no,pos[u]=++p ;
    for(auto it:g[u])if(it!=par[u]&&sub[it]>mx)mx=sub[it],tmp=it ;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it!=par[u]&&it!=tmp)no++,hld(it) ;
}
void uplazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m]+=lazy[m]*(r-l+1);
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void update(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]+=(r-l+1) ;
        if(l<r)
        {
            lazy[m<<1]++;
            lazy[m<<1|1]++;
        }
        return ;
    }
    int mid=l+r>>1 ;
    update(l,mid,x,y,m<<1),update(mid+1,r,x,y,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
ll findsum(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m] ;
    int mid=l+r>>1;
    return findsum(l,mid,x,y,m<<1)+findsum(mid+1,r,x,y,m<<1|1);
}
void uphld(int u,int v)
{
    while(ch[u]!=ch[v])
    {
        int hx=hd[ch[u]],hy=hd[ch[v]];
        if(depth[hx]>=depth[hy])
        {
            update(1,n,pos[hx],pos[u],1);
            u=par[hx];
        }
        else
        {
            update(1,n,pos[hy],pos[v],1);
            v=par[hy];
        }
    }
    if(u==v)return ;
    if(depth[u]>depth[v])swap(u,v);
    update(1,n,pos[u]+1,pos[v],1);
}
ll qans(int u,int v)
{
    ll ans = 0;
    while(ch[u]!=ch[v])
    {
        int hx=hd[ch[u]],hy=hd[ch[v]];
        if(depth[hx]>=depth[hy])
        {
            ans+=findsum(1,n,pos[hx],pos[u],1);
            u=par[hx];
        }
        else
        {
            ans+=findsum(1,n,pos[hy],pos[v],1);
            v=par[hy];
        }
    }
    if(u==v)return ans;
    if(depth[u]>depth[v])swap(u,v);
    return ans+findsum(1,n,pos[u]+1,pos[v],1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T,i,j,u,v  ;
    char c ;
    cin >> n >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1),hld(1);
    while(T--)
    {
        cin >> c >> u >> v ;
        if(c=='P')uphld(u,v);
        else cout << qans(u,v) << '\n' ;
    }
}
