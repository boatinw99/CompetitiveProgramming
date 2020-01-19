#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 209 ;
set<pair<int,pii> > s;
int par[N],rnk[N];
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int u,int v)
{
    int pu = find(u),pv = find(v);
    if(pu==pv)return 0 ;
    if(rnk[pu]>=rnk[pv])rnk[pu]+=rnk[pv],par[pv]=pu;
    else rnk[pv]+=rnk[pu],par[pu]=pv ;
    return 1;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,x;
    cin >> n >> m;
    while(m--)
    {
        int ans = 0,cc=n;
        cin >> u >> v >> x ;
        s.insert({x,{u,v}});
        for(i=1;i<=n;i++)
        {
            par[i]=i ;
            rnk[i]=0 ;
        }
        for(auto it:s)if(Union(it.se.fi,it.se.se))ans+=it.fi,cc--;
        cout << (cc==1?ans:-1) << '\n' ;
    }
}
