#include<bits/stdc++.h>
using namespace std ;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int st1=0,st2,ed1,ed2; 
int s[1009][1009];
bool d[1009][1009];
priority_queue<pair<int,pair<int,int> > > pq;
main()
{
	int i,j,n,k,a,b,x ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&s[i][j]);
			if(!s[i][j]&&st1==0)st1=i,st2=j;
			else if(!s[i][j])ed1=i,ed2=j;
		}
	}
	d[st1][st2]++;
	pq.push({0,{st1,st2}});
	while(!pq.empty())
	{
		x=pq.top().first*-1;
		a=pq.top().second.first;
		b=pq.top().second.second;
		pq.pop();
		if(a==ed1&&b==ed2)
		{
			printf("%d",x);
			return 0;
		}
		for(i=0;i<4;i++)
		{
			if(!d[a+dx[i]][b+dy[i]]++&&a+dx[i]>0&&a+dx[i]<=n&&b+dy[i]>0&&b+dy[i]<=n)
			{
				//printf("%d ",s[a+dx[i]][b+dy[i]]);
				if(s[a+dx[i]][b+dy[i]]<=x)
				{
					pq.push({-x,{a+dx[i],b+dy[i]}});
				}
				else pq.push({-s[a+dx[i]][b+dy[i]],{a+dx[i],b+dy[i]}});
			}
		}
	}
}
