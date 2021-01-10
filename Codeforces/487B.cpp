#include<bits/stdc++.h>
using namespace std ;
int dp[100009];
priority_queue<pair<int,int> > pq,pq1;
main()
{
	int n,s,t,i,j=1,ex=0,x,d1,d2 ;
	scanf("%d %d %d",&n,&s,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(ex==0)
		{
			ex++;
			pq.push({-x,i});
			pq1.push({x,i});
		}
		else if(x+pq.top().first<=s&&pq1.top().first-x<=s)
		{
			ex++;
			pq.push({-x,i});
			pq1.push({x,i});
		}
		else
		{
			j=0;
			while(!pq.empty()&&!pq1.empty())
			{
				if((x+pq.top().first>s||pq.top().second<=j||dp[j]==0))
				{
					j=max(j,pq.top().second);
					pq.pop();
				}
				else if((pq1.top().first-x>s||pq1.top().second<=j))
				{
					j=max(j,pq1.top().second);
					pq1.pop();
				}
				else break ;
			}	
			ex=i-j ;
			pq.push({-x,i});
			pq1.push({x,i});
		}
		if(ex>=t)
		{
			if(dp[i-ex]==0&&i-ex>0)break;
			dp[i]=dp[i-ex]+1;
		}
	}
	if(dp[n]==0)printf("-1"); 
	else printf("%d",dp[n]);
}
