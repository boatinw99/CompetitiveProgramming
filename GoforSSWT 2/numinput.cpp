#include<bits/stdc++.h>
using namespace std ;
const int N = 1009,MOD= 9901;
int a[N];
int dp[N][N];
main()
{
    int n,m,i,j,p=1,x,q,pre ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        while(x--)
        {
            a[p++]=i;
        }
    }
    pre=1;
    dp[1][1]=1;
    while(m--)
    {
        scanf("%d",&q);
        dp[a[pre]-1][pre]=0;
        for(j=pre+1;j<=q;j++)
        {
            for(i=a[pre];i<=a[q]&&i<=j;i++)
            {
                dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
            }
        }
        pre=q;
    }
    dp[a[pre]-1][pre]=0;
    for(j=pre+1;j<p;j++)
    {
        for(i=a[pre];i<=n&&i<=j;i++)
        {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
        }
    }
    printf("%d",dp[n][p-1]);
}
