#include<bits/stdc++.h>
using namespace std ;
const int MOD=1e9+7;
int a[1009][1009];
main()
{
	int n,m,i,j,x ;
	scanf("%d %d",&n,&m);
	a[1][1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x);
			if(x==0)
			{
				a[i][j]+=(a[i-1][j]+a[i][j-1])%MOD;	
			}	
		}	
	}
	printf("%d",a[n][m]);
}
