#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[59];
vector<pair<int,int> >::iterator it;
int bmf[59];
int a[59][59];
main()
{
	int n,m,i,j,x,y,val,st,ed  ;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&val);
		v[x].push_back({y,val});
	}
	st=n;
	bmf[st]=0;
	for(i=0;i<n;i++)bmf[i]=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			for(it=v[j].begin();it!=v[j].end();it++)
			{
				bmf[it->first]=min(bmf[it->first],bmf[j]+it->second);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			it->second+=bmf[i]-bmf[it->first];
		}
	}
	priority_queue<pair<int,int> > pq;
	for(i=0;i<n;i++)for(j=0;j<n;j++)a[i][j]=INT_MAX;
	for(i=0;i<n;i++)
	{
		while(!pq.empty())pq.pop();
		a[i][i]=0;
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			pq.push({-it->second,it->first});
		}
		while(!pq.empty())
		{
			x=pq.top().first*-1;
			y=pq.top().second;
			pq.pop();
			if(!a[i][y])
			{
				//a[i][y]=
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==INT_MAX)printf("- ");
			else printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
