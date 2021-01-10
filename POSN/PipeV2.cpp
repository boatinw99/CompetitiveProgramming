#include<bits/stdc++.h>
using namespace std;
int d[15009],e[15009];
vector<vector<pair<int,int> > > v(15009);
vector<pair<int,int> >::iterator it ;
priority_queue<pair<int,int> > p;
priority_queue<int> q ;
main()
{
	int a,b,i,x,y,j,count,count1,a1;
	scanf("%d %d",&a,&b);
	for(i=1;i<=a;i++)
	{
		scanf(" %d %d",&x,&y);
		d[i]=x;
		e[i]=y;
	}
	for(i=1;i<=a-1;i++)
	{
		for(j=i+1;j<=a;j++)
		{
			count=d[i]-d[j];
			if(count<0)count*=-1;
			count1=e[i]-e[j];
			if(count1<0)count1*=-1;
			count=count+count1;	
			v[i].push_back({j,count});
			v[j].push_back({i,count});
		}	
	}
	for(it=v[1].begin();it!=v[1].end();it++)
	{
		p.push({it->second*-1,it->first});
	}
	e[1]=0;
	a1=a;
	while(a1>1)
	{
		x=p.top().first*-1;
		y=p.top().second;
		p.pop();
		if(e[y]!=0)
		{
			a1--;
			q.push(x*-1);
			e[y]=0;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				p.push({it->second*-1,it->first});
			}
		}
	}
	count=0;
	while(b<a)
	{
		b++;
		count-=q.top();
		q.pop();
	}
	printf("%d",count);
	
	
}
