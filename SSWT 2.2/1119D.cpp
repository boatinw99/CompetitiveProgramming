#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 1e5+9 ;
vector<ll> v,dif ;
ll qs[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,u,m;
    ll l,r,len ;
    ll x ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(i=1;i<v.size();i++)dif.push_back(v[i]-v[i-1]);
    sort(dif.begin(),dif.end());
    i=1;
    for(auto it:dif)
    {
        qs[i]=qs[i-1]+it ;
        i++;
    }
    int sz = v.size();
    cin >> m ;
    while(m--)
    {
        cin >> l >> r ;
        len=r-l+1;
        auto it = upper_bound(dif.begin(),dif.end(),len)-dif.begin();
        ll ans = len*(sz-it)+qs[it];
        cout << ans << " " ;
    }
}
