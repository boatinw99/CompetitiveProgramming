#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 300009;
vector<int> g[N];
vector<int> ch ;
int a,b,dp[N];
int dfs0(int u,int v)
{
    if(u==a)
    {
        ch.emplace_back(u);
        return 1 ;
    }
    for(auto it:g[u])
    {
        if(it!=v)
        {
            int ret = dfs0(it,u);
            if(ret)
            {
                ch.emplace_back(u);
                return ret ;
            }
        }
    }
    return 0 ;
}
void dfs1(int u,int v,int ed)
{
    if(u==ed)return ;
    for(auto it:g[u])if(it!=v)dfs1(it,u,ed);
    vector<int> times ;
    for(auto it:g[u])if(it!=v&&it!=ed)times.emplace_back(dp[it]);
    sort(times.begin(),times.end(),greater<int>());
    int mx = 0,add=1;
    for(auto it:times)
    {
        mx=max(mx,it+add);
        add++;
    }
    dp[u]=mx ;
}
pii query(int x)
{
    memset(dp,0,sizeof dp);
    int ans = 0 ;
    dfs1(a,a,ch[x]);
    dfs1(b,b,ch[x-1]);
    return {dp[a],dp[b]};
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n >> a >> b ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(b,b);
    int l=1,r=ch.size();
    int ans = INT_MAX ;
    while(l<r)
    {
        pii f = query(mid);
        if(f.fi<f.se)l=mid+1;
        else r=mid ;
    }
    pii f = query(l);
    ans=min(ans,max(f.fi,f.se));
    int add = 1 ;
    if(f.fi>f.se)add=-1;
    f = query(l+add);
    ans=min(ans,max(f.fi,f.se));
    cout << ans ;
}
