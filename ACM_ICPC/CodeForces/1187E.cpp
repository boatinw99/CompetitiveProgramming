#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 ;
vector<int> g[N];
int sub[N],n;
ll dp[N],ans = 0 ;
void dfs0(int u,int v)
{
    sub[u] = 1 ;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            sub[u]+=sub[it];
        }
    }
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dp[u]=max(dp[u],dp[it]+n-sub[it]-sub[u]);
        }
    }
    if(g[u].size()==1&&u!=1)
    {
        dp[u]=n-1;
    }
    ans+=sub[u];
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    cout << dp[1]+ans ;
    return 0 ;
}