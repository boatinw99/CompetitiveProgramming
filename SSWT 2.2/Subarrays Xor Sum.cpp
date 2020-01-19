#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , mod = 1e9+7 , M = 30 ;
int n,l,r,a[N],dp[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> l >> r ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    int ans = 0 ;
    for(int bit=0;bit<M;bit++)
    {
        int Xor = 0,add = 0,cnt0 = 0,cnt1 = 0 ;
        for(int i=1;i<=n;i++)
        {
            Xor^=(((1<<bit)&a[i])>0);
            dp[i]=Xor ;
            if(i>=l)
            {
                cnt0+=(dp[i-l]==0);
                cnt1+=(dp[i-l]==1);
            }
            if(i>r)
            {
                cnt0-=(dp[i-r-1]==0);
                cnt1-=(dp[i-r-1]==1);
            }
            if(Xor)add+=cnt0;
            else add+=cnt1;
            add%=mod;
        }
        ans=(ans+1ll*add*(1<<bit)%mod)%mod;
    }
    cout << ans ;
    return 0 ;
}
