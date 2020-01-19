#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 ;
ll a[N],b[N],dp[N],qs[N];
struct cht
{
    struct line
    {
        ll m,c ;
        line(ll m,ll c):m(m),c(c){}
        ll f(ll x)
        {
            return m*x+c;
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
    int n,i,j;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> b[i];
    for(i=1;i<=n;i++)qs[i]=a[i]+qs[i-1];
    for(i=2;i<=n;i++)
    {
        hull.add(b[i-1],dp[i-1]);
        dp[i]=hull.query(a[i]);
        ///printf("aa %d %d\n",b[i-1],dp[i-1]);
    }
    cout << dp[n];
}
