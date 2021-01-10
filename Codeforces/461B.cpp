#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , mod = 1e9+7 ;
vector<int> g[N];
int clr[N];
ll dp[N][2];
ll powap(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret = ret*ret%mod;
    if(p&1)ret=ret*a%mod;
    return ret ;
}
void dfs(int u,int v)
{
    dp[u][clr[u]]=1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs(it,u); 
            dp[u][clr[u]]*=(dp[it][0]+dp[it][1])%mod;
            dp[u][clr[u]]%=mod;
        }
    }
    if(clr[u]==0)
    {
        for(auto it:g[u])
        {
            if(it!=v)
            {
                dp[u][1]+=dp[it][1]*dp[u][clr[u]]%mod*powap((dp[it][0]+dp[it][1])%mod,mod-2)%mod;
                dp[u][1]%=mod ;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1,u ;i<n;i++)
    {
        cin >> u ;
        g[i].emplace_back(u);
        g[u].emplace_back(i);
    }
    for(int i=0;i<n;i++)cin >> clr[i];
    dfs(0,0);
    cout << dp[0][1] << '\n' ;
    return 0 ;
}