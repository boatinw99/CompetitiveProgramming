#include<bits/stdc++.h>
using namespace std ;
int dp[100009];
int p=0,*q;
main()
{
	int n,x ;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		q=upper_bound(dp,dp+p,x);
		dp[q-dp]=x;
		if(q-dp==p)
		{
			p++; 
		}
	}
	printf("%d",p);
}
