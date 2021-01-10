#include<bits/stdc++.h>
using namespace std ;
const int N=1000000;
int dp[N+9];
main()
{
	int n,x,val,max1=0,i ;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		val=dp[x];
		for(i=1;i*x<=N;i++)
		{		
			dp[i*x]=max(dp[i*x],val+1);
		}
	}
	for(i=1;i<=N;i++)max1=max(max1,dp[i]);
	printf("%d",max1);
}
