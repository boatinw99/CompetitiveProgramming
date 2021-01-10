#include<bits/stdc++.h>
using namespace std;
int s[109][109];
main()
{
	int m,n,i,j,x,y,value,k=0 ;
	char b;
	vector<pair<int,int> > v[109][109];
	vector<pair<int,int> >::iterator it;
	priority_queue<pair<int,pair<int,int> > > pq;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			s[i][j]=9999;
			scanf(" %c",&b);
			if(b=='B'||b=='D')
			{
				v[i][j].push_back({i+1,j});
				v[i+1][j].push_back({i,j});
			}
			if(b=='B'||b=='R')
			{
				v[i][j].push_back({i,j+1});
				v[i][j+1].push_back({i,j});
			}
		}	
	}
	s[0][0]=1;
	value=2;
	for(it=v[0][0].begin();it!=v[0][0].end();it++)
	{
		pq.push({-2,{it->first,it->second}});
	}
	while(1)
	{
		x=pq.top().second.first ;
		y=pq.top().second.second;
		value=pq.top().first*-1; //+	
		pq.pop();
		if(value==s[x][y])
		{
			printf("%d\n",value);
			printf("%d %d\n",x+1,y+1);
			break;
		}
		if(value<=s[x][y])
		{
			s[x][y]=value;
			for(it=v[x][y].begin();it!=v[x][y].end();it++)
			{
				pq.push({-value-1,{it->first,it->second}});
			}
		}
	}
}
