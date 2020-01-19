#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 ;
ll sum[N],qs[N];
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
    bool bad(line a,line b,line c)
    {
        return 1.0*(c.c-a.c)/(a.m-c.m)>1.0*(b.c-a.c)/(a.m-b.m);
    }
    void add(ll m,ll c)
    {
        line now(m,c);
        while(l.size()>1&&bad(l[l.size()-2],l.back(),now))l.pop_back();
        l.push_back(now);
    }
    ll query(ll x)
    {
        int L=0,R=l.size()-1;
        while(L<R)
        {
            int mid = L+R>>1;
            if(l[mid].f(x)>=l[mid+1].f(x))R=mid;
            else L=mid+1;
        }
        return l[L].f(x);
    }

}hull;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j;
    ll sum2=0,ans=0 ;
    cin >> n ;
    hull.add(0,0);
    for(i=1;i<=n;i++)
    {
        cin >> qs[i] ;
        sum2+=qs[i]*i ;
        qs[i]+=qs[i-1];
        hull.add(-i,i*qs[i]-sum2);
        ans=max(ans,hull.query(qs[i])+sum2);
    }
    cout << ans ;
}
