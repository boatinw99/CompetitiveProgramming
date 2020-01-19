#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll inf = 1e17;
const int N = 3e5+9 ;
vector<pair<int,pii> > g[N];///it c m
ll dist[N],ans[N];
int n,x;
ll dfs0(int u,int v,ll cst)
{
    dist[u]=cst ;
    ll mx = dist[u];
    ans[u]=0 ;
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            ll ret = dfs0(it.fi,u,cst+it.se.fi+1ll*it.se.se*x);
            ans[u]=max(ans[u],mx+ret-2*dist[u]);
            mx=max(mx,ret);
        }
    }
    return mx ;
}
ll f(int times)
{
    x=times;
    dfs0(1,1,0);
    ll ret = 0 ;
    for(int i=1;i<=n;i++)ret=max(ret,ans[i]);
    return ret ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int D,u,v,c,m ;
    cin >> n >> D ;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v >> c >> m ;
        g[u].push_back({v,{c,m}});
        g[v].push_back({u,{c,m}});
    }
    int l = 0 , r = D ;
    while(l<r)f(mid)<=f(mid+1)?r=mid:l=mid+1;
    cout << l << '\n' << f(l) ;
    return 0 ;
}
