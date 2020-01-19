#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ,M = 1e6+9 ;
vector<pii> g[N];
ll cnt[N];
int edge[N],sub[N],val[N],f1[M],f2[M],tin[N],tout[N],pos[N],ind[N],times=0 ;
bool vst[N];
int n ;
void update(int *f,int i,int cst)
{
    if(i<=0)return ;
    for(;i<M;i+=i&-i)f[i]+=cst;
}
int getsum(int *f,int i)
{
    int x = 0 ;
    for(;i;i-=i&-i)x+=f[i];
    return x ;
}
void dfs1(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])if(!vst[it.fi])dfs1(it.fi),sub[u]+=sub[it.fi];
    vst[u]=0 ;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it.fi!=v&&!vst[it.fi]&&sub[it.fi]>sz/2)
        return dfs2(it.fi,u,sz);
    return u ;
}
void dfs3(int u,int mx,int cst)
{
    vst[u]++;
    val[u]=mx ;
    if(ind[u])update(f1,mx,cst);
    for(auto it:g[u])if(!vst[it.fi])dfs3(it.fi,max(mx,edge[it.se]),cst);
    vst[u]=0;
}
void dfs4(int u,int v,int idx,int mx,bool kp)/// node NumOfEdge mx keep
{
    mx=max(mx,edge[idx]);
    int tmp=-1,mxs=0,idx1;///mxsub
    for(auto it:g[u])if(it.fi!=v&&sub[it.fi]>mxs&&!vst[it.fi])
        mxs=sub[it.fi],tmp=it.fi,idx1=it.se ;
    for(auto it:g[u])if(it.fi!=tmp&&it.fi!=v&&!vst[it.fi])dfs4(it.fi,u,it.se,mx,0);
    if(mxs)dfs4(tmp,u,idx1,mx,1);
    for(auto it:g[u])if(it.fi!=tmp&&it.fi!=v&&!vst[it.fi])
    {
        for(int i=tin[it.fi];i<=tout[it.fi];i++)
        {
            if(ind[pos[i]])update(f2,val[pos[i]],1);
        }
    }
    if(ind[u])update(f2,val[u],1);
    if(edge[idx]==mx)cnt[idx]+=1ll*getsum(f2,mx)*getsum(f1,mx);
    if(!kp)for(int i=tin[u];i<=tout[u];i++)
        if(ind[pos[i]])update(f2,val[pos[i]],-1);
}
void dfs5(int u)
{
    vst[u]++;
    sub[u]=1;
    tin[u]=++times;
    pos[times]=u ;
    for(auto it:g[u])if(!vst[it.fi])dfs5(it.fi),sub[u]+=sub[it.fi];
    tout[u]=times ;
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    dfs3(ctd,1,1);
    dfs5(ctd);
    vst[ctd]++;
    for(auto it:g[ctd])
    {
        if(!vst[it.fi])
        {
            dfs3(it.fi,edge[it.se],-1);
            dfs4(it.fi,ctd,it.se,1,0);
            dfs3(it.fi,edge[it.se],1);
        }
    }
    dfs3(ctd,1,-1);
    vst[ctd]++;
    times=0 ;
    for(auto it:g[ctd])if(!vst[it.fi])dcp(it.fi);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,x,u,v ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> u ;
        ind[u]++;
    }
    for(i=0;i<n-1;i++)
    {
        cin >> u >> v >> edge[i] ;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    dcp(0);
    int num = 0 ;
    ll ans =0 ;
    for(i=0;i<n-1;i++)
    {
        if(cnt[i]>ans)ans=cnt[i],num=1 ;
        else if(cnt[i]==ans)num++;
    }
    cout << num << " " << ans << '\n' ;
    for(i=0;i<n-1;i++)if(ans==cnt[i])cout << i << " " ;
}
