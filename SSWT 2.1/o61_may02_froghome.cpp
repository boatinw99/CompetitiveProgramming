#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
int a[19],k;
int dist[N],sub[N];
bool vst[N];
ll ans[N];
vector<int> g[N];
void dfs1(int u)
{
    vst[u]++;
    sub[u]=1;
    for(auto it:g[u])
    {
        if(vst[it]==0)
        {
            dfs1(it);
            sub[u]+=sub[it];
        }
    }
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&vst[it]==0&&sub[it]>sz/2)return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int cnt)
{
    vst[u]++;
    for(int i=1;i<=k;i++)
    {
        if(a[i]-cnt+1>0)
        {
            //printf("aa %d | %d %d\n",u,a[i],cnt);
            ans[i]+=1ll*dist[a[i]-cnt+1] ;
        }
    }
    for(auto it:g[u])if(vst[it]==0)dfs3(it,cnt+1);
    vst[u]=0;
}
void dfs4(int u,int cnt)
{
    vst[u]++;
    dist[cnt]++;
    for(auto it:g[u])if(vst[it]==0)dfs4(it,cnt+1);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    dist[1]++;
    for(auto it:g[ctd])
    {
        if(vst[it]==0)dfs3(it,1),dfs4(it,2);
    }
    for(int i=1;dist[i];i++)dist[i]=0;
   // return ;
    for(auto it:g[ctd])if(vst[it]==0)dcp(it);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v  ;
    cin >> n >> k ;
    for(i=1;i<=k;i++)cin >> a[i] ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dcp(1);
    for(i=1;i<=k;i++)cout << ans[i]*2 << '\n' ;
}
