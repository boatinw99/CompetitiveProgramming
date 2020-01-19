#include<bits/stdc++.h>
using namespace std ;
char s[1009];
int dp[1009][1009];
int pr[1009];
main()
{
	int n,i,j ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&s[i]);
	}
	for(i=n-1;i>0;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			if(s[i]==s[j])
			{
				dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		pr[i]=dp[1][i];
		for(j=1;j<=i;j++)
		{
			pr[i]=max(pr[i],pr[j]+dp[j+1][i]);
		}
	}
	for(i=1;i<=n;i++)
	printf("%d ",pr[i]);
}
