#include<bits/stdc++.h>
using namespace std ;
#define fi first
#define se second
const int N = 1e5+9 ,MAX = 1e6 ;
vector<int> G[N];
vector<int> ch[N];
int st[N*4],depth[N],par[N],sub[N],pos[N],hy[N];
int hd[N],chno[N],no=1,p=1,n;
void update(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>x)return ;
    if(l==x&&l==r)
    {
        if(st[m]<MAX)st[m]=MAX ;
        else st[m]=y ;
        return ;
    }
    update(l,mid,x,y,m*2);
    update(mid+1,r,x,y,m*2+1);
    st[m]=min(st[m*2],st[m*2+1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)return MAX ;
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m*2),findmin(mid+1,r,x,y,m*2+1));
}
int findlca(int u)
{
    int x=MAX,ind=MAX,y ; ///node x
    while(chno[u]!=1)
    {
        y=findmin(1,n,pos[hd[chno[u]]],pos[u],1);
        if(y<x)x=y,ind=ch[chno[u]][y-depth[hd[chno[u]]]];
        u=par[hd[chno[u]]];
    }
    y=findmin(1,n,1,pos[u],1);
    if(y<x)x=y,ind=ch[1][y-1];
    return (ind<=n)?ind:-1 ;
}
void dfs(int u)
{
    int max1=0,ind=0;
    depth[u]=depth[par[u]]+1;
    sub[u]=1;
    for(auto it:G[u])
    {
        if(it!=par[u])
        {
            par[it]=u;
            dfs(it);
            sub[u]+=sub[it];
            if(max1<sub[it])max1=sub[it],ind=it;
        }
    }
    hy[u]=ind;
}
void hld(int u)
{
    if(!hd[no])hd[no]=u;
    chno[u]=no;
    ch[no].emplace_back(u);
    pos[u]=p++ ;
    if(hy[u])hld(hy[u]);
    for(auto it:G[u])
    {
        if(it!=par[u]&&it!=hy[u])
        {
            no++;
            hld(it);
        }
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,i,j,u,v ;
    cin >> n >> T ;
    for(i=0;i<N*4;i++)st[i]=MAX;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1); hld(1);
    while(T--)
    {
        cin >> u >> v ;
        if(u==0)update(1,n,pos[v],depth[v],1);
        else cout << findlca(v) << '\n' ;
    }
}
