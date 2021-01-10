#include<bits/stdc++.h>
using namespace std ;
typedef long long ll  ;
typedef pair<ll,int> pli ;
const int N = 1e5+9 ;
const ll MAX = 1e16 ;
#define fi first
#define se second
vector<int> g[N],town[N];
queue<int> q ;
int par[N],sub[N],hd[N],ch[N],depth[N],pos[N],out[N],iter[N];
int pathhld[N];
ll lazy[N*4],a[N];
pli st[N*4];
int p=0,no=1,n;
pli operate(pli t1,pli t2)
{
    pli t;
    if(t1.fi<t2.fi)t=t1;
    else if(t1.fi>t2.fi)t=t2;
    else t={t1.fi,min(t1.se,t2.se)};
    return t ;
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]={a[l],pathhld[l]};
        return ;
    }
    construct(l,mid,m<<1),construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void updatelazy(int l,int r,int m)
{
    if(lazy[m])
    {
        st[m].fi+=lazy[m];
        if(l<r)
        {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void update(int l,int r,int x,int y,ll cst,int m)
{
    int mid=l+r>>1;
    updatelazy(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        st[m].fi+=cst ;
        if(l<r)
        {
            lazy[m<<1]+=cst ;
            lazy[m<<1|1]+=cst ;
        }
        return ;
    }
    update(l,mid,x,y,cst,m<<1),update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pli findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1 ;
    updatelazy(l,r,m);
    if(r<x||l>y)return {MAX,0};
    if(l>=x&&r<=y)return st[m];
    return operate(findmin(l,mid,x,y,m<<1),findmin(mid+1,r,x,y,m<<1|1));
}
void dfs(int u,int v)
{
    sub[u]=1,par[u]=v,depth[u]=depth[v]+1;
    for(auto it:g[u])if(it!=v)dfs(it,u),sub[u]+=sub[it];
}
void hld(int u)
{
    int mx=0,tmp=0;
    if(!hd[no])hd[no]=u;
    pos[u]=++p,pathhld[p]=u,ch[u]=no;
    for(auto it:g[u])if(it!=par[u]&&sub[it]>mx)mx=sub[it],tmp=it;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it!=par[u]&&it!=tmp)no++,hld(it);
    out[u]=p;
}
bool findans(int u,int v)
{
    /// find min in path u -> v
    pli ans={MAX,0};
    while(ch[u]!=ch[v])
    {
        if(depth[hd[ch[u]]]>=depth[hd[ch[v]]])
        {
            ans=operate(ans,findmin(1,n,pos[hd[ch[u]]],pos[u],1));
            u=par[hd[ch[u]]];
        }
        else
        {
            ans=operate(ans,findmin(1,n,pos[hd[ch[v]]],pos[v],1));
            v=par[hd[ch[v]]];
        }
    }
    ans=operate(ans,findmin(1,n,min(pos[u],pos[v]),
                    max(pos[u],pos[v]),1));
    if(ans.fi<MAX)
    {
        int tmp = ans.se ;
        q.push(town[tmp][iter[tmp]]);
        iter[tmp]++;
        int dif=town[tmp][iter[tmp]]-town[tmp][iter[tmp]-1];
        if(town[tmp].size()==iter[tmp])
        {
            update(1,n,pos[tmp],pos[tmp],MAX,1);
        }
        else
        {
            update(1,n,pos[tmp],pos[tmp],dif,1);
        }
        return 1;
    }
    return 0 ;
}
void qans(int u,int v,int k)
{
    bool ck=1 ;
    for(int i=1;i<=k&&ck;i++)ck = findans(u,v);
    cout << q.size() << " " ;
    for(;!q.empty();q.pop())cout << q.front() << " " ;
    cout << '\n' ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,T,u,v,i,j,tmp,t,k ;
    cin >> n >> m >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=m;i++)
    {
        cin >> tmp ;
        town[tmp].emplace_back(i);
    }
    dfs(1,1),hld(1);
    for(i=1;i<=n;i++)
    {
        a[pos[i]]=MAX ;
        if(!town[i].empty())a[pos[i]]=*town[i].begin();
    }
    construct(1,n,1);
    while(T--)
    {
        cin >> t ;
        if(t==1)
        {
            cin >> u >> v >> k ;
            qans(u,v,k) ;
        }
        else
        {
            cin >> u >> k ;
            update(1,n,pos[u],out[u],k,1);
        }
    }
}
