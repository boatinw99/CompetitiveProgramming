#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second
const ll mx = 1e9+7,inf=1e18+7,N=2e6+9;
vector<pll> V,sweep;
map<pll,ll> mp ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    ll a,b,ab,ans=0 ;
    cin >> n >> a >> b ;
    if(a>mx&&b>mx)ab=inf;
    else ab = a*b;
    //if(b==1&&a%2==0)ab/=2;
    for(int i=1;i<=n;i++)
    {
        ll u,v ;
        cin >> u >> v ;
        ll len = v-u+1;
        for(ll j=u;j<=v;j++)
        {
            mp[{(j+(j/b))%a,j%b}]++;
        }
    }
    ///sort(V.begin(),V.end());
    ///V.resize(unique(V.begin(),V.end())-V.begin());
    /*
    for(int i=0;i<N;i++)
    {
        if(cnt[i])ans++;
    }*/
    cout << mp.size() << '\n' ;
    //while(ans>ab);
    return 0;
}
