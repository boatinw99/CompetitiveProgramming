#include<bits/stdc++.h>
using namespace std ;
const int N = 109;
int dp[2][2][N][N];/// Type row numb wi;
main()
{
    int n,k,wi,pi,T,row,x1,y1,x,i,j,y=0,q=0,g ;
    scanf("%d %d",&n,&k);
    x1=0; y1=0;
    for(row=1;row<=k;row++)
    {
        scanf("%d %d %d",&wi,&pi,&T);
        if(T==0)x1^=1,x=x1,q++,g=q;
        else y1^=1,x=y1,y++,g=y;
        for(i=1;i<=g;i++)
        {
            for(j=1;j<=n;j++)
            {
                dp[T][x][i][j]=dp[T][x^1][i][j];
            }
            for(j=wi;j<=n;j++)
            {
                dp[T][x][i][j]=max(dp[T][x][i][j],
                        dp[T][x^1][i-1][j-wi]+pi);
                dp[T][x][i][j]=max(dp[T][x][i][j],dp[T][x][i][j-1]);
            }
        }
    }
    ///x1 y1
    int ans=0;
    for(i=0;i<=q;i++)
    {
        for(j=0;j<=n;j++)
        {
            x=0;
            for(g=(i+1)/2-1;g<=min(y,(i+1)*2);g++)
            {
                x=max(x,dp[1][y1][g][n-j]);
            }
            ans=max(ans,x+dp[0][x1][i][j]);
        }
    }
    printf("%d",ans);
}
