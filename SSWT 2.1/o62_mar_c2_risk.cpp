#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
vector<pii> p1,p2;
vector<pii> hull1,hull2 ;
int ans = 0 ,n  ;
long double dist(pii lhs,pii rhs)
{
    ll d = (lhs.fi-rhs.fi)*(lhs.fi-rhs.fi)+(lhs.se-rhs.se)*(lhs.se-rhs.se);
    return (long double)sqrt(d);
}
int drc(pii a,pii b,pii c)
{
    pii vec1(b.fi-a.fi,b.se-a.se),vec2(c.fi-a.fi,c.se-a.se);
    if(vec1.fi*vec2.se-vec2.fi*vec1.se>0)return 1;
    else if(vec1.fi*vec2.se-vec2.fi*vec1.se==0)return 0 ;
    else return 2 ;
}
void construct(vector<pii> &p ,vector<pii> &hull)
{
    sort(p.begin(),p.end(),[&](pii a,pii b){
        if(a.se!=b.se)return a.se>b.se ;
        return a.fi>b.fi ;
        });
    pii stt = p.back();
    p.pop_back();
    sort(p.begin(),p.end(),[&](pii a,pii b){
         int di = drc(stt,a,b);
         if(di==0)return dist(stt,a)<dist(stt,b);
         return di==2 ;
         });
    hull.push_back(stt);
    hull.push_back(p[0]);
    for(int i=1;i<p.size();i++)
    {
        while((hull.size()>1)&&drc(hull[hull.size()-2],hull.back(),p[i])!=2)
            hull.pop_back();
        hull.push_back(p[i]);
    }
    p.push_back(stt);
}
int inside(pii nw,vector<pii> &hull,vector<pii> &p)
{
    int sz=hull.size();
    auto it = lower_bound(p.begin(),p.end(),nw);
    if(it!=p.end()&&*it==nw)return 1 ;
    int l=1,r=sz-1 ;
    pii str = hull[0];
    while(l<r)
    {
        int dl=drc(str,hull[mid],nw),dr=drc(str,hull[mid+1],nw);
        int d = drc(hull[mid+1],hull[mid],nw) ;
        if((dl==0||dl==2)&&(d==1||d==0)&&(dr==1||dr==0))return 1 ;
        else if(dl==1)r=mid ;
        else l=mid+1;
    }
    return 0 ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,u,v ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> u >> v ;
        p1.push_back({u,v});
    }
    construct(p1,hull1);
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        p2.push_back({u,v});
    }
    construct(p2,hull2) ;
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    for(auto it:p1)if(inside(it,hull2,p2))ans++;
    for(auto it:p2)if(inside(it,hull1,p1))ans++;
    cout << ans ;

}
