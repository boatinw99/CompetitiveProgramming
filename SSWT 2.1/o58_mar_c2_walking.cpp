#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9,MAX=1e9,K=1e6+1009;
vector<int> g[N];
int a[N],dp[K],sub[N],n,st[K*4],k;
int ans = MAX ;
bool vst[N];
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=MAX;
        return ;
    }
    construct(l,mid,m<<1),construct(mid+1,r,m<<1|1);
    st[m]=MAX;
}
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=cst;
        return ;
    }
    update(l,mid,x,cst,m<<1),update(mid+1,r,x,cst,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return MAX ;
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m<<1),findmin(mid+1,r,x,y,m<<1|1));
}
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs1(it),sub[u]+=sub[it];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(!vst[it]&&it!=v&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int len,int cst)
{
    if(cst>K)return ;
    cst+=a[u];
    int tmp = findmin(0,K-1,k-cst,K-1,1);
    ans=min(ans,tmp+len);
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs3(it,len+1,cst);
    vst[u]=0;
}
void dfs4(int u,int len,int cst)
{
    if(cst>K)return ;
    cst+=a[u];
    dp[cst]=min(dp[cst],len);
    update(0,K-1,cst,dp[cst],1);
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs4(it,len+1,cst);
    vst[u]=0;
}
void dfs5(int u,int len,int cst)
{
    if(cst>K)return ;
    cst+=a[u];
    dp[cst]=MAX ;
    update(0,K-1,cst,dp[cst],1);
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs5(it,len+1,cst);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd=dfs2(u,u,sub[u]);
    vst[ctd]++;
    dp[a[ctd]]=0;
    update(0,K-1,a[ctd],dp[a[ctd]],1);
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            dfs3(it,1,0);
            dfs4(it,1,a[ctd]);
        }
    }
    for(auto it:g[ctd])
    {
        if(!vst[it])dfs5(it,1,a[ctd]);
    }
    dp[a[ctd]]=MAX ;
    update(0,K-1,a[ctd],dp[a[ctd]],1);
    for(auto it:g[ctd])if(!vst[it])dcp(it);
}
main()
{
    int i,j,u,v ;
    cin >> n >> k ;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    construct(0,K-1,1);
    for(i=0;i<K;i++)dp[i]=MAX;
    dcp(0);
    if(ans<MAX)cout << ans ;
    else cout << -1 ;
}
