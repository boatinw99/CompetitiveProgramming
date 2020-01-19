#include<bits/stdc++.h>
using namespace std;
pair<pair<int,int>,pair<int,int> > s[109];
vector<int> v[2000];
vector<int>::iterator it;
int r[2009];
main()
{
	int a,i,x,y,z ;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		s[i].first.first=y;
		s[i].first.second=x;
		s[i].second.first=z;
		s[i].second.second=i+1;
	}
	sort(s,s+a);
	int lim,ti,val,q,j;
	for(i=0;i<a;i++)
	{
		lim=s[i].first.first;
		ti=s[i].first.second;
		val=s[i].second.first;
		q=s[i].second.second;
		for(j=2000;j>=1;j--)
		{
			if(r[j]!=0)
			{
				if(j+ti<lim&&val+r[j]>r[j+ti])
				{
					r[j+ti]=r[j]+val;
					for(it=v[j+ti].begin();it!=v[j+ti].end();)
						v[j+ti].erase(it);
					for(it=v[j].begin();it!=v[j].end();it++)
						v[j+ti].push_back(*it);
					v[j+ti].push_back(q);
				}
			}
		}
				if(ti<lim&&val>r[ti])
				{
					r[ti]=val;
					for(it=v[ti].begin();it!=v[ti].end();)
					v[ti].erase(it);
					v[ti].push_back(q);
					//printf("%d",q);
				}
	}
	int max=0,o=0;
	for(i=1;i<=2000;i++)
	{
		if(r[i]>max)
		{
			max=r[i];
			o=i;
		}
	}
	printf("%d\n",r[o]);
	printf("%d\n",v[o].size());
	for(it=v[o].begin();it!=v[o].end();it++)
	{
		printf("%d ",*it);
	}
	
	
}
