#include<bits/stdc++.h>
using namespace std ;
const int N = 111111 ;
typedef pair<int,int> pii;
multiset<int> sw[N],sb[N];
vector<int> G[N],chain[N];
#define fi first
#define se second
int b[N],d[N];
int par[N],sub[N],pos[N],hy[N],ind[N],depth[N];
int allw[N],allb[N];
int wh[N],bl[N];
int x,y,no=1,p=1,n ;
struct Tree
{
    int prew,preb,sufw,sufb,cpre,csuf,sep;
};
Tree st[N*4];
Tree operate(Tree t1,Tree t2)
{
    Tree t ;
    if(t1.sep==-1)return t2; if(t2.sep==-1)return t1;
    if(t1.csuf!=t2.cpre||(t1.sep&&t2.sep))
        return {t1.prew,t1.preb,t2.sufw,t2.sufb,t1.cpre,t2.csuf,1};
    t.cpre=t1.cpre; t.csuf=t2.csuf ; t.sep=max(t1.sep,t2.sep);
    if(t1.sep==0&&t2.sep==0)
    {
        t.prew=t.sufw=t1.prew+t2.prew;
        t.preb=t.sufb=t1.preb+t2.preb;
    }
    else if(t1.sep)
    {
        t.prew=t1.prew; t.preb=t1.preb;
        t.sufw=t1.sufw+t2.prew ;  t.sufb = t1.sufb+t2.preb;
    }
    else
    {
        t.sufw=t2.sufw; t.sufb=t2.sufb;
        t.prew=t1.sufw+t2.prew; t.preb=t1.sufb+t2.preb;
    }
    return t;
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)st[m]={allw[l],allb[l],allw[l],allb[l],0,0,0};
    else
    {
        construct(l,mid,m*2); construct(mid+1,r,m*2+1);
        st[m]=operate(st[m*2],st[m*2+1]);
    }
}
void update(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l>x||r<x||l>r)return ;
    if(l==x&&r==x)st[m]={allw[l],allb[l],allw[l],allb[l],d[l],d[l],0};
    else
    {
        update(l,mid,m*2); update(mid+1,r,m*2+1);
        st[m]=operate(st[m*2],st[m*2+1]);
    }
}
Tree findans(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y||x>y||l>r)return {0,0,0,0,0,0,-1};
    if(l>=x&&r<=y)return st[m];
    return operate(findans(l,mid,m*2),findans(mid+1,r,m*2+1));
}
void dfs(int u)
{
    int max1=0,ind=0 ;
    sub[u]=1;depth[u]=depth[par[u]]+1;
    for(auto it:G[u])
    {
        if(it!=par[u])
        {
            par[it]=u; dfs(it); sub[u]+=sub[it];
            if(max1<sub[it])max1=sub[it],ind=it;
        }
    }
    hy[u]=ind;
}
void hld(int u)
{
    chain[no].emplace_back(u); pos[u]=p++; ind[u]=no;
    if(hy[u])hld(hy[u]);
    for(auto it:G[u])if(it!=par[u]&&it!=hy[u])no++,hld(it);
}
void E(multiset<int> &a ,int val)
{
    auto it=a.find(val);
    a.erase(it);
}
void I(multiset<int> &a,int val){a.insert(val);}
void color(int u)
{
    int px,py,pz,pp,pu=pos[u],id,i=u ;
    Tree t;
    ///erase
    while(ind[u]!=1)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pp = par[px]; pu=pos[u];
        x=pz; y=pz+py-1 ;
        t = findans(1,n,1);
        E(sw[pp],t.prew),wh[pp]-=t.prew;
        E(sb[pp],t.preb),bl[pp]-=t.preb;
        u=pp;
    }
    ///update
    u=i;
    pu=pos[u];
    if(b[u]==0)
    {
        b[u]=1; E(sw[u],1); wh[u]--;I(sb[u],1); bl[u]++;
        d[pu]=1;
    }
    else
    {
        b[u]=0; E(sb[u],1); bl[u]--; I(sw[u],1); wh[u]++;
        d[pu]=0;
    }
    //printf("aa %d %d %d | color = %d \n",u,wh[u],bl[u],b[u]);
    while(ind[u]!=0)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pp = par[px]; pu=pos[u];
        if(b[u]==0)allw[pu]=wh[u],allb[pu]=0;
        else allb[pu]=bl[u],allw[pu]=0;
        x=pu ; update(1,n,1);
        if(ind[u]==1)break;
        x=pz; y=pz+py-1;
        t=findans(1,n,1);
        I(sw[pp],t.prew),wh[pp]+=t.prew;
        I(sb[pp],t.preb),bl[pp]+=t.preb;
        u=pp;
    }

}
int qans(int u)
{
    int cl=b[u],ans=0,px,py,pz,pp,pu,id ;
    Tree t ;
    while(ind[u]!=1)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pp = par[px]; pu=pos[u];
        x=pz; y=pu ;
        t = findans(1,n,1);
        if(t.sep==0&&b[px]==b[pp]&&b[px]==cl)u=pp;
        else break;
    }
    id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
    pp = par[px]; pu=pos[u];
    x=pz; y=pu ;
    t = findans(1,n,1);
    if(cl==0)ans+=t.sufw; else ans+=t.sufb;
    x=pu+1; y=pz+py-1;
    if(x<=y)
    {
        t = findans(1,n,1);
        if(cl==0)ans+=t.prew; else ans+=t.preb;
    }
    return ans ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,u,v,px,py,T,pz ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(i=1;i<=n;i++){wh[i]=1,I(sw[i],1);allw[i]=1;}
    dfs(1); hld(1); construct(1,n,1);
    vector<pii> h ;
    for(i=2;i<=no;i++)h.emplace_back(depth[chain[i][0]],i);
    sort(h.begin(),h.end(),greater<pii>());
    Tree t;
    for(pii it:h)
    {
        i=it.se ;
        px=chain[i][0]; pz=pos[px]; py=chain[i].size();
        x=pz; y=pz+py-1;
        t=findans(1,n,1);
        I(sw[par[px]],t.prew);
        I(sb[par[px]],t.preb);
        wh[par[px]]+=t.prew ;
        allw[pos[par[px]]]=wh[par[px]];
        x=pos[par[px]];
        update(1,n,1);
    }
    cin >> T ;
    while(T--)
    {
        cin >> u >> v ;
        if(u==0)cout << qans(v) << '\n' ;
        else color(v);
    }
}
