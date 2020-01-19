#include<bits/stdc++.h>
using namespace std ;
vector<int>v[100009];
int vote[100009];
bool b[100009];
int dp[100009];
int dp2[100009];
void find(int i)
{
	b[i]++;
	vector<int>::iterator it;
	if(v[i].empty())
	{
		dp[i]=1;
	}
	else 
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(b[*it]==0)
		{
			find(*it);
			dp[i]+=dp2[*it];
			dp2[i]+=dp[*it];
		}
	}
	dp[i]=max(dp[i],dp2[i]);
	printf("%d %d %d\n",i,dp[i],dp2[i]);
}
main()
{
	int Q,n,i,j,pr ;
	scanf("%d",&Q);
	while(Q--)
	{
		pr=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			dp[i]=1; dp2[i]=0; b[i]=0;
			scanf("%d",&vote[i]);
			v[vote[i]].push_back(i);
		}
		for(i=1;i<=n;i++)
		{
			if(b[i]==0&&!v[i].empty())
			{
				printf("\n");
				find(i);
				pr+=dp[i];
			}
		}
		printf("%d\n",n-pr);
		for(i=1;i<=n;i++)
		{
			v[i].clear();
		}
	}
}
