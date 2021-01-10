#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const ll INF = 1e15 ; 
const int N = 1e5+9 ; 
ll val[N],dp[N];
int clr[N],n,q ; 
ll comp(ll a,ll b)
{
    pll mx = {0,0} ;
    for(int i=1;i<=n;i++)
    {
        int c = clr[i];
        ll mxb = mx.fi ;
        ll now = dp[c]+val[i]*a ;
        if(mxb==dp[c])
        {
            mxb = mx.se ; 
            now = max(now,mxb+val[i]*b); 
            if(now>dp[c])
            {
                dp[c] = now ;
                mx.fi = now ;
            }
        }
        else 
        {
            now = max(now,mxb+val[i]*b);
            if(now>mx.fi)mx.se=mx.fi,mx.fi=now;
            else if(now>mx.se)mx.se=now ;
            if(now>dp[c])dp[c]=now;
        }
    }
    return mx.fi ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> q ;
    for(int i=1;i<=n;i++)
    {
        cin >> val[i] ;
    }
    for(int i=1;i<=n;i++)cin >> clr[i] ;
    for(int i=1;i<=q;i++)
    {
        ll a,b ;
        fill(dp,dp+N,-INF);
        cin >> a >> b ;
        cout << comp(a,b) << '\n' ;
    }
    return 0 ;
}