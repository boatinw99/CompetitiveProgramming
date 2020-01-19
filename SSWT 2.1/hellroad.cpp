#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1009;
int rnk[N],par[N],cc;
ll mst=0;
vector<pair<int,pii> > g ;
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int u,int v)
{
    int pu=find(u),pv=find(v);
    if(pu==pv)return 0;
    cc--;
    if(rnk[pu]>=rnk[pv])rnk[pu]+=rnk[pv],par[pv]=pu;
    else rnk[pv]+=rnk[pu],par[pu]=pv;
    return 1;
}
void process(int cst)
{
    for(auto it:g)
    {
        if(it.fi>=cst&&Union(it.se.fi,it.se.se))
        {
            mst+=it.fi;
        }
    }
}
main()
{
    int n,M,i,j,u,v,wi ;
    cin >> n >> M ;
    int l=0,r=M;
    for(i=1;i<=n*(n-1)/2;i++)
    {
        cin >> u >> v >> wi ;
        g.push_back({wi,{u,v}});
    }
    sort(g.begin(),g.end());
    while(l+1<r)
    {
        int mid=l+r>>1;
        cc=n-1,mst=0;
        for(i=1;i<=n;i++)rnk[i]=1,par[i]=i;
        process(mid);
        if(cc==0&&mst<=M)l=mid;
        else r=mid;
    }
    cout << l ;
}
