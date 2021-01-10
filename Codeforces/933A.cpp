#include<bits/stdc++.h>
using namespace std;
int n,m ;
int s[109];
vector<pair<int,char> > v[109];
int dfs(int i,char ch)
{
	vector<pair<int,char> >::iterator it;
	int x=0;
	for(it=v[i].begin();it!=v[i].end();it++)
	{
		if(ch<=it->second)
		{	
			x=dfs(it->first,it->second);
			s[i]=max(s[i],x);
		}
	}
	return x+1;
}
main()
{
	int i,x,y;
	char ch;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %c",&x,&y,&ch);
		v[x].push_back({y,ch});
	}
	for(i=1;i<=n;i++)
	{
		dfs(i,'a');
	}
	int j;
	for(i=1;i<=n;i++)
		printf("%d ",s[i]);
		printf("\n\n");
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(s[i]>s[j])printf("A");
			else printf("B");
		}
		printf("\n");
	}
}
