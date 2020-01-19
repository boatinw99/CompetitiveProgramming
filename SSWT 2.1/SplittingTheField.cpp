#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
typedef long long ll ;
const int N = 5e4+9 ;
set<pii> s;
pii a[N];
main()
{
    int n,i,j,u,v,mx=0,mn=INT_MAX,l ;
    ll ans=1e18+9 ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> u >> v ;
        a[i]={u,v};
        s.insert({v,u});
    }
    sort(a+1,a+1+n);
    l=a[1].fi;
    for(i=1;i<n;i++)
    {
        u=a[i].fi,v=a[i].se;
        s.erase({v,u});
        mx=max(mx,v);
        mn=min(mn,v);
        ll tmp = (1ll*u-l)*(1ll*mx-mn);
        ll tmp1= (1ll*a[n].fi-a[i+1].fi)*(1ll*(s.rbegin()->fi)-s.begin()->fi);
        ans=min(ans,tmp+tmp1);
    }
    s.erase(s.begin());
    mx=max(mx,a[n].se);
    mn=min(mn,a[n].se);
    ll A=(1ll*a[n].fi-a[1].fi)*(1ll*mx-mn);
    for(i=1;i<=n;i++)
    {
        pii point=a[i];
        a[i]={point.se,point.fi};
        s.insert({point.fi,point.se});
    }
    mx=0,mn=INT_MAX;
    sort(a+1,a+1+n);
    l=a[1].fi;
    for(i=1;i<n;i++)
    {
        u=a[i].fi,v=a[i].se;
        s.erase({v,u});
        mx=max(mx,v);
        mn=min(mn,v);
        ll tmp = (1ll*u-l)*(1ll*mx-mn);
        ll tmp1= (1ll*a[n].fi-a[i+1].fi)*(1ll*(s.rbegin()->fi)-s.begin()->fi);
        ans=min(ans,tmp+tmp1);
    }
    cout << A-ans ;
}
