#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll qs[609];
ll dp[609][609];
main()
{
	ll i,n,j,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&qs[i]);
		qs[i]+=qs[i-1];
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			dp[i][j]=1e17;
			if(qs[i]-qs[i-1]<=qs[j]-qs[i])
			{
				dp[i][j]=dp[i+1][j]+(qs[i]-qs[i-1])*2+qs[j]-qs[i];
			}
			else 
			{
				dp[i][j]=dp[i+1][j]+(qs[i]-qs[i-1])+(qs[j]-qs[i])*2;
			}
			if(qs[j-1]-qs[i-1]<=qs[j]-qs[j-1])
			{
				dp[i][j]=max(dp[i][j],dp[i][j-1]+(qs[j-1]-qs[i-1])*2+qs[j]-qs[j-1]);
			}
			else
			{
				dp[i][j]=max(dp[i][j],qs[j-1]-qs[i-1]+(qs[j]-qs[j-1])*2+dp[i][j-1]);
			}
		}
	}
	printf("%lld",dp[1][n]);
}
