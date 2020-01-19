#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
vector<pair<int,pii> > g ;
int par[N],rnk[N];
int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
bool Union(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py)return 0 ;
    if(rnk[x]>=rnk[y])rnk[x]+=rnk[y],par[py]=px;
    else rnk[y]+=rnk[x],par[px]=py ;
    return 1;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,u,v,x,i,j,ans=0 ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> x ;
        g.push_back({x,{u,v}});
    }
    for(i=1;i<=n;i++)par[i]=i;
    sort(g.begin(),g.end());
    for(i=0;i<m;)
    {
        int cnt=0;
        for(j=i;j<m&&g[j].fi==g[i].fi;j++)
        {
            int px=find(g[j].se.fi),py=find(g[j].se.se);
            if(px!=py)
            {
                cnt++;
            }
        }
        int times=0;
        for(;i<j;i++)
        {
            times+=Union(g[i].se.fi,g[i].se.se);
        }
        ans+=cnt-times;
    }
    cout << ans ;
}
