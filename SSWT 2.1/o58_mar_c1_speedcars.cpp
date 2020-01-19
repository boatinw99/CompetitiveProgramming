#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
pii a[N];
ll mx = 0 ;
bool cmp(pii lhs,pii rhs)
{
    if(lhs.fi!=rhs.fi)return lhs.fi<rhs.fi;
    return lhs.se>rhs.se ;
}
main()
{
    int n,T,i,j,cnt=0 ;
    cin >> n >> T ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i].fi >> a[i].se ;
    }
    sort(a+1,a+1+n,cmp);
    for(i=1;i<=n;i++)
    {
        ll tmp = a[i].se*T+a[i].fi ;
        if(tmp>mx)cnt++;
        mx=max(mx,tmp);
    }
    cout << cnt ;
}
