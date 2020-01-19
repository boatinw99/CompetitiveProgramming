#include<bits/stdc++.h>
using namespace std ;
const int N = 34,MOD=1e9+7;
int dp[N][3][3];///l,r
int dp1[N][3][3];
int dpans[N][3][3];
/// INcantation
main()
{
    int i,j,n,m,k,l,r,d1,d2,bits ;
    scanf("%d",&n);
    dp[0][0][0]=1; dp[0][1][1]=1; dp[0][1][2]=1; dp[0][2][2]=1;
    dp[0][0][1]=1; dp[0][1][0]=1; dp[0][2][1]=1;
    //dp1[0]=1; dp2[0]=1; dp3[0]=1; dp4[0]=1;
    for(i=1;i<31;i++)
    {
        for(l=0;l<3;l++)
        {
            for(d1=0;d1<3;d1++)
            {
                for(r=0;r<3;r++)
                {
                    dp[i][l][r]=(1ll*dp[i][l][r]+
                    (1ll*dp[i-1][l][d1]*dp[i-1][d1][r]))%MOD;
                }
            }
        }
        //dp[i][0][2]+=dp1[i-1]*dp2[i-1];
       // dp[i][2][0]+=dp3[i-1]*dp4[i-1];
    }

    int p=1,ans=0 ;

    for(i=0;(1<<i)<=n;i++);i--;
    for(l=0;l<3;l++)
    {
        for(r=0;r<3;r++)
        {
            dpans[0][l][r]=dp[i][l][r];
        }
    }
    n-=(1<<i);
    for(i--;n>0;i--)
    {
        if((1<<i)>n)
        {
            continue ;
        }
        n-=(1<<i);
        for(l=0;l<3;l++)
        {
            for(d1=0;d1<3;d1++)
            {
                for(r=0;r<3;r++)
                {
                    dpans[p][l][r]=(1ll*dpans[p-1][l][r]+
                    (1ll*dpans[p-1][l][d1]*dpans[p-1][d1][r]))%MOD;
                }
            }
        }
        p++;
    }
    p--;
    for(l=0;l<3;l++)
    {
        for(r=0;r<3;r++)
        {
            ans=ans+dpans[p][l][r];
            ans%=MOD;
        }
    }
    printf("%d",ans);

}
