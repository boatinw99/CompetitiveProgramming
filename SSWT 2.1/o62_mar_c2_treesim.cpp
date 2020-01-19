#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
const ll pb = 98765431 ;
const int N = 4e5+9 ;
vector<int> g[N];
map<ll,int> vec1,vec2 ;
int cnt=0 ;
ll a[N],p[N],b[N];
ll all = 0 ;
void dfs0(int u,int v)
{
    if(g[u].size()==1)
    {
        a[u]=p[u];
    }
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs0(it,u);
            a[u]+=a[it];
        }
    }
    //printf("aa %d %lld %lld\n",u,a[u],all-a[u]);
    ///a[u]=min(a[u],all-a[u]);
    vec1[min(a[u],all-a[u])]++;
}
void dfs1(int u,int v)
{
    if(g[u].size()==1)b[u]=p[u];
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs1(it,u);
            b[u]+=b[it];
        }
    }
    //printf("bb %d %lld %lld\n",u,b[u],all-b[u]);
    ///b[u]=min(b[u],all-b[u]);
    vec2[min(b[u],all-b[u])]++;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n ;
    p[0]=1 ;
    for(i=1;i<N;i++)p[i]=p[i-1]*pb ;
    for(i=1;i<=n;i++)all+=p[i];
    for(i=1;i<=2*n-3;i++)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs0(1,1);
    for(i=1;i<=n;i++)while(g[i].size()!=1);
    for(i=0;i<N;i++)g[i].clear();
    for(i=1;i<=2*n-3;i++)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)while(g[i].size()!=1);
    dfs1(1,1);
    for(auto it:vec1)
    {
        cnt+=abs(it.se-vec2[it.fi]);
    }
    cout << cnt ;
}
