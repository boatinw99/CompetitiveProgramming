#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ,MAX = 1e9  ;
struct Tree
{
    int pre,suf ;
};
vector<int> G[N],chain[N];
int pos[N],ind[N],depth[N],par[N],sub[N],dist[N],hy[N];
int mpre[N],msuf[N];
int n,no=1,p=1,x,y ;
Tree st[N*4];
Tree operate(Tree t1,Tree t2)
{
    return {min(t1.pre,t2.pre),min(t1.suf,t2.suf)};
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]={mpre[l],msuf[l]}; return ;
    }
    construct(l,mid,m<<1); construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void update(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>x)return ;
    if(l==x&&r==x)
    {
        st[m]={mpre[l],msuf[l]}; return ;
    }
    update(l,mid,m<<1); update(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
Tree findans(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y||x>y)return {MAX,MAX};
    if(l>=x&&r<=y)return st[m];
    return operate(findans(l,mid,m<<1),findans(mid+1,r,m<<1|1));
}
void dfs(int u)
{
    int max1=0,id=0;
    depth[u]=depth[par[u]]+1;
    sub[u]=1;
    for(auto it:G[u])
    {
        if(it!=par[u])
        {
            par[it]=u;dfs(it);sub[u]+=sub[it];
            if(max1<sub[it])max1=sub[it],id=it;
        }
    }
    hy[u]=id ;
}
void hld(int u)
{
    chain[no].emplace_back(u); pos[u]=p++; ind[u]=no;
    if(hy[u])hld(hy[u]);
    for(auto it:G[u])if(it!=hy[u]&&it!=par[u])no++,hld(it);
}
void color(int u)
{
    int id,px,py,pz,pu=pos[u],pp ;
    dist[pu]=0 ;
    while(u)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px];
        mpre[pu]= dist[pu]+pu-pz;
        msuf[pu]= dist[pu]+pz+py-pu-1;
        x=pu; update(1,n,1);
        dist[pos[pp]]=min(dist[pos[pp]],mpre[pu]+1);
        u=pp ;
    }
}
int qans(int u)
{
    int min1=MAX,id,d=0,px,py,pz,pu,pp ;
    while(u)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px];
        x=pz,y=pu;
        min1=min(min1,findans(1,n,1).suf+d-(pz+py-1-pu));
        x=pu; y=pz+py-1 ;
        min1=min(min1,findans(1,n,1).pre+d-(pu-pz));
        d+=depth[u]-depth[pp];
        u=pp ;
    }
    return min1;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,u,v,T ;
    Tree t ;
    cin >> n >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1); hld(1);
    dist[1]=0; mpre[1]=0; msuf[1]=chain[1].size()-1;
    for(i=2;i<=n;i++)dist[i]=mpre[i]=msuf[i]=MAX ;
    construct(1,n,1);
    while(T--)
    {
        cin >> u >> v ;
        if(u==1)color(v);
        else cout << qans(v) << '\n' ;
    }
}
