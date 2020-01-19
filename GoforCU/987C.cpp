#include<bits/stdc++.h>
using namespace std ;
const int N=3009;
int dp[5][N];
int a[N];
main()
{
	int n,i,j,k ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dp[1][i]);
	}
	for(i=2;i<=3;i++)
	{
		dp[i][i-1]=1e9+7;
		for(j=i;j<=n;j++)
		{
			dp[i][j]=1e9+7;
			for(k=j-1;k>=i-1;k--)
			{
				if(a[k]<a[j])
				{
					dp[i][j]=min(dp[i][j],dp[1][j]+dp[i-1][k]);
				}
			}
		}
	}
	int max1=1e9;
	for(i=3;i<=n;i++)
	{
		max1=min(max1,dp[3][i]);
	}
	if(max1==1e9)printf("-1");
	else printf("%d",max1);
}
