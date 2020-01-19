/**
 *      Author : boatinw99
 *      Date : 4.5.2019 15:45
**/
#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 , mod = 998244353 ;
int a[N],dp[N];
int main()
{
    int n,x ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> x ;
        a[x]++;
    }
    int ans = 0 ;
    for(int i=n;i>=1;i--)
    {
        dp[i]=1ll*a[i]*(a[i]-1)/2 %mod;
        for(int j=i+1;j<=n;j++)
        {
            dp[i]=(dp[i]+1ll*dp[j]*a[i])%mod;
        }
        ans=(ans+dp[i])%mod;
    }
    return 0 ;
}
