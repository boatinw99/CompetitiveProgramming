#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 2e5+9 , K = 21 ;
int n,k,no=1,idx=1;
struct node
{
    int cnt[K];
}st[N<<2];
int lazy[N<<2],par[N],pos[N],ch[N],hd[N],sub[N];
vector<int> g[N];
node operate(node a,node b)
{
    node ret ;
    for(int i=0;i<k;i++)ret.cnt[i]=a.cnt[i]+b.cnt[i];
    return ret ;
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m].cnt[1]=1;
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
void push(int l,int r,int m)
{
    if(!lazy[m])return ;
    int tmp[K],cst=lazy[m]%k;
    lazy[m<<1]+=lazy[m];
    lazy[m<<1|1]+=lazy[m];
    for(int i=0;i<k;i++)tmp[i]=st[m].cnt[(i-cst+k)%k];
    for(int i=0;i<k;i++)st[m].cnt[i]=tmp[i];
    lazy[m]=0;
}
void update(int l,int r,int x,int y,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]++;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
int query(int m)
{
    return (m%k==0)&&(st[1].cnt[0]==m/k);
}
void dfs0(int u)
{
    sub[u]=1;
    for(auto it:g[u])dfs0(it),sub[u]+=sub[it];
}
void hld(int u)
{
    if(!hd[no])hd[no]=u;
    ch[u]=no,pos[u]=idx++;
    int mx=0,tmp=0;
    for(auto it:g[u])if(sub[it]>mx)mx=sub[it],tmp=it;
    if(tmp)hld(tmp);
    for(auto it:g[u])if(it!=tmp)no++,hld(it);
}
void upd(int u)
{
    while(u)
    {
        int pu = hd[ch[u]];
        update(1,n,pos[pu],pos[u],1);
        u=par[pu];
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ;
    for(int i=2,x ;i<=n;i++)
    {
        cin >> x ;
        par[i]=x ;
        g[x].emplace_back(i);
    }
    dfs0(1);hld(1);
    construct(1,n,1);
    for(int i=2;i<=n;i++)
    {
        upd(par[i]);
        cout << (query(i)?"YES":"NO") << '\n' ;
    }
    return 0 ;
}
