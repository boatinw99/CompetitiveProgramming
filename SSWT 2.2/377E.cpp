#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll inf = 1e18 ;
const int N = 2e5+9 ;
struct build
{
    ll v,c ;
    bool operator <(const build &tmp)const
    {
        if(c!=tmp.c)return c>tmp.c ;
        return v>tmp.v ;
    }
}a[N];
struct line
{
    ll m,c ;
    line(ll m,ll c):m(m),c(c){}
    ll f(ll x)
    {
        return m*x+c ;
    }
    ll get(ll y)
    {
        return (y-c-1+m)/m;
    }
};
struct cht
{
    vector<line> L ;
    int str=0;
    bool bad(line a,line b,line c)
    {
        return 1.0*(c.c-a.c)/(a.m-c.m)<=1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(line now)
    {
        if(!L.empty()&&L.back().m==now.m)L.pop_back();
        while(L.size()>1&&bad(L[L.size()-2],L.back(),now))L.pop_back();
        L.push_back(now);
    }
    ll query(ll y)
    {
        while(str<L.size()-1)
        {
            ll a=L[str].get(y),b=L[str+1].get(y);
            if(a>b||(a==b&&L[str].f(a)<L[str+1].f(b)))str++;
            else break;
        }
        return L[str].get(y);
    }

}hull;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j ;
    ll s,ans=inf ;
    cin >> n >> s ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].v >> a[i].c ;
        a[i].c*=-1 ;
    }
    sort(a+1,a+1+n);
    hull.add(line(a[1].v,0));
    ans=hull.L.back().get(s) ;
    ll mx = 0 ;
    for(i=2;i<=n;i++)
    {
        if(a[i].v<=mx)continue ;
        mx=a[i].v ;
        ll ret = hull.query(-a[i].c);
        hull.add(line(a[i].v,hull.L[hull.str].f(ret)-ret*a[i].v+a[i].c));
        ans=min(ans,hull.L.back().get(s));
    }
    cout << ans ;
}
