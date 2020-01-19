#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int st[N*4],sub[N],depth[N];
int par[N],hd[N],ch[N],pos[N],no=1,timer=0,n;
vector<int> g[N];
void update(int l,int r,int x,int cst,int m)
{

    int mid=l+r>>1;
    if(l>x||r<x)return ;
    if(l==x&&r==x)
    {
        st[m]+=cst;
        return ;
    }
    update(l,mid,x,cst,m<<1),update(mid+1,r,x,cst,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int findmx(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(l>y||r<x)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return max(findmx(l,mid,x,y,m<<1),findmx(mid+1,r,x,y,m<<1|1));
}
void dfs1(int u,int v)
{
    sub[u]=1;
    par[u]=v;
    depth[u]=depth[v]+1;
    for(auto it:g[u])if(it!=v)dfs1(it,u),sub[u]+=sub[it];
}
void hld(int u)
{
    int mx=0,tmp=0 ;
    if(hd[no]==0)hd[no]=u;
    pos[u]=++timer,ch[u]=no ;
    for(auto it:g[u])if(it!=par[u]&&sub[it]>mx)mx=sub[it],tmp=it ;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it!=par[u]&&it!=tmp)no++,hld(it);
}
int qans(int u,int v)
{
    int mx = 0 ;
    while(ch[u]!=ch[v])
    {
        if(depth[hd[ch[u]]]>=depth[hd[ch[v]]])
        {
            mx=max(mx,findmx(1,n,pos[hd[ch[u]]],pos[u],1));
            u=par[hd[ch[u]]];
        }
        else
        {
            mx=max(mx,findmx(1,n,pos[hd[ch[v]]],pos[v],1));
            v=par[hd[ch[v]]];
        }
    }
    mx=max(mx,findmx(1,n,min(pos[u],pos[v]),max(pos[u],pos[v]),1));
    return mx ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,T,u,v ;
    char c ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(1,1),hld(1);
    cin >> T ;
    while(T--)
    {
        cin >> c >> u >> v ;
        if(c=='I')update(1,n,pos[u],v,1);
        else cout << qans(u,v) << '\n' ;
    }
}
