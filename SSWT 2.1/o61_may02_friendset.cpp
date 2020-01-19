#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
const int N = 1e5+9 ;
const ll pb = 98765431 ;
map<ll,int> mp1,mp2 ;
ll pi[N];
ll val1[N],val2[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m,u,v ;
    cin >> n >> m ;
    pi[0]=1;
    for(i=1;i<=n;i++)pi[i]=pi[i-1]*pb ;
    for(i=1;i<=n;i++)
    {
        val2[i]=pi[i];
    }
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        val1[u]+=pi[v];
        val2[u]+=pi[v];
        val1[v]+=pi[u];
        val2[v]+=pi[u];
    }
    for(i=1;i<=n;i++)
    {
        mp1[val1[i]]++;
        mp2[val2[i]]++;
    }
    ll ans=0 ;
    for(auto it:mp1)
    {
        ans+=it.se*(it.se-1)/2;
    }
    for(auto it:mp2)ans+=it.se*(it.se-1)/2;
    cout << ans ;

}
