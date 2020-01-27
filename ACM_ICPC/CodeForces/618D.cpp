#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 ; 
vector<int> g[N];
int dp[N][2];
void dfs0(int u,int v)
{
    vector<int> V ; 
    int all = 0 ;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            all+=dp[it][1];
            V.emplace_back(dp[it][0]-dp[it][1]);
        }
    }
    dp[u][0]=dp[u][1]=all+1;
    sort(V.begin(),V.end());
    if(!V.empty())
    {
        dp[u][0]=min(dp[u][0],all+V[0]);
        if(V.size()>1)
        {
            dp[u][1]=all+V[0]+V[1]-1;
        }
    }
    dp[u][1]=min(dp[u][0],dp[u][1]);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,x,y ; 
    cin >> n >> x >> y ;
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    bool star = 0 ;
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==n-1)star++;
    }
    dfs0(1,1);
    int num = dp[1][1]; /// 0 is non-used 1 is used  

    ll ans = 0 ;
    if(star)ans = 1ll*(n-2)*y+x;
    else ans = 1ll*(n-1)*y ; 
    ans = min(ans,1ll*(num-1)*y+1ll*(n-num)*x);
    cout << ans << '\n' ;
    return 0 ;
}