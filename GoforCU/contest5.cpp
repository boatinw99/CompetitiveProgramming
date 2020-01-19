#include<bits/stdc++.h>
using namespace std ;
const int N = 5009;
int A[N];
int B[N];
int dp[N][N];
bool b[N];
main()
{
    int n,m,k,i,j ;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    for(j=1;j<=m;j++)scanf("%d",&B[j]);
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)dp[i][j]=1e9;
    }
    dp[0][0]=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<i;j++)printf("  ");
        for(j=i;j<=n;j++)
        {
            if(b[i])dp[i][j]=min(dp[i][j-1],dp[i][j]);
            if(!b[i]++||B[i]==A[j+1])
            {
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
            if(B[i]==A[j])
            {
                dp[i][j]=min(dp[i-1][j-1],dp[i][j]);
            }
            printf("%d ",dp[i][j]);
        }
          printf("\n");
    }
    int max1=0;
    printf("\n\n");
    for(i=1;i<=m;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(dp[i][j]<=k)
            {
                max1=i;
                break;
            }
        }
    }
    printf("%d",max1);
}
