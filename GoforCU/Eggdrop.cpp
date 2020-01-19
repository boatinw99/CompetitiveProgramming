#include<bits/stdc++.h>
using namespace std ;
int dp[1009][1009];
main()
{
	int n,k,i,j,d  ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)dp[i][1]=1;
	for(i=2;i<=k;i++)dp[1][i]=i;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			dp[i][j]=INT_MAX;
			for(d=1;d<j;d++)
			{
				dp[i][j]=min(dp[i][j],max(dp[i-1][d-1],dp[i][j-d])+1);
			}
		}
	}
	printf("ans = %d",dp[n][k]);
}
