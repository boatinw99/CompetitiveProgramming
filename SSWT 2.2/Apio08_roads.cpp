#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e4+9 ;
int par[N],rnk[N];
vector<pair<pii,int> > ans ;
vector<int> g[N][2];
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int u,int v)
{
    int pu=find(u),pv=find(v);
    if(pu==pv)return 0 ;
    if(rnk[pu]>=rnk[pv])rnk[pu]+=rnk[pv],par[pv]=pu ;
    else rnk[pv]+=rnk[pu],par[pu]=pv ;
    return 1 ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,k,u,v,typ ;
    cin >> n >> m >> k ;
    int cc = n ;
    for(i=1;i<=n;i++)par[i]=i ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> typ ;
        g[u][typ].emplace_back(v);
        ///g[v][typ].emplace_back(u);
    }
    for(i=1;i<=n;i++)
    {
        for(auto it:g[i][1])
        {
            if(Union(i,it))
            {
                cc--;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(auto it:g[i][0])
        {
            if(Union(i,it))
            {
                ans.push_back({{i,it},0});
                cc-- ;
                k--;
            }
        }
    }
    for(i=1;i<=n;i++)par[i]=i,rnk[i]=0;
    if(cc!=1||k<0)
    {
        cout << "no solution" ;
        return 0 ;
    }
    cc=n ;
    for(auto it:ans)
    {
        Union(it.fi.fi,it.fi.se);
        cc-- ;
    }
    for(i=1;i<=n&&k>0;i++)
    {
        for(auto it:g[i][0])
        {
            if(Union(i,it))
            {
                ans.push_back({{i,it},0});
                cc--;
                k--;
            }
            if(k==0)break;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(auto it:g[i][1])
        {
            if(Union(i,it))
            {
                ans.push_back({{i,it},1});
                cc--;
            }
        }
    }
    if(cc!=1||k!=0)
    {
        cout << "no solution" ;
        return 0 ;
    }
    for(auto it:ans)
    {
        cout << it.fi.fi << " " << it.fi.se << " " << it.se << '\n' ;
    }
}
