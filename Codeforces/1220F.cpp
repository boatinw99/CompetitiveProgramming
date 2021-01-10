#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 2e5+9 , inf = 1e9 ; 
int st[N<<2],lazy[N<<2],arr[N],tin[N],tout[N],n,pos[N],times=0;
int L[N],R[N];
pii mn[N<<2];
vector<int> V,g[N];
void push(int l,int r,int m)
{
    if(lazy[m]==0)return ;
    st[m]+=lazy[m];
    if(l<r)
    {
        lazy[m<<1]+=lazy[m];
        lazy[m<<1|1]+=lazy[m];
    }
    lazy[m]=0;
}
void update(int l,int r,int x,int y,int add,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]+=add ;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,add,m<<1);
    update(mid+1,r,x,y,add,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int getmax(int l,int r,int x,int y,int m)
{
    push(l,r,m);
    if(r<x||l>y)return 0 ; 
    if(l>=x&&r<=y)return st[m];
    return max(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        mn[m]={V[l],l};
        return ; 
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    mn[m]=min(mn[m<<1],mn[m<<1|1]);
}
pii getmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {inf,0} ;
    if(l>=x&&r<=y)return mn[m];
    return min(getmin(l,mid,x,y,m<<1),getmin(mid+1,r,x,y,m<<1|1));
}
void dfs0(int l,int r,int u)
{
    if(l>r)
    {
        return ;
    }
    pii idx = getmin(0,n-2,l,r,1);
    g[u].emplace_back(idx.fi);
    dfs0(l,idx.se-1,idx.fi);
    dfs0(idx.se+1,r,idx.fi);
}
void dfs1(int u)
{
    tin[u]=++times;
    pos[u]=times ;
    for(auto it:g[u])
    {
        dfs1(it);
    }
    tout[u]=times;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int x=0; /// x -> store idx of num 1 
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
        if(arr[i]==1)x=i ; 
    }
    if(n==1)
    {
        cout << "1 0" << '\n' ; 
        return 0 ;
    }
    for(int i=x+1;i<=n;i++)
    {
        V.emplace_back(arr[i]);
    }
    for(int i=1;i<x;i++)V.emplace_back(arr[i]);
    construct(0,n-2,1);
    dfs0(0,n-2,0);
    dfs1(0);
    for(int i=n-2;i>=0;i--)
    {
        int u = V[i] ; 
        update(1,n,tin[u],tout[u],1,1);
        int mx = getmax(1,n,1,n,1);
        R[i]=mx ;
    }
    for(int i=n-2;i>=0;i--)
    {
        int u = V[i];
        int mx = getmax(1,n,1,n,1);
        L[i]=mx ;
        update(1,n,tin[u],tout[u],-1,1);
    }
    pii ans = {R[0],0};
    for(int i=n-2;i>=0;i--)
    {
        ans=min(ans,{max(R[i+1],L[i]),i+1});
    }
    //printf("wtf %d \n",ans.se);
    cout << ans.fi+1 << " " << (ans.se+x)%n << '\n' ;
    return 0 ;
}