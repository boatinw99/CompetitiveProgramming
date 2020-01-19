#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , mod = 1e9+7 ;
vector<int> g[N];
int n,sub[N],fact[N],inv[N],ans = 0 ;
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    int ret = pow2(a,p>>1);
    ret = 1ll*ret*ret%mod ;
    if(p&1)ret=1ll*ret*a%mod ;
    return ret ;
}
void dfs0(int u,int v)
{
    sub[u]=1;
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it] ;
}
void dfs1(int u,int v,int add)
{
    ans=(ans+add)%mod;
    for(auto it:g[u])if(it!=v)dfs1(it,u,1ll*add*sub[it]%mod*inv[n-sub[it]]%mod);
}
int main()
{
    cin >> n ;
    int u,v ;
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*1ll*i%mod ;
    for(int i=1;i<N;i++)inv[i]=pow2(i,mod-2);
    for(int i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    int add = fact[n] ;
    for(int i=1;i<=n;i++)add=1ll*add*inv[sub[i]]%mod;
    dfs1(1,1,add);
    cout << ans ;
    return 0 ;
}
