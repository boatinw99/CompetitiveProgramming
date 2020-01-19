#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ,mod = 998244353 ;
vector<int> g[N];
int dp[N][3];
void dfs0(int u)
{
    int tmp[3]={1,0,0};
    if(g[u].empty())
    {
        dp[u][2]=1;
        return ;
    }
    for(auto it:g[u])
    {
        dfs0(it);
        dp[u][0] = tmp[0]*1ll*(dp[it][0]+dp[it][2])%mod ;
        dp[u][1] = (tmp[1]*1ll*(dp[it][0]+dp[it][2])%mod
                    +tmp[0]*1ll*(dp[it][1]+dp[it][2])%mod)%mod;
        dp[u][2] = (tmp[2]*1ll*(dp[it][0]+dp[it][2])%mod
                    +tmp[1]*1ll*(dp[it][1]+dp[it][2])%mod
                    +tmp[2]*1ll*(dp[it][1]+dp[it][2])%mod)%mod;
        for(int i=0;i<3;i++)tmp[i]=dp[u][i];
        ///printf("chk node = %d %d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2]);
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=2,x ;i<=n;i++)
    {
        cin >> x ;
        g[x].emplace_back(i);
    }
    dfs0(1);
    cout << (dp[1][0]+dp[1][2])%mod;
    return 0 ;
}
