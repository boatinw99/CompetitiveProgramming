#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
vector<int> g[N];
int a[N],sub[N],tin[N],tout[N],times=1,odr[N];
map<int,int> mp ;
ll ans=0 ;
void dfs0(int u,int v)
{
    sub[u]=1;
    odr[times]=u;
    tin[u]=times++;
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it];
    tout[u]=times ;
}
void dfs1(int u,int v,bool kp)
{
    int mx=0,hc=0;///heavy child
    for(auto it:g[u])if(it!=v&&sub[it]>mx)mx=sub[it],hc=it;
    for(auto it:g[u])if(it!=v&&it!=hc)dfs1(it,u,0);
    if(hc)dfs1(hc,u,1);
    ans+=mp[1];
    mp[a[u]]++;
    for(auto it:g[u])if(it!=v&&it!=hc)
    {
        for(int i=tin[it];i<tout[it];i++)
            if(a[u]%a[odr[i]]==0)ans+=mp[a[u]/a[odr[i]]];
        for(int i=tin[it];i<tout[it];i++)mp[a[odr[i]]]++;
    }
    if(!kp)
    {
        for(int i=tin[u];i<tout[u];i++)
        {
            mp[a[odr[i]]]--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)cin >> a[i];
    dfs0(1,0),dfs1(1,0,1);
    cout << ans ;
}
