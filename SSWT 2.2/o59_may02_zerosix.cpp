#include<bits/stdc++.h>
using namespace std ;
const int N = 109,mxbit=1209;
int a[N][N];
int dp[N][N][mxbit];
bool b[N][N][mxbit];
int findp(int x,int y)
{
    int ans=0;
    while(x%y==0)
    {
        x/=y;
        ans++;
    }
    return ans;
}
main()
{
    int n,m,i,j,x,y,p2,p3,k ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    b[1][0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            x=a[i][j];
            p2=findp(x,2); p3=findp(x,3);
            for(k=0;k+p3<mxbit;k++)
            {
                if(b[i][j-1][k]==1||b[i-1][j][k]==1)
                {
                    dp[i][j][k+p3]=max(dp[i-1][j][k],dp[i][j-1][k])+p2;
                    b[i][j][k+p3]++;
                }

            }
        }
    }
    int ans=0;
    for(i=0;i<mxbit;i++)
    {
        ans=max(ans,min(i,dp[n][m][i]));
    }
    printf("%d",ans);
}
