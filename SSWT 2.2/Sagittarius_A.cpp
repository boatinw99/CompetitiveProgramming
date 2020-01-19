#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
vector<int> V ;
vector<pii> edge ;
int p[N],rnk[N];
pii E[N];
int find(int u)
{
    return u==p[u]?u:p[u]=find(p[u]);
}
bool Union(int u,int v)
{
    u=find(u),v=find(v);
    if(u==v)return 0 ;
    if(rnk[u]>rnk[v])swap(u,v);
    p[u]=v;
    rnk[v]+=rnk[u];
    return 1 ;
}
int main()
{
    int n,m,cc,t;
    ll ans = 0;
    bool mx=0;
    cin >> n >> m ;
    cc=n ;
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,x ;
        cin >> E[i].fi >> E[i].se >> x ;
        edge.push_back({x,i});
    }
    cin >> t ;
    sort(edge.begin(),edge.end(),greater<pii>());
    for(auto it:edge)
    {
        int val = it.fi , u = E[it.se].fi , v = E[it.se].se;
        int ret = Union(u,v);
        if(ret==1)
        {
            cc--;
            ans+=val;
            V.emplace_back(it.se);
            ///printf("aa %d %d \n");
        }
        else if(!mx)
        {
            ans+=val;
            mx++;
            V.emplace_back(it.se);
        }
    }
    if(cc==1&&mx)
    {
        cout << ans << '\n' ;
        if(t==2)for(auto it:V)cout << it << " " ;
        return 0 ;
    }
    cout << "-1" << '\n' ;
    return 0 ;
}
