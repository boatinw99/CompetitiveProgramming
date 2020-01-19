#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
vector<pii> l,r,u,d ;
vector<pair<ll,pii> > edge;
const int N = 1e5+9;
int root,par[N],rnk[N] ;
ll ans=0 ;
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
ll dist(pii x1,pii x2)
{
    ll ret = 1ll*(x1.fi-x2.fi)*(x1.fi-x2.fi)+1ll*(x1.se-x2.se)*(x1.se-x2.se);
    while(ret<=0);
    return ret ;
}
void pre_(vector<pii> &t)
{
    if(t.empty())return ;
    sort(t.begin(),t.end());
    for(int i=0;(int)i<t.size()-1;i++)
    {
        edge.push_back({1ll*(t[i].fi-t[i+1].fi)*(t[i].fi-t[i+1].fi),
                       {t[i].se,t[i+1].se}});
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,w,h,i,j,x,y,p1,p2 ;
    cin >> n >> w >> h ;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y ;
        if(x==0)l.push_back({y,i});
        else if(x==w)r.push_back({y,i});
        else if(y==0)d.push_back({x,i});
        else if(y==h)u.push_back({x,i});
        else
        {
            root=i ;
            p1=x;
            p2=y ;
        }
    }
    pre_(l),pre_(r),pre_(u),pre_(d);
    if(root)
    {
        for(auto it:l)edge.push_back({dist({0,it.fi},{p1,p2}),{root,it.se}});
        for(auto it:r)edge.push_back({dist({w,it.fi},{p1,p2}),{root,it.se}});
        for(auto it:u)edge.push_back({dist({it.fi,h},{p1,p2}),{root,it.se}});
        for(auto it:d)edge.push_back({dist({it.fi,0},{p1,p2}),{root,it.se}});
    }
    if(!l.empty()&&!u.empty())
        edge.push_back({dist({0,l.back().fi},{u[0].fi,h}),{l.back().se,u[0].se}});
    if(!l.empty()&&!d.empty())
        edge.push_back({dist({0,l[0].fi},{d[0].fi,0}),{l[0].se,d[0].se}});
    if(!r.empty()&&!u.empty())
        edge.push_back({dist({w,r.back().fi},{u.back().fi,h}),
                       {r.back().se,u.back().se}});
    if(!r.empty()&&!d.empty())
        edge.push_back({dist({w,r[0].fi},{d.back().fi,0}),
                       {r[0].se,d.back().se}});
    if(!r.empty())
    {
        for(auto it:l)
        {
            auto it1 = lower_bound(r.begin(),r.end(),make_pair(it.fi,0));
            if(it1!=r.end())
            {
                edge.push_back({dist({0,it.fi},{w,it1->fi}),{it.se,it1->se}});
            }
            if(it1!=r.begin())
            {
                it1-- ;
                edge.push_back({dist({0,it.fi},{w,it1->fi}),{it.se,it1->se}});
            }
        }
    }
    if(!d.empty())
    {
        for(auto it:u)
        {
            auto it1 = lower_bound(d.begin(),d.end(),make_pair(it.fi,0));
            if(it1!=d.end())
            {
                edge.push_back({dist({0,it.fi},{h,it1->fi}),{it.se,it1->se}});
            }
            if(it1!=d.begin())
            {
                it1-- ;
                edge.push_back({dist({0,it.fi},{h,it1->fi}),{it.se,it1->se}});
            }
        }
    }
    for(i=1;i<=n;i++)par[i]=i;
    sort(edge.begin(),edge.end());
    for(auto it:edge)
    {
        while(it.fi<=0);
        if(Union(it.se.fi,it.se.se))ans+=it.fi ;
    }
    cout << ans ;
}
