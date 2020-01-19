#include<bits/stdc++.h>
using namespace std;
int n,m,k,co,pr=0;
int b[1009];
int d[1009];
bool q[1009];
vector<int>v[1009];
void dfs(int i,int town)
{
	int x;
	vector<int>::iterator it;
	d[town]++; q[i]++;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(!q[*it])dfs(*it,town);
	}
}
void dfs1(int i)
{
	vector<int>::iterator it;
	q[i]++;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(!q[*it])dfs1(*it);
		pr+=co-v[i].size()-1;
	}
}
void dfs2(int i,int town)
{
	vector<int>::iterator it;
	q[i]++;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(!q[*it])dfs2(*it,town);
		if(d[town]-v[i].size()-1>0)
		pr+=d[town]-v[i].size()-1;
	}
}
main()
{
	int i,j,x,y,max1=0,e ;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<k;i++)scanf("%d",&b[i]);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=0;i<k;i++)
	{
		dfs(b[i],i);
		if(max1<d[i])max1=d[i],e=i;	
	}
	for(i=1;i<=n;i++)if(!q[i])co++;co+=max1;
	for(i=1;i<=n;i++)q[i]=0;
	dfs1(d[e]);
	for(i=0;i<k;i++)if(i!=e)dfs2(d[i],i);	
	printf("%d",pr);
}
