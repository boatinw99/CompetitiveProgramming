#include<bits/stdc++.h>
using namespace std ;
const int N=100000;
int dp[N+7];
main()
{
	int n,m,pr=0,co=0,x,i ;
	scanf("%d %d",&n,&m);
	for(i=0;i<N+3;i++)dp[i]=1e9;
	dp[1]=0;
	while(n--)
	{
		scanf("%d",&x);
		if(dp[x]==1e9)
		{
			for(i=1;i*x<=N;i++)
			{
				if(dp[i]!=1e9)
				{
					dp[i*x]=min(dp[i]+1,dp[i*x]);
				}
			}
		}
		else
		{
			pr++ ;
			co+=dp[x];
		}
	}
	printf("%d ",pr);
	if(m==2)printf("%d",co);
}
