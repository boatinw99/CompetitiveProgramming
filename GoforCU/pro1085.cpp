#include<bits/stdc++.h>
using namespace std ; 
vector<int>v[500009];
vector<int>::iterator it;
bool s[500009];
bool b[500009];
main()
{
	int n,m,k,x,y,i;
	scanf("%d %d %d",&n,&m,&k);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}
	while(k--)
	{
		scanf("%d",&x); b[x]++;
	}
	s[1]++;
	for(i=1;i<=n-1;i++)
	{
		if(s[i])
		{
			if(!b[i])s[i+1]++;
			for(it=v[i].begin();it!=v[i].end();it++)s[*it]++;
		}
	}
	if(s[n])printf("1");
	else
	{
		for(i=n-1;i>=1;i--)
		{
			if(s[i])
			{
				printf("0 %d",i);
				return 0;
			}
		}
	}
}
