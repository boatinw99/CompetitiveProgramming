#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
vector<int> g[N];
ll cnt[N];
int a[N],sub[N],tin[N],tout[N],pos[N],times=1,mxc=0;
ll ans=0,p[N];
/// a[] - > color
void update(int i)
{
    cnt[a[pos[i]]]++;
    if(cnt[a[pos[i]]]>mxc)mxc=cnt[a[pos[i]]],ans=a[pos[i]];
    else if(cnt[a[pos[i]]]==mxc)ans+=a[pos[i]];
}
void dfs1(int u,int v)
{
    sub[u]=1;
    pos[times]=u ;
    tin[u]=times++ ;
    for(auto it:g[u])if(it!=v)dfs1(it,u),sub[u]+=sub[it];
    tout[u]=times;
}
void dfs2(int u,int v,bool kp)
{
    int mx=0,hy=0;
    for(auto it:g[u])if(it!=v&&sub[it]>mx)mx=sub[it],hy=it ;
    for(auto it:g[u])if(it!=v&&it!=hy)dfs2(it,u,0);
    if(hy)dfs2(hy,u,1);
    update(tin[u]);
    for(auto it:g[u])if(it!=v&&it!=hy)
    {
        for(int i=tin[it];i<tout[it];i++)update(i);
    }
    p[u]=ans;
    if(!kp)
    {
        mxc=0,ans=0;
        for(int i=tin[u];i<tout[u];i++)cnt[a[pos[i]]]--;
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    for(i=1;i<=n;i++)cout << p[i] << " " ;
}
