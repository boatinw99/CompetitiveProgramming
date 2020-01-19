#include<bits/stdc++.h>
using namespace std ;
const int N=1009;
int dp0[N][N],dp1[N][N],dp2[N][N],dp3[N][N];
int a[N][N],n,m;
void check0(int di,int dj)
{
	int i,j ;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp0[i][j]=max(dp0[i+di][j],dp0[i][j+dj])+a[i][j];
		}
	}
}
void check1(int di,int dj)
{
	int i,j ;
	for(i=n;i>0;i--)
	{
		for(j=1;j<=m;j++)
		{
			dp1[i][j]=max(dp1[i+di][j],dp1[i][j+dj])+a[i][j];
		}
	}
}
void check2(int di,int dj)
{
	int i,j ;
	for(i=1;i<=n;i++)
	{
		for(j=m;j>0;j--)
		{
			dp2[i][j]=max(dp2[i+di][j],dp2[i][j+dj])+a[i][j];
		}
	}
}
void check3(int di,int dj)
{
	int i,j ;
	for(i=n;i>0;i--)
	{
		for(j=m;j>0;j--)
		{
			dp3[i][j]=max(dp3[i+di][j],dp3[i][j+dj])+a[i][j];
		}
	}
}
main()
{
	int i,j ;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	check0(-1,-1);
	check1(1,-1);
	check2(-1,1);
	check3(1,1);
	int max1=0;
	for(i=2;i<n;i++)
	{
		for(j=2;j<m;j++)
		{
			max1=max(max1,dp0[i][j-1]+dp1[i+1][j]+dp2[i-1][j]+dp3[i][j+1]);
			max1=max(max1,dp0[i-1][j]+dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]);
		}
	}
	printf("%d",max1);
}
