#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e6+9 ;
int deg[N],self[N];
int sz[N],par[N],cc ; 
pii edge[N];
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
void Union(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)return ;
    cc--;
    if(sz[u]<=sz[v])swap(u,v);
    sz[u]+=sz[v];
    par[v]=u ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,num=0; 
    cin >> n >> m ;
    cc = n ; 
    for(int i=1;i<=n;i++)sz[i]=1,par[i]=i;
    int ex = 0 ;
    for(int i=1,u,v ;i<=m;i++)
    {
        cin >> u >> v ;
        edge[i]={u,v};
        if(u==v)self[u]++,num++;
        else deg[u]++,deg[v]++;
        Union(u,v);
        ex = par[u];
    }
    for(int i=1;i<=m;i++)
    {
        int tmp = find(edge[i].fi);
        if(tmp!=ex)
        {
            cout << "0" << '\n' ;
            return 0 ;
        }
    }
    ll ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        ans+=1ll*deg[i]*(deg[i]-1);
        ans+=1ll*deg[i]*num;
        ans+=1ll*(num-1)*self[i];
    }
    cout << ans/2 << '\n' ;
    return 0 ;
}