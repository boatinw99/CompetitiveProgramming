#include<bits/stdc++.h>
using namespace std ;
int dist[20][20];
int dp[(1<<20)-1][20];
int n,k; 
int tsp(int mask,int town)
{
	if(mask==((1<<n)-1))
	{
		return dist[town][k];
	}
	if(dp[mask][town])return dp[mask][town];
	dp[mask][town]=INT_MAX;
	int i;
	for(i=0;i<n;i++)
	{
		if((mask&(1<<i))==0)
		{
			dp[mask][town]=min(dp[mask][town],dist[town][i]+tsp(mask|(1<<i),i));
		}
	}
	return dp[mask][town];
}
main()
{
	int i,j ;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&dist[i][j]);
		}
	}
	printf("%d",tsp(1<<k,k));
}
