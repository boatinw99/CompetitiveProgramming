#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9,LOG=log2(N)+1 ;
vector<int> g[N];
int up[N][LOG],min1[N][LOG],depth[N],a[N];
ll dp[N];
int minlift(int u)
{
    int tmp=a[u];
    for(int i=LOG-1;i>=0;i--)if(min1[u][i]>=tmp)u=up[u][i];
    return u ;
}
void dfs(int u)
{
    min1[u][0]=a[up[u][0]];
    depth[u]=depth[up[u][0]]+1;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        min1[u][i]=min(min1[u][i-1],min1[up[u][i-1]][i-1]);
    }
    int v = minlift(u);
    dp[u]=dp[up[v][0]]+1ll*a[u]*(depth[u]-depth[v]+1);
    for(auto it:g[u])if(it!=up[u][0])dfs(it);
}
main()
{
    int n,i,j ;
    cin >> n ;
    for(i=2;i<=n;i++)
    {
        cin >> up[i][0];
        g[up[i][0]].emplace_back(i);
    }
    for(i=1;i<=n;i++)cin >> a[i];
    a[0]=INT_MIN;
    dfs(1);
    for(i=1;i<=n;i++)cout << dp[i] << " " ;
}
