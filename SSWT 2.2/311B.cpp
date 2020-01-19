#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , K = 109 ;
const ll inf = 1e15 ;
ll qs[N],a[N],dp[N][K];
struct cht
{
    struct line
    {
        ll m,c ;
        line(ll m,ll c):m(m),c(c){}
        ll f(ll x)
        {
            return m*x+c ;
        }
    };
    vector<line> l ;
    int str = 0 ;
    bool bad(line a,line b,line c)
    {
        return 1.0*(c.c-a.c)/(a.m-c.m)<1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(ll m,ll c)
    {
        line now(m,c);
        while(l.size()>1&&bad(l[l.size()-2],l.back(),now))l.pop_back();
        l.push_back(now);
    }
    ll query(ll x)
    {
        while(str<l.size()-1&&l[str].f(x)>l[str+1].f(x))str++;
        return l[str].f(x);
    }

}hull;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,k,p,h,x ;
    cin >> n >> m >> p ;
    for(i=2;i<=n;i++)
    {
        cin >> qs[i] ;
        qs[i]+=qs[i-1];
    }
    for(i=1;i<=m;i++)
    {
        cin >> h >> x ;
        a[i]=x-qs[h];
    }
    sort(a+1,a+1+m);
    for(i=1;i<=m;i++)qs[i]=qs[i-1]+a[i];
    for(i=1;i<=m;i++)dp[i][0]=inf ;
    for(k=1;k<=p;k++)
    {
        hull.add(0,0);
        hull.str=0 ;
        for(i=1;i<=m;i++)
        {
            dp[i][k]=hull.query(a[i])+a[i]*i-qs[i];
            hull.add(-i,dp[i][k-1]+qs[i]);
        }
        hull.l.clear();
    }
    cout << dp[m][p] ;
}
