#include<bits/stdc++.h>
using namespace std ;
int l=0,r=1e9+1;
vector<pair<int,int> >v[50009];
vector<int>nest[50009];
int hive[50009];
void dfs(int i,int par,int w)
{
	vector<pair<int,int> >::iterator it;
	hive[i]=par;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(it->second>w&&hive[it->first]==0)
		{	
			dfs(it->first,par,w);
		}
	}
}
main()
{
	vector<int>::iterator it;
	int n,m,k,i,x,y,wi ;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		nest[x].push_back(i);
	}
	while(m--)
	{
		scanf("%d %d %d",&x,&y,&wi);
		v[x].push_back({y,wi});
		v[y].push_back({x,wi});
	}
	while(l+1<r)
	{
		bool t=0;
		for(i=1;i<=n;i++)hive[i]=0;
		int mid=(l+r)/2;
		for(i=1;i<=n;i++)
		{
			if(hive[i]==0)
			{
				dfs(i,i,mid);
			}
		}
		for(i=1;i<=k;i++)
		{
			for(it=nest[i].begin();it!=nest[i].end();it++)
			{
				if(hive[*it]!=hive[*nest[i].begin()])
				{
					t++;
					break;
				}
			}
		}
		if(t==0)l=mid;
		else r=mid;
	}
	int co=0;
	vector<pair<int,int> >::iterator it1;
	for(i=1;i<=n;i++)
	{
		for(it1=v[i].begin();it1!=v[i].end();it1++)
		{
			if(it1->second<=l)co++;
		}
	}
	printf("%d",co/2);
}
