#include<bits/stdc++.h>
using namespace std ;
pair<int,int> dp[1009][1009][2];
pair<int,int> a[1009][1009];
int n;
int divide(int k,int mod)
{
	int x;
	if(k==0)return 1;
	for(x=0;k%mod==0;k/=mod)x++;
	return x;
}
void pr(int x,int y)
{
	int i,j ;
	printf("\n");
	for(i=1;i<x;i++)printf("D");
	for(j=1;j<y;j++)printf("R");
	for(i=x;i<n;i++)printf("D");
	for(j=y;j<n;j++)printf("R");
}
void pr1(int q,int x,int y)
{
	if(dp[x-1][y][q].first==dp[x][y][q].first-a[x][y].first&&dp[x-1][y][q].second==dp[x][y][q].second-a[x][y].second)
	{
		if(x-1>0)
		{
			pr1(q,x-1,y);
			printf("D");
		}
		
	}
	else 
	{
		if(y-1>0)
		{
			pr1(q,x,y-1);
			printf("R");	
		}
	}
}
main()
{
	int x,i,j,k1,k2,y ;
	bool q=0;
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		dp[i][0][0]={1e6,1e6};
		dp[i][0][1]={1e6,1e6};
		dp[0][i][0]={1e6,1e6};
		dp[0][i][1]={1e6,1e6};
	}
	dp[0][1][0]={0,0};
	dp[0][1][1]={0,0};
	int d1,d2,d3,d4;
	int p1,p2;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if(x==0)q++,p1=i,p2=j;
			k1=divide(x,2);
			k2=divide(x,5);
			a[i][j]={k1,k2};
			if(dp[i-1][j][0].first<dp[i][j-1][0].first)
			{
				d1=dp[i-1][j][0].first;
				d2=dp[i-1][j][0].second;
			}
			else if(dp[i-1][j][0].first==dp[i][j-1][0].first)
			{
				d1=dp[i-1][j][0].first;
				d2=min(dp[i-1][j][0].second,dp[i][j-1][0].second);
			}
			else
			{
				d1=dp[i][j-1][0].first;
				d2=dp[i][j-1][0].second;
			}
			if(dp[i-1][j][1].second<=dp[i][j-1][1].second)
			{
				d3=dp[i-1][j][1].first;
				d4=dp[i-1][j][1].second;
			}
			else if(dp[i-1][j][1].second==dp[i][j-1][1].second)
			{
				d2=dp[i-1][j][1].second;
				d2=min(dp[i-1][j][1].first,dp[i][j-1][1].first);
			}
			else 
			{
				d3=dp[i][j-1][1].first;
				d4=dp[i][j-1][1].second;
			}
			dp[i][j][0]={d1+k1,d2+k2};
			dp[i][j][1]={d3+k1,d4+k2};
			//printf("%d %d || %d %d\n",d1+k1,d2+k2,d3+k1,d4+k2);
		}
	}
	int max1,max2;
	//printf("%d %d\n",dp[n][n][0].first,dp[n][n][0].second);
//	printf("%d %d\n",dp[n][n][1].first,dp[n][n][1].second);
	max1=min(dp[n][n][0].first,dp[n][n][0].second);
	max2=min(dp[n][n][1].first,dp[n][n][1].second);
	if(q)max2=min(max2,1);
	printf("%d",min(max1,max2));
	if(min(max1,max2)==1&&q)
	{
		pr(p1,p2);
		return 0;
	}
	if(max1<max2)q=0;
	else q=1; 
	printf("\n");
	pr1(q,n,n);
}
