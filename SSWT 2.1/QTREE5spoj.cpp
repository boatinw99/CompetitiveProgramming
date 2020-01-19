#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ,MAX = 1e8 ;
struct Tree
{
    int pre,suf ;
};
multiset<int> smin[N] ;
bool b[N];
int depth[N],pos[N],par[N],hy[N],sub[N],minpre[N],minsuf[N],id[N];
vector<int> G[N],chain[N];
int x,y,n,p=1,no=1 ;
Tree st[N*4];
Tree operate(Tree t1,Tree t2)
{
    return {min(t1.pre,t2.pre),min(t1.suf,t2.suf)};
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)st[m]={MAX,MAX};
    else
    {
        construct(l,mid,m*2); construct(mid+1,r,m*2+1);
        st[m]=operate(st[m*2],st[m*2+1]);
    }
}
void update(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l>x||r<x)return ;
    if(l==x&&r==x)st[m]={minpre[l],minsuf[l]};
    else
    {
        update(l,mid,m*2); update(mid+1,r,m*2+1);
        st[m]=operate(st[m*2],st[m*2+1]);
    }
}
Tree findans(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y||x>y)return {MAX,MAX};
    if(l>=x&&r<=y)return st[m];
    return operate(findans(l,mid,m*2),findans(mid+1,r,m*2+1));
}
void dfs(int u)
{
    int max1=0,ind=0;
    sub[u]=1; depth[u]=depth[par[u]]+1;
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
    hy[u]=ind ;
}
void hld(int u)
{
    chain[no].emplace_back(u); id[u]=no; pos[u]=p++;
    if(hy[u])hld(hy[u]);
    for(auto it:G[u])if(it!=par[u]&&it!=hy[u])no++,hld(it);
}
void E(int i,int val){auto itmt=smin[i].find(val); smin[i].erase(itmt);}
void I(int i,int val){smin[i].insert(val);}
void color(int u)
{
    int i=u,val,px,py,pz,pu,ind,pp ;
    if(b[u]==0)b[u]=1,E(i,0),I(i,MAX);
    else b[u]=0,E(i,MAX),I(i,0);
    while(id[u]!=0)
    {
        ind=id[u];
        pu=pos[u]; px=chain[ind][0];py=chain[ind].size();pz=pos[px];
        pp=par[px];
        x=pz; y=pz+py-1;
        E(pp,findans(1,n,1).pre+1);
        minpre[pu]=*smin[u].begin()+pu-pz;
        minsuf[pu]=*smin[u].begin()+py-(pu-pz)-1;
        x=pu ; update(1,n,1);
        x=pz; y=pz+py-1;
        I(pp,findans(1,n,1).pre+1);
        u=pp;
    }
}
int qans(int u)
{
    int min1=MAX,ind,wh,px,py,pz,pu,pp,dist=0 ;
    while(id[u]!=0)
    {
        ind = id[u];
        pu = pos[u]; px=chain[ind][0];pp=par[px];
        py=chain[ind].size(); pz=pos[px];
        x=pz ; y=pu;
        min1=min(min1,findans(1,n,1).suf+dist-(depth[px]+py-1-depth[u]));
        x=y; y=pz+py-1;
        min1=min(min1,findans(1,n,1).pre+dist-(depth[u]-depth[px]));
        dist+=depth[u]-depth[par[px]];
        u = par[px];
    }
    return min1 ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,i,j,u,v,px,py,k ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1); hld(1);
    for(i=1;i<=n;i++)
    {
        b[i]=1;
        minpre[i]=MAX;
        minsuf[i]=MAX;
        smin[i].insert(MAX);
    }
    construct(1,n,1);
    for(i=1;i<=no;i++)
    {
        px=chain[i][0]; py = par[px];
        smin[py].insert(MAX+1);
    }
    cin >> T ;
    while(T--)
    {
        cin >> u >> v ;
        if(u==0)color(v);
        else
        {
            k=qans(v);
            if(k>n)k=-1;
            cout << k << '\n' ;
        }
    }
}
