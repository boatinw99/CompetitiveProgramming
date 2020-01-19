#include<bits/stdc++.h>
using namespace std ;
const int N = 35009;
int a[N];
int cs[N];
int dp[59][N];
main()
{
	int n,k,i,j,co,d ;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=k;i++)
	{
		co=1;
		for(j=1;j<=n;j++)cs[j]=0;
		d=i;
		dp[i][i]=i;
		cs[a[i]]++;
		for(j=i+1;j<=n;j++)
		{
			cs[a[j]]++;
			if(cs[a[j]]==1)
			{
				co++;
			}
			while(d<=j)
			{
				if(cs[a[d]]>1)
				{
					cs[a[d]]--;
					d++;
				}
				else if(co+dp[i-1][d-1]<dp[i-1][d]+co-1)
				{
					cs[a[d]]--;
					d++;
					co--;
				}
				else break ;
			}
			dp[i][j]=co+dp[i-1][d-1];
		}
	}
	printf("%d",dp[k][n]);
}
