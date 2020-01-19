#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second
const int N = 1e6+9 ;
pair<pll,ll> a[N];
ll dp[N];
struct cht
{
    struct line
    {
        ll m,c ;
        line(ll m,ll c):m(m),c(c){}
        ll f(ll x){
            return m*x+c ;
        }
    };
    vector<line> l;
    int ptr=0 ;
    bool bad(line a,line b,line c)
    {
        return 1.0*(c.c-a.c)/(a.m-c.m)>=1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(ll x,ll c)
    {
        line now(x,c);
        while(l.size()>1&&bad(l[l.size()-2],l[l.size()-1],now))l.pop_back();
        l.emplace_back(now);
    }
    ll query(ll x)
    {
        while(ptr<l.size()-1&&l[ptr].f(x)>l[ptr+1].f(x))ptr++;
        return l[ptr].f(x);
    }
}hull;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j;
    ll x,y,cst,ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y >> cst ;
        a[i]={{x,y},cst};
    }
    hull.add(0,0);
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        dp[i]=-hull.query(a[i].fi.se)-a[i].se+a[i].fi.fi*a[i].fi.se;
        hull.add(a[i].fi.fi,-dp[i]);
        ans=max(ans,dp[i]);
    }
    cout << ans ;
}
