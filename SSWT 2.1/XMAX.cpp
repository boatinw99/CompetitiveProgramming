#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N =1e5+9 ;
const ll  M = 1ll<<62;
ll a[N] ;
vector<ll> ans ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
    }
    for(ll j=M;j>=1;j>>=1)
    {
        ll tmp = 0 ;
        for(i=1;i<=n;i++)if((a[i]&j))tmp=a[i] ;
        if(!tmp)continue ;
        ans.emplace_back(tmp);
        for(i=1;i<=n;i++)
        {
            if(a[i]&j)a[i]^=tmp;
        }
    }
    ll ret = 0 ;
    for(auto it:ans)if((ret^it)>ret)ret^=it;
    cout << ret ;
}
