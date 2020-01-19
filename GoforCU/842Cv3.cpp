#include<bits/stdc++.h>
using namespace std;
vector<int>v[200009];
int s[200009];
int pr[200009];
set<int>p[200009];
int dfs(int w,int gcd,int source)
{
	vector<int>::iterator it;
	set<int>::iterator its;
	for(its=p[source].begin();its!=p[source].end();its++)
	{
		p[w].insert(__gcd(s[w],*its)) ;
	}	
	p[w].insert(gcd);
	for(it=v[w].begin();it!=v[w].end();it++)
	{
		if(*it!=source)
		{
			dfs(*it,__gcd(gcd,s[w]),w);
		}
	}
	
}
main()
{
	int n,i,x,y ;
	set<int>::iterator its;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0,0);
	printf("%d ",s[1]);
	for(i=2;i<=n;i++)
	{
		its=p[i].end();
		its--;
		printf("%d ",*its);
	}
}
