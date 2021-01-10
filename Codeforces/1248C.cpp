#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ; 
typedef pair<int,ll> pil ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 1e5+9 , mod = 1e9+7, inf = 1e9 ; 
ll dp[N][4];
ll dp1D(int len)
{
    if(len==1)return 2 ;
    dp[2][0]=dp[2][1]=dp[2][2]=dp[2][3]=1;
    for(int i=4;i<=len;i+=2)
    {
        dp[i][0]=(dp[i-2][1]+dp[i-2][3])%mod;
        dp[i][1]=(dp[i-2][0]+dp[i-2][2])%mod;
        dp[i][2]=(dp[i-2][0]+dp[i-2][2]+dp[i-2][3])%mod;
        dp[i][3]=(dp[i-2][1]+dp[i-2][2]+dp[i-2][3])%mod;
    }
    int i = len ;
    if(len&1)
    {
        i--;
        return (dp[i][0]+dp[i][1]+dp[i][2]*2+dp[i][3]*2)%mod;
    }
    else return (dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3])%mod;
}
ll dp2D(int len)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<4;j++)dp[i][j]=0;
    }
    dp[2][0]=dp[2][1]=dp[2][2]=dp[2][3]=1;
    ll ans = 0 ;
    for(int i=4;i<=len;i+=2)
    {
        dp[i][0]=(dp[i-2][1]+dp[i-2][3])%mod;
        dp[i][1]=(dp[i-2][0]+dp[i-2][2])%mod;
        dp[i][2]=(dp[i-2][0]+dp[i-2][2]+dp[i-2][3])%mod;
        dp[i][3]=(dp[i-2][1]+dp[i-2][2]+dp[i-2][3])%mod;
    }
    int i = len ; 
    if(len&1)
    {
        i--;
        ans = (dp[i][0]+dp[i][1]+dp[i][2]*2+dp[i][3]*2)%mod;
    }
    else ans=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3])%mod;
    return ans ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans = 0 ;
    int n, m ;
    cin >> n >> m ;
    if(n==1||m==1)
    {
        int len = max(n,m); 
        cout << dp1D(len) << '\n' ;
        return 0 ;
    }
    else cout << (dp2D(m)+dp2D(n)-2+mod)%mod << '\n' ;
    return 0 ;
}