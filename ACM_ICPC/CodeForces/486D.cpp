#include<bits/stdc++.h>
using namespace std ;
const int N = 2e3+9 , mod = 1e9+7 , inf = 1e9 ; 
vector<int> V,g[N];
int a[N],dp[N],d;
void dfs0(int u,int v,int cst)
{
    int possi = 1 ; 
    for(auto it:g[u])
    {
        if(it!=v&&a[it]-cst<=d&&a[it]<inf)
        {
            dfs0(it,u,cst);
            possi=possi*1ll*dp[it]%mod ; 
        }
    }
    possi++;
    dp[u]=possi%mod ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> d >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
        V.emplace_back(i);
    }
    for(int i=1;i<n;i++)
    {
        int u,v ; 
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    sort(V.begin(),V.end(),[&](int l,int r){
        return  a[l]<a[r];
    });
    int ans = 0 ;
    for(auto it:V)
    {
        dfs0(it,it,a[it]);
        ans=(ans+(dp[it]-1+mod)%mod)%mod;
        a[it]=inf ;
    }
    cout << ans << '\n' ;
    return 0 ;
}