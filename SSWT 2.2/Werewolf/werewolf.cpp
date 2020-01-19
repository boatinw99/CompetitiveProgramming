/**
 *      Author : boatinw99
 *      Date : 4.5.2019 10.50 - 11.15 , 12.50 - 13.35
 */

#include "werewolf.h"
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e5+9 ,inf = 1e9 ,LOG=log2(N)+1 ;
struct Q
{
    int st,ed,l,r,idx ;
}query[N];
int L[N*LOG*2],R[N*LOG*2],st[N*LOG*2],idx=1,root[N];
pii edge[N<<1] ;
int n,m,q;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++idx,R[m]=++idx;
    construct(l,mid,L[m]);
    construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    if(r<x||l>x)return m;
    int nw = ++idx ;
    if(l==r)
    {
        st[nw]++;
        return nw ;
    }
    L[nw]=update(l,mid,x,L[m]),R[nw]=update(mid+1,r,x,R[m]);
    st[nw]=st[L[nw]]+st[R[nw]];
    return nw ;
}
int getsum(int l,int r,int x,int y,int m1,int m2)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m1]-st[m2];
    return getsum(l,mid,x,y,L[m1],L[m2])+getsum(mid+1,r,x,y,R[m1],R[m2]);
}
struct tree
{
    int up[N][LOG],cst[N][LOG],tin[N],tout[N],times = 0 ; /// cst-> min or max
    int rnk[N],p[N],val[N],euler[N],pos[N],idx=0;
    vector<int> g[N];
    void init()
    {
        for(int i=1;i<=n;i++)p[i]=val[i]=i ;
    }
    int find(int u)
    {
        return u==p[u]?u:p[u]=find(p[u]);
    }
    bool Union0(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v)return 0;
        int mn = min(val[u],val[v]);
        if(rnk[u]>=rnk[v])swap(u,v);
        rnk[v]+=rnk[u];
        g[val[v]].emplace_back(val[u]);
        g[val[u]].emplace_back(val[v]);
        val[v]=mn;
        p[u]=v;
        return 1;
    }
    bool Union1(int u,int v)
    {
        u=find(u),v=find(v);
        if(u==v)return 0;
        int mn = max(val[u],val[v]);
        if(rnk[u]>=rnk[v])swap(u,v);
        rnk[v]+=rnk[u];
        g[val[v]].emplace_back(val[u]);
        g[val[u]].emplace_back(val[v]);
        val[v]=mn;
        p[u]=v;
        return 1;
    }
    void dfs0(int u,int v)
    {
        up[u][0]=v;
        tin[u]=++times;
        pos[u]=times;
        euler[times]=u;
        for(int i=1;i<LOG;i++)
        {
            up[u][i]=up[up[u][i-1]][i-1];
            cst[u][i]=cst[up[u][i-1]][i-1];
        }
        for(auto it:g[u])if(it!=v)cst[it][0]=u,dfs0(it,u);
        tout[u]=times;
    }
    void dfs1(int u,int v)
    {
        up[u][0]=v;
        tin[u]=++times;
        pos[u]=times;
        euler[times]=u;
        for(int i=1;i<LOG;i++)
        {
            up[u][i]=up[up[u][i-1]][i-1];
            cst[u][i]=cst[up[u][i-1]][i-1];
        }
        for(auto it:g[u])if(it!=v)cst[it][0]=u,dfs1(it,u);
        tout[u]=times;
    }
    int bliftmin(int u,int val)
    {
        for(int i=LOG-1;i>=0;i--)if(cst[u][i]>=val)u=up[u][i];
        return u;
    }
    int bliftmax(int u,int val)
    {
        for(int i=LOG-1;i>=0;i--)if(cst[u][i]<=val)u=up[u][i];
        return u ;
    }

}t1,t2;
void constructdsu()
{
    t1.init();
    sort(edge+1,edge+1+m,[&](const pii a,const pii b){
         return min(a.fi,a.se)>min(b.fi,b.se);});
    for(int i=1;i<=m;i++)t1.Union0(edge[i].fi,edge[i].se);
    t1.dfs0(1,1);
    t2.init();
    sort(edge+1,edge+1+m,[&](const pii a,const pii b){
         return max(a.fi,a.se)<max(b.fi,b.se);});
    for(int i=1;i<=m;i++)t2.Union1(edge[i].fi,edge[i].se);
    t2.up[n][0]=n;
    t2.cst[n][0]=inf;
    t2.dfs1(n,n);
}
vector<int> check_validity(int SZ,vector<int> X,vector<int> Y,
                                vector<int> S,vector<int> E,
                                vector<int> le,vector<int> ri)
{
    n=SZ;
    m=X.size();
    q=S.size();
    vector<int> ans(q);
    for(int i=1;i<=m;i++)edge[i]={X[i-1]+1,Y[i-1]+1};
    for(int i=1;i<=q;i++)query[i]={S[i-1]+1,E[i-1]+1,le[i-1]+1,ri[i-1]+1,i};
    constructdsu();
    root[0]=1;
    construct(1,n,1);
    for(int i=1;i<=n;i++)root[i]=update(1,n,t2.pos[t1.euler[i]],root[i-1]);
    sort(query+1,query+1+q,[&](const Q a,const Q b){
         return a.r<b.r;});
    for(int i=1;i<=q;i++)
    {
        int u = t1.bliftmin(query[i].st,query[i].l);
        int v = t2.bliftmax(query[i].ed,query[i].r);
        ans[query[i].idx-1]=(getsum(1,n,t2.tin[v],t2.tout[v],
                    root[t1.tout[u]],root[t1.tin[u]-1])>0);
    }
    return ans ;
}
