#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+9 ; 
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
vector<pii> g[N]; 
ll dp[N][2];
int n,k ; 
void init()
{
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i][1]=0;
        g[i].clear();
    }
}
void dfs0(int u,int v)
{
    vector<int> V ; 
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            dfs0(it.fi,u);
            dp[u][0]+=dp[it.fi][0];
            dp[u][1]+=dp[it.fi][0];
            V.emplace_back(dp[it.fi][1]+it.se-dp[it.fi][0]);
        }
    }
    sort(V.begin(),V.end(),greater<int>());
    for(int i=0;i<V.size()&&i<k;i++)
    {
        if(V[i]>0)dp[u][0]+=V[i];
    }
    for(int i=0;i<V.size()&&i<k-1;i++)
    {
        if(V[i]>0)dp[u][1]+=V[i];
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--)
    {
        cin >> n >> k ;
        init();
        for(int i=1;i<n;i++)
        {
            int u,v,wi ;
            cin >> u >> v >> wi ;
            g[u].emplace_back(v,wi);
            g[v].emplace_back(u,wi);
        }
        dfs0(1,1);
        cout << dp[1][0] << '\n' ;
    }
    return 0 ;
}