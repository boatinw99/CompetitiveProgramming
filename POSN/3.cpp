#include<bits/stdc++.h>
using namespace std ;
int s[100001]={0};
main()
{
	int a,b,max,i,x,y,value,start,end ;
	priority_queue<pair<int,int> > pq;
	vector<int>::iterator it;
	scanf("%d %d %d",&b,&max,&a);
	vector<vector<int> > v(100000);
	for(i=1;i<=b;i++)s[i]=9999;
	for(i=0;i<a;i++)
	{
		scanf(" %d %d %d",&x,&y,&value);
		if(value>=max)
		{
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	scanf("%d %d",&start,&end);
	for(it=v[start].begin();it!=v[start].end();it++)
	{
		pq.push({-1,*it});
	}
	while(!pq.empty())
	{
		x=pq.top().first*-1; //+
		y=pq.top().second ;
		pq.pop();
		if(x<s[y])
		{
			s[y]=x;
			if(y==end)break;
			for(it=v[y].begin();it!=v[y].end();it++)
			{
				pq.push({-x-1,*it});
			}
		}
	}
	if(s[end]>9000)
	printf("-1");
	else 
	printf("%d",s[end]-1);

}
