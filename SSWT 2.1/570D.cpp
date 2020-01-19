#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 5e5+9 ;
vector<int> g[N];
vector<pii> query[N];
int cnt[N],a[N],tin[N],tout[N],odr[N],depth[N],sub[N],times=1;///dfs-order
bool ans[N];
bool findans(int h)
{
    if(cnt[h]==0)return 1 ;
    for(int i=0;i<26;i++)
    {
        if(cnt[h]==(1<<i))return 1;
    }
    return 0 ;
}
void dfs0(int u)
{
    sub[u]=1;
    odr[times]=u;
    tin[u]=times++;
    for(auto it:g[u])depth[it]=depth[u]+1,dfs0(it),sub[u]+=sub[it];
    tout[u]=times ;
}
void dfs1(int u,bool kp)
{
    int mx=0,hy=0 ;
    for(auto it:g[u])if(sub[it]>mx)mx=sub[it],hy=it;
    for(auto it:g[u])if(it!=hy)dfs1(it,0);
    if(hy)dfs1(hy,1);
    cnt[depth[u]]^=a[u];
    for(auto it:g[u])if(it!=hy)
    {
        for(int i=tin[it];i<tout[it];i++)
        {
            cnt[depth[odr[i]]]^=a[odr[i]];
        }
    }
    for(auto it:query[u])
    {
        ans[it.se]=findans(it.fi);
    }
    if(!kp)
    {
        for(int i=tin[u];i<tout[u];i++)
        {
            cnt[depth[odr[i]]]^=a[odr[i]];
        }
    }

}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,i,j,u,v,h ;
    char c ;
    cin >> n >> m ;
    for(i=2;i<=n;i++)
    {
        cin >> u ;
        g[u].emplace_back(i);
    }
    for(i=1;i<=n;i++)
    {
        cin >> c ;
        a[i]=1<<(c-'a');
    }
    for(i=1;i<=m;i++)
    {
        cin >> v >> h ;
        query[v].emplace_back(h,i);
    }
    depth[1]=1;
    dfs0(1),dfs1(1,1);
    for(i=1;i<=m;i++)
    {
        if(ans[i])cout << "Yes" << '\n' ;
        else cout << "No" << '\n' ;
    }
}
