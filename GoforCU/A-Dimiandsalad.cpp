#include<bits/stdc++.h>
using namespace std ;
int a[109];
int dp[250009];
main()
{
	int n,k,i,x,j,val,b ;
	const int N=100009;
	scanf("%d %d",&n,&k);
	for(i=0;i<=220007;i++)dp[i]=-1e9;
	dp[N]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b);
		val=a[i];
		x=val-k*b;	
		if(x>=0)
		{
			for(j=(2*N)-x;j>=0;j--)
			{
				dp[j+x]=max(dp[j+x],dp[j]+val);		
			}
		}
		else
		{
			for(j=-x;j<=2*N;j++)
			{
				dp[j+x]=max(dp[j+x],dp[j]+val);
			}
		}
	}
	if(dp[N]==0)printf("-1");
	else printf("%d",dp[N]);
}
