#include<bits/stdc++.h>
using namespace std ;
const int N = 32;
int a[N][N],k;
int dp[N][N][N][N] ;
int slr[N][N][N*N],sld[N][N][N*N];
int all[N*N];
///slide l-r , slide u-d ;
int find(int x1,int y1,int x2,int y2)
{
    int co=0,d;
    if(x1==x2)
    {
        for(d=1;d<=k;d++)
        {
            if(slr[x2][y2][d]-slr[x1][y1-1][d]==all[d]&&all[d]!=0)
            {
                co++;
            }
        }
    }
    else
    {
        for(d=1;d<=k;d++)
        {
            if(sld[x2][y2][d]-sld[x1-1][y1][d]==all[d]&&all[d]!=0)
            {
                co++;
            }
        }
    }
    return co;
}
main()
{
    int n,m,i,j,i1,j1,d ;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)scanf("%d",&a[i][j]),all[a[i][j]]++;
    }
    ///LR
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            slr[i][j][a[i][j]]++;
            for(d=1;d<=k;d++)slr[i][j][d]+=slr[i][j-1][d];
        }
    }
    ///UD
    int max1,max2;
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            sld[i][j][a[i][j]]++;
            for(d=1;d<=k;d++)sld[i][j][d]+=sld[i-1][j][d];
        }
    }
    for(i=n;i>0;i--)
    {
        for(j=m;j>0;j--)
        {
            for(j1=j;j1<=m;j1++)dp[i][j][i][j1]=find(i,j,i,j1);
            for(i1=i;i1<=n;i1++)dp[i][j][i1][j]=find(i,j,i1,j);
            ///
            for(i1=i+1;i1<=n;i1++)
            {
                for(j1=j+1;j1<=m;j1++)
                {
                    max1=max(dp[i][j][i][j1]+dp[i+1][j][i1][j1],
                        dp[i][j][i1-1][j1]+dp[i1][j][i1][j1]);
                    max2=max(dp[i][j][i1][j]+dp[i][j+1][i1][j1],
                        dp[i][j][i1][j1-1]+dp[i][j1][i1][j1]);
                    dp[i][j][i1][j1]=max(max1,max2);
                }
            }
        }
    }
    printf("%d",dp[1][1][n][m]);

}
