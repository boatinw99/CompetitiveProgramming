#include<bits/stdc++.h>
using namespace std ;
char s[1509];
int dp[15009];
int a[1509];
main()
{
	int n,m,i,j,k ;
	int co,max1=0;
	scanf("%d %d ",&n,&m);
	for(i=1;i<=n;i++)
	{
		gets(s);
		for(j=0;j<m;j++)
		{	
			dp[a[j+1]]=max(dp[a[j+1]]-1,0);
			if(s[j]=='0')
			{
				a[j+1]=0;	
			}
			else 
			{
				a[j+1]++;
				dp[a[j+1]]++;
			}	
		}
		co=0;
		for(k=i;k>=1;k--)
		{
			co+=dp[k];
			max1=max(max1,k*co);
		}
	}
	printf("%d",max1);
}
