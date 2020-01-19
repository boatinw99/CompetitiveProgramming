#include<bits/stdc++.h>
using namespace std ;
int dist[26][26],n,k,co=0;
int dp[(1<<23)-1][26];
int tsp(int mask,int town)
{
	int i;
	if(mask==(1<<n)-1)
	{
		return dist[town][1];	
	}
	if(dp[mask][town]!=0)
	{
		return dp[mask][town];
	}
	dp[mask][town]=INT_MAX ;
	for(i=1;i<=n;i++)
	{
		if((mask&(1<<(i-1)))==0)
		{
			dp[mask][town]=min(dp[mask][town],tsp(mask|(1<<(i-1)),i)+dist[town][i]);
		}
	}
	return dp[mask][town] ;
}
main()
{
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&dist[i][j]);
		}
	}
	printf("%d",tsp(1<<(k-1),k));
}
