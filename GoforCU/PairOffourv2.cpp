#include<bits/stdc++.h>
using namespace std ;
char s[1009],c;
int dp[1009][1009];
vector<int> v[300];
vector<int>::iterator it,it1;
main()
{
	int n,i,j ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&s[i]);
		v[s[i]].push_back(i);
	}
	for(i=n-1;i>0;i--)
	{
		it=lower_bound(v[s[i]].begin(),v[s[i]].end(),i);
		for(j=i+1;j<=n;j++)
		{	
			if(s[i]==s[j])
			{
				dp[i][j]=1+dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
				for(it1=it+1;it1!=v[s[i]].end()&&*it1<j;it1++)
				{
					dp[i][j]=max(dp[i][j],dp[*it][*it1]+dp[*it1+1][j]);
				}
			}
		}
	}
	printf("%d",dp[1][n]);
}
