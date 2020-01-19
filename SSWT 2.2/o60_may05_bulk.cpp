#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e5+9,inf = 1e9+7 ;
vector<pii> g[N];
vector<int> typ[2] ;
struct T
{
    int sum,mx,cnt ;
};
T st[N<<2];///val , times ,cnt
int lazy1[N<<2],lazy2[N<<2];
int edge[N],wi[N];
int n,sz,times;
bool cycle[N],vst[N];
void push(int l,int r,int m)
{
    int  b = 0 ;
    if(lazy2[m]!=inf)//set c 
    {
        st[m].sum=lazy2[m]*(r-l+1);
        st[m].mx=lazy2[m];
        st[m].cnt=r-l+1;
        if(l<r)
        {
            lazy1[m<<1]=lazy1[m<<1|1]=0 ;
            lazy2[m<<1]=lazy2[m];
            lazy2[m<<1|1]=lazy2[m];
        }
        lazy2[m]=inf;
    }
    if(lazy1[m]!=0)//+ c
    {
        st[m].sum+=lazy1[m]*(r-l+1);
        st[m].mx+=lazy1[m];
        if(l<r)
        {
            lazy1[m<<1]+=lazy1[m];
            lazy1[m<<1|1]+=lazy1[m];
        }
        lazy1[m]=0;
    }
}
T operate(T t1,T t2)
{
    T tmp={0,0,0};
    tmp.sum=t1.sum+t2.sum;
    if(t1.mx>t2.mx)tmp.mx=t1.mx,tmp.cnt=t1.cnt;
    else if(t1.mx<t2.mx)tmp.mx=t2.mx,tmp.cnt=t2.cnt;
    else
    {
        tmp.mx=t1.mx;
        tmp.cnt=t1.cnt+t2.cnt;
    }
    return tmp ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        ///DONT FORGET HERE
        st[m]={wi[l],wi[l],1};
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update1(int l,int r,int x,int y,int cst,int m)
{
    push(l,r,m);
    if(r<x||l>y||x>y)return ;
    if(l>=x&&r<=y)
    {
        lazy1[m]=cst ;
        push(l,r,m);
        return ;
    }
    update1(l,mid,x,y,cst,m<<1);
    update1(mid+1,r,x,y,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update2(int l,int r,int x,int y,int cst,int m)
{
    push(l,r,m);
    if(r<x||l>y||x>y)return ;
    if(l>=x&&r<=y)
    {
        lazy2[m]=cst;
        push(l,r,m);
        return ;
    }
    update2(l,mid,x,y,cst,m<<1);
    update2(mid+1,r,x,y,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
T getans(int l,int r,int x,int y,int m)
{
    push(l,r,m);
    if(r<x||l>y)return {0,-inf,0};
    if(l>=x&&r<=y)return st[m];
    return operate(getans(l,mid,x,y,m<<1),getans(mid+1,r,x,y,m<<1|1));
}
int dfs0(int u,int v)
{
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it.fi])
        {
            int ret = dfs0(it.fi,u);
            if(ret<0)return -1 ;
            if(ret>0)cycle[it.se]=1;
            if(ret==u)return -1 ;
            else if(ret)return ret ;
        }
        else if(it.fi!=v)
        {
            cycle[it.se]=1;
            return it.fi ;
        }
    }
    return 0 ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v,x,t ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> u >> v >> edge[i] ;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    for(i=0;i<N*4;i++)lazy2[i]=inf ;
    dfs0(1,1);
    for(i=1;i<=n;i++)typ[cycle[i]].emplace_back(i);
    sz = typ[0].size();
    for(i=0;i<sz;i++)wi[i+1]=edge[typ[0][i]];
    for(i=0;i<typ[1].size();i++)wi[i+sz+1]=edge[typ[1][i]];
    construct(1,n,1);
    while(m--)
    {
        cin >> t >> u >> v >> x ;
        auto it0l = lower_bound(typ[0].begin(),typ[0].end(),u)-typ[0].begin()+1;
        auto it0r = upper_bound(typ[0].begin(),typ[0].end(),v)-typ[0].begin();
        auto it1l = lower_bound(typ[1].begin(),typ[1].end(),u)-typ[1].begin()+1;
        auto it1r = upper_bound(typ[1].begin(),typ[1].end(),v)-typ[1].begin();
        it1l+=sz;
        it1r+=sz;
        if(t==1)
        {
            update1(1,n,it0l,it0r,x,1);
            update1(1,n,it1l,it1r,x,1);
        }
        else if(t==2)
        {
            update2(1,n,it0l,it0r,x,1);
            update2(1,n,it1l,it1r,x,1);
        }
        T tmp = getans(1,n,sz+1,n,1);
        cout << getans(1,n,1,sz,1).sum+tmp.sum-tmp.mx << " " << tmp.cnt << '\n' ;
    }
}
