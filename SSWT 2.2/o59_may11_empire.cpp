#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 ,inf =1e9 ;
vector<int> g[N];
int pos[N],hd[N],ch[N],depth[N],len,cycle[N],sub[N],par[N],no=1,p=1,sum=1;
int lazy[N<<2],st[N<<2],bedge=0,n;
bool vst[N];
void push(int l,int r,int m)
{
    if(lazy[m]!=inf)
    {
        st[m]=(r-l+1)*lazy[m];
        if(l<r)
        {
            lazy[m<<1]=lazy[m];
            lazy[m<<1|1]=lazy[m];
        }
        lazy[m]=inf ;
    }
}
void update(int l,int r,int x,int y,int cst,int m)
{
    push(l,r,m);
    if(r<x||l>y||x>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]=cst*(r-l+1);
        if(l<r)
        {
            lazy[m<<1]=cst ;
            lazy[m<<1|1]=cst ;
        }
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,x,y,m<<1)+getsum(mid+1,r,x,y,m<<1|1);
}
int dfs0(int u,int v)
{
    vst[u]++;
    depth[u]=depth[v]+1;
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            int ret = dfs0(it,u);
            if(ret)return ret ;
        }
        else if(it!=v)
        {
            len=depth[u]-depth[it]+1;
            return it;
        }
    }
    return 0 ;
}
int dfs1(int u,int v)
{
    vst[u]++;
    sub[u]=1;
    par[u]=v;
    depth[u]=depth[v]+1;
    int ret = 0 ;
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            ret=max(ret,dfs1(it,u));
            sub[u]+=sub[it];
        }
        else if(it!=v)ret=1 ;
    }
    cycle[u]=ret ;
    return ret ;
}
void hld(int u)
{
    vst[u]++;
    if(!hd[no])hd[no]=u ;
    ch[u]=no,pos[u]=p++;
    if(cycle[u])
    {
        for(auto it:g[u])if(!vst[it]&&cycle[it])hld(it);
        for(auto it:g[u])if(!vst[it]&&!cycle[it])no++,hld(it);
        return ;
    }
    int mx=0,tmp=0;
    for(auto it:g[u])if(!vst[it]&&sub[it]>mx)mx=sub[it],tmp=it ;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(!vst[it]&&it!=tmp)no++,hld(it);
}
void query(int u,int v,int x)
{
    while(ch[u]!=ch[v])
    {
        if(depth[hd[ch[u]]]<depth[hd[ch[v]]])swap(u,v);
        int pu=hd[ch[u]];
        update(1,n,pos[pu],pos[u],x,1);
        u=par[pu];
    }
    if(depth[u]>depth[v])swap(u,v);
    if(u==v)return ;
    if(ch[u]>1)update(1,n,pos[u]+1,pos[v],x,1);
    else
    {
        if(pos[v]-pos[u]<pos[u]+len-pos[v])
        {
            update(1,n,pos[u]+1,pos[v],x,1);
        }
        else if(pos[v]-pos[u]>pos[u]+len-pos[v])
        {
            bedge=x ;
            update(1,n,2,pos[u],x,1);
            update(1,n,pos[v]+1,len,x,1);
        }
        else
        {
            bedge = x ; ///1 -> cut
            update(1,n,2,len,x,1);
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v,x ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int root = dfs0(1,0);
    fill(lazy,lazy+N*4-1,inf);
    memset(vst,0,sizeof vst);
    memset(depth,0,sizeof depth);
    dfs1(root,root);
    memset(vst,0,sizeof vst);
    hld(root);
    while(m--)
    {
        cin >> u >> v >> x ;
        x^=1;
        if(u!=v)query(u,v,x);
        int add=0 ;
        if((bedge^1)&&getsum(1,n,1,len,1)!=0)add++;
        cout << st[1]+1-add << '\n' ;
    }
}
