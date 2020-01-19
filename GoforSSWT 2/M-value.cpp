#include <bits/stdc++.h>

using namespace std;

bool dp[2][100007];

int main()
{
	int N;
	int co = 0 ;
	scanf("%d",&N);
	for(int I=1;I<=N;I++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		co=n*m;
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=0;j<m;j++)
			{
				if(dp[(i+1)&1][j])
				{
					dp[i&1][(j+x)%m]=1;
					dp[i&1][j]=1;
					dp[(i+1)&1][j]=0;
				}
			}
		}
		int sol=0;
		for(int i=0;i<m;i++)
		{
			if(dp[n&1][i])
			{
				sol=i;
				dp[n&1][i]=0;
				dp[(n+1)&1][i]=0;
			}
		}
		printf("Case #%d: %d\n",I,sol);
	}
	while(co>1e8);
	return 0;
}
