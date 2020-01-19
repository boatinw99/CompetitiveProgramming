#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 1e5+9 ,md = 1e9+9 ;
int lazy[N*4],st[N*4],pos[N],hd[N],ch[N],p=1,sub[N],par[N],no=1,depth[N];
bool vst[N];
int n ;
vector<int> g[N];
void uplazy(int l,int r,int m)
{
    if(lazy[m]>=2)
    {
        st[m]=1ll*st[m]*lazy[m]%md;
        if(l<r)
        {
            lazy[m<<1]=1ll*lazy[m]*lazy[m<<1]%md;
            lazy[m<<1|1]=1ll*lazy[m]*lazy[m<<1|1]%md;
        }
        lazy[m]=1;
    }
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=1;
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=(st[m<<1]+st[m<<1|1])%md;
}
void update(int l,int r,int x,int y,int m)
{
    uplazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m]=st[m]*2%md;
        if(l<r)
        {
            lazy[m<<1]=lazy[m<<1]*2%md;
            lazy[m<<1|1]=lazy[m<<1|1]*2%md ;
        }
        return ;
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=(st[m<<1]+st[m<<1|1])%md;
}
void dfs0(int u,int v)
{
    sub[u]=1,par[u]=v,depth[u]=depth[v]+1;
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it];
}
void hld(int u)
{
    if(vst[no]==0)hd[no]=u,vst[no]++;
    ch[u]=no,pos[u]=p++;
    int mx=0,tmp=0;
    for(auto it:g[u])if(it!=par[u]&&sub[it]>mx)mx=sub[it],tmp=it;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it!=par[u]&&it!=tmp)no++,hld(it);
}
void updatehld(int u,int v)
{
    while(ch[u]!=ch[v])
    {
        int pu=hd[ch[u]],pv=hd[ch[v]];
        if(depth[pu]>=depth[pv])///do pu
        {
            update(1,n,pos[pu],pos[u],1);
            u=par[pu];
        }
        else
        {
            update(1,n,pos[pv],pos[v],1);
            v=par[pv];
        }
    }
    if(pos[u]>pos[v])swap(u,v);
    update(1,n,pos[u],pos[v],1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,m,u,v,Q,E,type ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=0;i<N*4;i++)lazy[i]=1;
    dfs0(0,0);
    hld(0);
    construct(1,n,1);
    cin >> Q >> E ;
    Q+=E;
    while(Q--)
    {
        cin >> type ;
        if(type==1)cout << st[1] << '\n' ;
        else
        {
            cin >> u >> v ;
            updatehld(u,v);
        }
    }
}
