#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,bool> > > v[200009];
vector<pair<int,pair<int,bool> > >::iterator it ;
vector<int> t[200009];
vector<int>::iterator itl;
queue<pair<int,int> > q;
int n,m,k,max1=0 ;
int d=-1;
int s[100009];
int dfs(int i,int h)
{
	itl=upper_bound(t[i].begin(),t[i].end(),h);
	it=v[i].begin()+(itl-t[i].begin());
	if(it==v[i].end())
	{
		if(s[i]>max1&&d==-1)d++,max1=s[i];
		else if(s[i]>max1)d=1,max1=s[i];
		return 0;
	}
	if(!it->second.second++)
	{
		//printf("%d ",it->first);	
		dfs(it->second.first,it->first);
	}
}
main()
{
	int i,j,x,y,hi ;
	scanf("%d %d %d",&m,&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	while(k--)
	{
		scanf("%d %d",&x,&hi);
		v[x].push_back({hi,{x+1,0}});
		v[x+1].push_back({hi,{x,0}});
	}
	scanf("%d",&x);
	for(i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end());
		for(it=v[i].begin();it!=v[i].end();it++)t[i].push_back(it->first);
	}
	q.push({x,0});
	while(!q.empty())
	{
		dfs(q.front().first,q.front().second);
		q.pop();
	}
	if(d==0)printf("%d\nNO",max1);
	else printf("%d\nYES",max1);
}
