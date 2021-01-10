#include<bits/stdc++.h>
using namespace std ;
vector<vector<pair<int,int> > > v(3000);
vector<pair<int,int> >::iterator it ;
priority_queue<pair<int,pair<int,int> > > pq;
int s[3009]={0},min1=999999,j[2509][2509],start;
int Call(int i)
{
	if(i==start)
	{
		return 0 ;
	}
	else 
	{
		if(j[s[i]][i]<min1)min1=j[s[i]][i];
		Call(s[i]);
	}
	
}
main()
{
	int m,n,i,x,y,value,end,l ;
	scanf("%d %d ",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d",&x,&y,&value);
		v[x].push_back({y,value});
		v[y].push_back({x,value});
		j[x][y]=value;
		j[y][x]=value;
	}
	scanf(" %d %d %d",&start,&end,&l);
	for(it=v[start].begin();it!=v[start].end();it++)
	{
		pq.push({it->second,{start,it->first}});
	}
	s[start]=99;
	while(!pq.empty())
	{
		value=pq.top().first ;
		x=pq.top().second.first;
		y=pq.top().second.second;
		pq.pop();
		if(s[y]==0)
		{
			s[y]=x;
			if(y==end)break;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				pq.push({it->second,{y,it->first}});
			}
		}
	}
	Call(end);
	min1--;
	x=0;
	while(l>0)
	{
		l-=min1;
		x++;
	}
	printf("%d",x);
	
}
