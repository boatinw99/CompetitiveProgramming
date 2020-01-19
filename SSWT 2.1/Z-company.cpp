#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<pii> g[N];
ll dp1[N],dp2[N];
void dfs(int u)
{
    for(auto it:g[u])
    {
        dp1[it.fi]=it.se ;
        dfs(it.fi);
        dp1[u]+=dp2[it.fi];
        dp2[u]+=dp1[it.fi];
    }
    dp1[u]=max(dp1[u],dp2[u]);
}
main()
{
    int n,i,j,u,x ;
    cin >> n ;
    cin >> dp1[0];
    for(i=1;i<n;i++)
    {
        cin >> u >> x ;
        g[u].emplace_back(i,x);
    }
    dfs(0);
    cout << dp1[0] << '\n' ;
}
