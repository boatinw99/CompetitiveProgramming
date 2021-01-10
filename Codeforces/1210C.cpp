#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
#define fi first
#define se second 
const int N = 1e5+9 , mod = 1e9+7 ; 
int n ; 
ll val[N],ans = 0 ;
map<ll,int> mp[N];
vector<int> g[N];
void dfs0(int u,int v)
{
    mp[u][val[u]]++;
    for(auto it:mp[v])
    {
        mp[u][__gcd(it.fi,val[u])]+=it.se;
    }
    for(auto it:mp[u])ans+=it.fi*it.se,ans%=mod;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> val[i] ; 
    }
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,0);
    cout << ans << '\n' ; 
    return 0 ;
}