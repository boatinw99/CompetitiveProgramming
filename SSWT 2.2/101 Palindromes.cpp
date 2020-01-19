#include<bits/stdc++.h>
using namespace std ;
const int N = 209 , dif = 101 , mod = 1e9+7 ;
int dp[N][N][4][dif],pow2[N];
int a[N];
void add(int &a,int b)
{
    a=(a+b)%mod;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        char c ;
        cin >> c ;
        a[i]=c-'0' ;
    }
    pow2[0]=1;
    for(int i=1;i<7;i++)pow2[i]=pow2[i-1]*10;
    for(int i=n;i>=1;i--)
    {
        dp[i][i][1][a[i]]=1;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==a[j])dp[i][j][2][a[i]*10+a[j]]=1;
            for(int len=0;len<4;len++)for(int md=0;md<dif;md++)
            {
                add(dp[i][j][len][md],(1ll*dp[i+1][j][len][md]+dp[i][j-1][len][md]
                    -dp[i+1][j-1][len][md]+mod)%mod);
                if(j>=i+2&&a[i]==a[j])
                {
                    int tmp = (1ll*a[i]*pow2[len+1]+10*md+a[j])%dif;
                    add(dp[i][j][(len+2)%4][tmp],
                        dp[i+1][j-1][len][md]);
                }
            }
        }
    }
    int ans = 0 ;
    for(int i=0;i<4;i++)
    {
        ans=(ans+dp[1][n][i][0])%mod;
        //printf("aa %d \n",dp[1][n][i][0]);
    }
    cout << ans ;
    return 0 ;
}
