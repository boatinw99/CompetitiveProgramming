
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pii ;
#define fi first
#define se second
vector<pii> p1,p2;
vector<pii> hull1,hull2 ;
int ans = 0 ;
long double dist(pii lhs,pii rhs)
{
    ll d = (lhs.fi-rhs.fi)*(lhs.fi-rhs.fi)+(lhs.se-rhs.se)*(lhs.se-rhs.se);
    return (long double)sqrt(d);
}
int direction(pii a,pii b,pii c)
{
    pii vec1(b.fi-a.fi,b.se-a.se),vec2(c.fi-a.fi,c.se-a.se);
    if(vec1.fi*vec2.se-vec2.fi*vec1.se>0)return 1;
    else if(vec1.fi*vec2.se-vec2.fi*vec1.se==0)return 0 ;
    else return 2 ;
}
void construct(vector<pii> &p ,vector<pii> &hull)
{
    sort(p.begin(),p.end(),[&](pii a,pii b){
        if(a.fi!=b.fi)return a.fi>b.fi ;
        return a.se>b.se ;
        });
    pii stt = p.back();
    p.pop_back();
    sort(p.begin(),p.end(),[&](pii a,pii b){
         int di = direction(stt,a,b);
         if(di==0)return (long double)dist(stt,a)<dist(stt,b);
         return di==2 ;
         });
    hull.push_back(stt);
    hull.push_back(p[0]);
    for(int i=1;i<p.size();i++)
    {
        while((hull.size()>1)&&direction(hull[hull.size()-2],hull.back(),p[i])!=2)
            hull.pop_back();
        hull.push_back(p[i]);
    }
    p.push_back(stt);
}
int inside(pii nw,vector<pii> &hull,vector<pii> &p )
{
    int sz=hull.size();
    auto it = lower_bound(p.begin(),p.end(),nw);
    if(it!=hull.end()&&*it==nw)return 0 ;
    for(int i=0;i<sz;i++)
    {
        if(direction(nw,hull[i],hull[(i+1)%sz])==0&&
           (dist(nw,hull[i])+dist(nw,hull[(i+1)%sz])-dist(hull[i],hull[(i+1)%sz]))>1)
        return 1 ;
        if(direction(nw,hull[i],hull[(i+1)%sz])==1)return 1;
    }
    //printf("a %lld %lld\n",nw.fi,nw.se);
    return 0 ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v ;
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
    cout << n+m-ans ;
}
