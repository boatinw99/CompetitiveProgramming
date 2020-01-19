#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll INF = 1e17;
const int N=50009;
ll qs[N],dp[2][N],pmin[2][N];
main()
{
	int n,k,m,x,i,j ;
	scanf("%d %d %d",&n,&k,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		qs[i]=qs[i-1]+x;
		pmin[0][i]=min(pmin[0][i-1],-qs[i-1]);
	}
	for(i=1;i<=k;i++)
	{
		x=i&1;
		dp[x][0]=INF ; pmin[x][0]=INF ;
		for(j=1;j<=n;j++)
		{
			dp[x][j]=dp[x][j-1];
			if(j-m+1>=1)
			{
				dp[x][j]=min(dp[x][j],pmin[x^1][j-m+1]+qs[j]);
			}
			pmin[x][j]=min(pmin[x][j-1],dp[x][max(j-2,0)]-qs[j-1]);
		}
	}
	printf("%lld",qs[n]-dp[k&1][n]);
}
