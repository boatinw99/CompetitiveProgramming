#include<bits/stdc++.h>
using namespace std ;
priority_queue<pair<int,int> >pq;
int s[609][609];
int pr[609];
main()
{
	int n,i,j,x,y ;
	scanf("%d",&n);
	for(i=1;i<=2*n;i++)
	{
		for(j=1;j<=2*n;j++)
		scanf("%d",&s[i][j]);
	}
	pq.push({0,2*n});
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		y=pq.top().second;
		pq.pop();
		if(!pr[y])
		{
			pr[y]=x;
			for(i=1;i<y;i++)
			{
				if(!pr[i])
				{
					pq.push({-x-s[y][i],i});
				}
			}
		}
	}
	printf("%d",pr[2]);
}
