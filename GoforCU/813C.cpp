#include<bits/stdc++.h>
using namespace std ; 
vector<int> v[200001];
vector<int> ::iterator it;
queue<pair<int,pair<int,int> > > q ;
//count town
main()
{ 
	int i,n,x,a,b,max=0,c ;
	scanf("%d %d",&n,&x);
	int s[n+1];
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push({0,{0,1}});
	//souce,count,go
	while(!q.empty())
	{
		a=q.front().first;
		b=q.front().second.first;
		c=q.front().second.second;
		q.pop();
		s[c]=b;
		for(it=v[c].begin();it!=v[c].end();++it)
		{
			if(*it!=a)
			q.push({c,{b+1,*it}});
		}
	}
	q.push({0,{0,x}});
	while(!q.empty())
	{
		a=q.front().first;
		b=q.front().second.first;
		c=q.front().second.second;
		q.pop();
		if(s[c]>max)max=s[c];
		for(it=v[c].begin();it!=v[c].end();++it)
		{
			if(b+1<s[*it]&&*it!=a)
			q.push({c,{b+1,*it}});
		}
	}
	printf("%d",max*2);
}
