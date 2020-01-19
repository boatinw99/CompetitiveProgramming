#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const int N = 2e5+9 , mod = 998244353 ; 
vector<int> g[N];
int dp[N],sub[N],fact[N],deg[N];
void dfs0(int u,int v)
{
    sub[u]=1;
    dp[u]=1;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            sub[u]+=sub[it];
            dp[u]=dp[u]*1ll*dp[it]%mod ; 
        }
    }
    deg[u]=g[u].size();
    if(u==1)deg[u]--; 
    dp[u]=dp[u]*1ll*fact[deg[u]]%mod;
    //printf("chk = %d %d %d \n",u,f[u],sub[u]);
}
void precomp()
{
    fact[0]=1 ;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*1ll*i%mod ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    precomp();
    g[1].emplace_back(0);
    for(int i=1;i<n;i++)
    {
        int u,v ; 
        cin >> u >> v ; 
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,0);
    cout << 1ll*n*dp[1]%mod << '\n' ;
    return 0 ;
}