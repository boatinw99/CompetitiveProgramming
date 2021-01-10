#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 5e5+9 ;
vector<int> g[N];
int st1[N*4],st2[N*4],lazy1[N*4],lazy2[N*4];
int sub[N],pos[N],out[N],ch[N],hd[N],par[N],n,p=0,no=1;
void uplazy(int *f,int *g,int l,int r,int m)
{
    if(f[m])
    {
        g[m]=f[m];
        if(l<r)
        {
            f[m<<1]=f[m];
            f[m<<1|1]=f[m];
        }
        f[m]=0;
    }
}
void update(int *f,int *g,int l,int r,int x,int y,int cst,int m)
{
    uplazy(f,g,l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        g[m]=cst ;
        if(l<r)
        {
            f[m<<1]=cst;
            f[m<<1|1]=cst;
        }
        return ;
    }
    update(f,g,l,mid,x,y,cst,m<<1),update(f,g,mid+1,r,x,y,cst,m<<1|1);
    g[m]=max(g[m<<1],g[m<<1|1]);
}
int findmax(int *f,int *g,int l,int r,int x,int m)
{
    uplazy(f,g,l,r,m);
    if(r<x||l>x)return 0 ;
    if(l==r)return g[m];
    return max(findmax(f,g,l,mid,x,m<<1),findmax(f,g,mid+1,r,x,m<<1|1));
}
void dfs0(int u,int v)
{
    sub[u]=1;
    par[u]=v;
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it];
}
void hld(int u,int v)
{
    int mx=0,hc=0 ;
    if(hd[no]==0)hd[no]=u ;
    ch[u]=no,pos[u]=++p;
    for(auto it:g[u])if(it!=v&&sub[it]>mx)mx=sub[it],hc=it ;
    if(hc)hld(hc,u);
    for(auto it:g[u])if(it!=v&&it!=hc)no++,hld(it,u);
    out[u]=p ;
}
void uphld(int u,int i)
{
    while(u)
    {
        int hx=hd[ch[u]];
        update(lazy1,st1,1,n,pos[hx],pos[u],i,1);
        u=par[hx];
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v,m ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,0),hld(1,0);
    int t ;
    cin >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> t >> u ;
        if(t==1)update(lazy2,st2,1,n,pos[u],out[u],i,1);
        else if(t==2)uphld(u,i);
        else
        {
            int tmp1=findmax(lazy2,st2,1,n,pos[u],1);
            int tmp2=findmax(lazy1,st1,1,n,pos[u],1);
            if(tmp1>tmp2)cout << "1" << '\n' ;
            else cout << "0" << '\n' ;
        }
    }
}
