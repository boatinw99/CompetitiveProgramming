#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ,INF = 2e9 ;
int sub[N],par[N],a[N],depth[N],lazy[N*4],A[N];
int hd[N],ch[N],pos[N],no=1,p=0,n ;
vector<int> g[N];
struct tree
{
    int mxl,mxr,sum,mx ;
};
tree st[N*4];
void dfs(int u,int v)
{
    par[u]=v,sub[u]=1,depth[u]=depth[v]+1;
    for(auto it:g[u])if(it!=v)dfs(it,u),sub[u]+=sub[it];
}
void hld(int u)
{
    int tmp=0,mx=0;
    if(!hd[no])hd[no]=u ;
    ch[u]=no,pos[u]=++p;
    for(auto it:g[u])if(it!=par[u]&&sub[it]>mx)mx=sub[it],tmp=it;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it!=par[u]&&it!=tmp)no++,hld(it);
}
tree operate(tree t1,tree t2)
{
    /// mxl mxr sum mx
    tree t ;
    t.sum=t1.sum+t2.sum;
    t.mxl=max(t1.mxl,t1.sum+t2.mxl);
    t.mxr=max(t2.mxr,t2.sum+t1.mxr);
    t.mx=max(t1.mxr+t2.mxl,max(t1.mx,t2.mx));
    return t ;
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        int tmp=max(A[l],0);
        st[m]={tmp,tmp,A[l],tmp} ;
        return ;
    }
    construct(l,mid,m<<1),construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void uplazy(int l,int r,int m)
{
    if(lazy[m]<INF)
    {
        int cst = lazy[m]*(r-l+1);
        int tmp = max(cst,0) ;
        st[m]={tmp,tmp,cst,tmp};
        if(l<r)
        {
            lazy[m<<1]=lazy[m];
            lazy[m<<1|1]=lazy[m];
        }
        lazy[m]=INF ;
    }
}
void update(int l,int r,int x,int y,int cst,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        int tmp1=cst*(r-l+1),tmp2=max(tmp1,0);
        st[m]={tmp2,tmp2,tmp1,tmp2};
        if(l<r)
        {
            lazy[m<<1]=cst;
            lazy[m<<1|1]=cst;
        }
        return ;
    }
    int mid=l+r>>1;
    update(l,mid,x,y,cst,m<<1),update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
tree findsum(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return {0,0,0,0};
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1 ;
    return operate(findsum(l,mid,x,y,m<<1),
        findsum(mid+1,r,x,y,m<<1|1));
}
void uphld(int u,int v,int cst)
{
    while(ch[u]!=ch[v])
    {
        int hx=hd[ch[u]],hy=hd[ch[v]];
        if(depth[hx]>=depth[hy])
        {
            update(1,n,pos[hx],pos[u],cst,1);
            u=par[hx];
        }
        else
        {
            update(1,n,pos[hy],pos[v],cst,1);
            v=par[hy];
        }
    }
    if(depth[u]>depth[v])swap(u,v);
    update(1,n,pos[u],pos[v],cst,1);
}
int qans(int u,int v)
{
    tree t1={0,0,0,0},t2={0,0,0,0},tmp ;
    while(ch[u]!=ch[v])
    {
        int hx=hd[ch[u]],hy=hd[ch[v]];
        if(depth[hx]>=depth[hy])
        {
            tmp=findsum(1,n,pos[hx],pos[u],1);
            t1=operate(tmp,t1);
            u=par[hx];
        }
        else
        {
            tmp=findsum(1,n,pos[hy],pos[v],1);
            t2=operate(tmp,t2);
            v=par[hy];
        }
    }
    if(depth[u]>depth[v])swap(u,v),swap(t1,t2);
    t2=operate(findsum(1,n,pos[u],pos[v],1),t2);
    return max(max(t1.mx,t2.mx),t1.mxl+t2.mxl) ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,u,v,T,cst ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1),hld(1);
    for(i=1;i<=n;i++)A[pos[i]]=a[i];
    construct(1,n,1);
    fill(lazy,lazy+N*4-1,INF);
    cin >> T ;
    while(T--)
    {
        cin >> i >> u >> v ;
        if(i==1)cout << qans(u,v) << '\n' ;
        else
        {
            cin >> cst ;
            uphld(u,v,cst);
        }
    }
}
