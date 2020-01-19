#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll MAX = 1e17 ;
const int N = 3e5+9 ;
ll all = 0,ans = MAX ,val[N],a[N];
int sub[N],tin[N],tout[N],times=1,pos[N];
vector<int> g[N];
multiset<ll> mt ;
ll dist(ll x,ll y,ll z)
{
    return max({x,y,z})-min({x,y,z});
}
ll getans(ll c)
{
    if(mt.empty())return MAX ;
    auto it = mt.lower_bound(all+c>>1);
    if(it==mt.begin())return dist(all-*it,c,*it-c) ;
    else
    {
        ll tmp = MAX ;
        if(it!=mt.end())tmp = dist(all-*it,c,*it-c);
        it--;
        return min(tmp,dist(all-*it,c,*it-c));
    }
}
ll getsum2(ll c)
{
    if(mt.empty())return MAX ;
    auto it = mt.lower_bound(all-c>>1);
    if(it==mt.begin())return dist(all-*it-c,c,*it);
    else
    {
        ll tmp = MAX ;
        if(it!=mt.end())tmp = dist(all-*it-c,c,*it);
        it--;
        return min(tmp,dist(all-*it-c,c,*it));
    }
}
void dfs0(int u,int v)
{
    sub[u]=1;
    tin[u]=++times ;
    pos[times]=u ;
    val[u]=a[u];
    for(auto it:g[u])if(it!=v)dfs0(it,u),sub[u]+=sub[it],val[u]+=val[it];
    tout[u]=times ;
}
void dfs1(int u,int v)
{
    for(auto it:g[u])
    {
        if(it!=v)
        {
            ///compute
            ans=min(ans,getans(val[it]));
            ///assign
            mt.insert(val[it]);
            dfs1(it,u);
            auto its = mt.lower_bound(val[it]);
            mt.erase(its);
        }
    }
}
void dfs2(int u,int v,bool kp)
{
    int mx=0,tmp = 0 ;
    for(auto it:g[u])if(it!=v&&sub[it]>mx)mx=sub[it],tmp=it ;
    for(auto it:g[u])if(it!=v&&it!=tmp)dfs2(it,u,0);
    if(tmp)dfs2(tmp,u,1);
    ///
    for(auto it:g[u])if(it!=tmp&&it!=v)
    {
        for(int i=tin[it];i<=tout[it];i++)ans=min(ans,getsum2(val[pos[i]]));
        for(int i=tin[it];i<=tout[it];i++)mt.insert(val[pos[i]]);
    }
    mt.insert(val[u]);
    if(!kp)mt.clear();
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    all = val[1];
    dfs1(1,1);
    dfs2(1,1,1);
    cout << ans ;
}
