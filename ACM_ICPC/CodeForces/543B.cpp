#include<bits/stdc++.h>
using namespace std ;
const int N = 3e3+9 ,inf =1e9 ;
vector<int> g[N]; 
queue<int> q ;
int dist[N];
int dp[N][N];
void bfs(int u)
{
    memset(dist,-1,sizeof dist);
    dist[u]=0 ;
    for(q.push(u);!q.empty();)
    {
        int x = q.front(); q.pop();
        dp[u][x]=dist[x];
        for(auto it:g[x])
        {
            if(dist[it]==-1)
            {
                dist[it]=dist[x]+1;
                q.push(it);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,s1,t1,l1,s2,t2,l2 ; 
    cin >> n >> m ;
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2 ;
    for(int i=1;i<=n;i++)bfs(i);
    int ans = inf ; 
    if(dp[s1][t1]<=l1&&dp[s2][t2]<=l2)
    {
        ans = dp[s1][t1]+dp[s2][t2] ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[s1][i]+dp[i][j]+dp[j][t1]<=l1&&(dp[s2][i]+dp[i][j]+dp[j][t2]<=l2||dp[s2][j]+dp[i][j]+dp[i][t2]<=l2))
            {
                ans=min(ans,dp[s1][i]+dp[j][t1]+dp[i][j]+min(dp[s2][i]+dp[j][t2],dp[s2][j]+dp[i][t2]));
            }
        }
    }
    cout << (ans==inf?-1:m-ans) << '\n' ; 
    return 0 ;
}