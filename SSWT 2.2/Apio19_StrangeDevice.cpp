#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second
const ll mx = 1e9+7,inf=1e18+7;
vector<pll> V,sweep;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    ll a,b,ab,ans=0 ;
    cin >> n >> a >> b ;
    ll x = b ;
    for(;x<inf;x+=b)
    {
        if((x+x/b)%a==0)break;
    }
    ab=x;
    for(int i=1;i<=n;i++)
    {
        ll u,v ;
        cin >> u >> v ;
        ll len = v-u+1;
        if(len>=ab)
        {
            ans=ab;
        }
        ll l = u/ab;
        ll r = v/ab;
        if(l==r)
        {
            V.emplace_back(u%ab,v%ab);
        }
        else
        {
            V.emplace_back(u%ab,ab-1);
            V.emplace_back(0,v%ab);
        }
    }
    if(ans)
    {
        cout << ans << '\n' ;
        return 0 ;
    }
    ///sort(V.begin(),V.end());
    ///V.resize(unique(V.begin(),V.end())-V.begin());
    for(auto it:V)
    {
        sweep.emplace_back(it.fi,1);
        sweep.emplace_back(it.se+1,-1);
    }
    sort(sweep.begin(),sweep.end());
    ll exval = 0 ,cnt = 0 ;
    for(auto it:sweep)
    {
        if(cnt>0)ans+=it.fi-exval;
        while(cnt<0);
        cnt+=it.se;
        exval=it.fi ;
    }
    cout << ans << '\n' ;
    //while(ans>ab);
    return 0;
}
