#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+ 9 ,MIN=-1e9 ;
typedef pair<int,int> pii ;
#define fi first
#define se second
struct Tree
{
    int prew,preb,sufw,sufb,cpre,csuf,sep;
};
Tree st[N*4];
vector<int> G[N],chain[N];
multiset<int> sw[N],sb[N];
int b[N],d[N],par[N],sub[N],hy[N];
int maxw[N],maxb[N],NOW[N];
int pos[N],depth[N],ind[N];
int n,p=1,no=1,x,y;
Tree operate(Tree t1,Tree t2)
{
    Tree t ;
    if(t1.sep==-1)return t2; if(t2.sep==-1)return t1;
    if(t1.csuf!=t2.cpre||(t1.sep&&t2.sep))
    {
        return {t1.prew,t1.preb,t2.sufw,t2.sufb,t1.cpre,t2.csuf,1};
    }
    t.cpre=t1.cpre; t.csuf=t2.csuf; t.sep=max(t1.sep,t2.sep);
    if(t1.sep==0&&t2.sep==0)
    {
        t.prew=t.sufw=max(t1.prew,t2.prew);
        t.preb=t.sufb=max(t1.preb,t2.preb);
    }
    else if(t1.sep)
    {
        t.prew=t1.prew; t.preb=t1.preb;
        t.sufw=max(t1.sufw,t2.prew);
        t.sufb=max(t1.sufb,t2.preb);
    }
    else
    {
        t.sufw=t2.sufw; t.sufb=t2.sufb;
        t.prew=max(t1.sufw,t2.prew); t.preb=max(t1.sufb,t2.preb);
    }
    return t ;
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        if(d[l]==0)st[m]={maxw[l],MIN,maxw[l],MIN,d[l],d[l],0};
        else st[m]={MIN,maxb[l],MIN,maxb[l],d[l],d[l],0};
    }
    else
    {
        construct(l,mid,m*2) ; construct(mid+1,r,m*2+1);
        st[m]=operate(st[m*2],st[m*2+1]);
    }
}
void update(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>x)return ;
    if(l==x&&r==x)
    {
        if(d[l]==0)st[m]={maxw[l],MIN,maxw[l],MIN,d[l],d[l],0};
        else st[m]={MIN,maxb[l],MIN,maxb[l],d[l],d[l],0};
        return ;
    }
    update(l,mid,m*2); update(mid+1,r,m*2+1);
    st[m]=operate(st[m*2],st[m*2+1]);
}
Tree findans(int l,int r,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y||x>y)return {MIN,MIN,MIN,MIN,0,0,-1};
    if(l>=x&&r<=y)
    {

        return st[m];
    }
    return operate(findans(l,mid,m*2),findans(mid+1,r,m*2+1));
}
void E(multiset<int> &a,int val){auto it=a.find(val); a.erase(it);}
void I(multiset<int> &a,int val){a.insert(val);}
void dfs(int u)
{
    int max1=0,id = 0;
    sub[u]=1;
    depth[u]=depth[par[u]]+1;
    for(auto it:G[u])
    {
        if(it!=par[u])
        {
            par[it]=u ;
            dfs(it);
            sub[u]+=sub[it];
            if(sub[it]>max1)max1=sub[it],id=it;
        }
    }
    hy[u]=id ;
}
void hld(int u)
{
    chain[no].emplace_back(u); pos[u]=p++; ind[u]=no;
    if(hy[u])hld(hy[u]);
    for(auto it:G[u])if(it!=par[u]&&it!=hy[u])no++,hld(it);
}
int qans(int u)
{
    int max1=MIN ,px,py,pz,pp,pu,id,ppp;
    Tree t ;
    while(ind[u]!=1)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
        x=pz ; y=pu;
        t=findans(1,n,1);
        if(t.sep==0&&b[px]==b[pp])u=pp;
        else break ;
    }
    id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
    x=pz; y=pu;
    t=findans(1,n,1);
    if(b[u]==0)max1=t.sufw; else max1=t.sufb;
    x= pu+1; y=pz+py-1;
    t=findans(1,n,1);
    if(b[u]==0)max1=max(max1,t.prew); else max1=max(max1,t.preb);
    return max1 ;
}
void color(int u)
{
    int px,py,pz,pp,pu,id,ppp,i=u;
    Tree t ;
    while(ind[u]!=1)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
        x=pz ; y=pz+py-1;
        t=findans(1,n,1);
        E(sw[pp],t.prew); E(sb[pp],t.preb);
        u=pp;
    } u=i; pu=pos[u];
    if(b[u]==0){b[u]=1,d[pu]=1;E(sw[u],NOW[u]);I(sb[u],NOW[u]);}
    else b[u]=0,d[pu]=0,E(sb[u],NOW[u]),I(sw[u],NOW[u]);
    while(ind[u]!=0)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
        maxw[pu]=maxb[pu]=0;
        if(b[u]==0)maxw[pu]=*sw[u].rbegin();
        else maxb[pu]=*sb[u].rbegin();
        x=pu;
        update(1,n,1);
        x=pz ; y=pz+py-1;
        t=findans(1,n,1);
        I(sw[pp],t.prew); I(sb[pp],t.preb);
        u=pp;
    }
}
void changewi(int u,int val)
{
    int px,py,pz,pp,pu,id,ppp,i=u;
    Tree t ;
    while(ind[u]!=1)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
        x=pz ; y=pz+py-1;
        t=findans(1,n,1);
        E(sw[pp],t.prew); E(sb[pp],t.preb);
        u=pp;
    } u=i; pu=pos[u];
    if(b[u]==0){E(sw[u],NOW[u]);I(sw[u],val);}
    else E(sb[u],NOW[u]),I(sb[u],val);
    NOW[u]=val ;
    while(ind[u]!=0)
    {
        id=ind[u]; px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
        maxw[pu]=maxb[pu]=0;
        if(b[u]==0)maxw[pu]=*sw[u].rbegin();
        else maxb[pu]=*sb[u].rbegin();
        x=pu;
        update(1,n,1);
        x=pz ; y=pz+py-1;
        t=findans(1,n,1);
        I(sw[pp],t.prew); I(sb[pp],t.preb);
        u=pp;
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,u,v,wi,T,px,py,pz,pp,pu,ppp,id,val ;
    Tree t ;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1); hld(1);
    for(i=1;i<=n;i++)
    {
        cin >> b[i];
        d[pos[i]]=b[i];
    }
    for(i=1;i<=n;i++)maxw[i]=maxb[i]=MIN;
    for(i=1;i<=n;i++)
    {
        cin >> wi;
        NOW[i]=wi;
        if(d[pos[i]]==0)maxw[pos[i]]=wi,sw[i].insert(wi);
        else  maxb[pos[i]]=wi,sb[i].insert(wi);
    }
    construct(1,n,1);
    vector<pii> h ;
    for(i=2;i<=no;i++)h.emplace_back(depth[chain[i][0]],i);
    sort(h.begin(),h.end(),greater<pii>());
    for(auto it:h)
    {
        id=it.se ;
        px=chain[id][0]; py=chain[id].size(); pz=pos[px];
        pu=pos[u]; pp=par[px]; ppp=pos[pp];
        x=pz; y=pz+py-1;
        t=findans(1,n,1);
        I(sw[pp],t.prew); maxw[ppp]=max(maxw[ppp],t.prew);
        I(sb[pp],t.preb); maxb[ppp]=max(maxb[ppp],t.preb);
        x=ppp;
        update(1,n,1);
    }
    cin >> T ;
    while(T--)
    {
        cin >> u >> v;
        if(u==0)cout << qans(v) << '\n' ;
        else if(u==1)color(v);
        else {cin >> val ; changewi(v,val);}
    }
}
