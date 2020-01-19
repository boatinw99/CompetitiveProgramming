#include<bits/stdc++.h>
using namespace std ;
vector<int> v[300009];
vector<int>::iterator it;
int s[300009];
main()
{
	int i,n,j,x,y ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)s[i]=1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		if(x>y)swap(x,y);
		v[x].push_back(y);
	}
	for(i=1;i<=n-1;i++)
	{
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			s[*it]=max(s[*it],s[i]+1);
		}
	}
	int max1=0;
	for(i=1;i<=n;i++)
	{
		max1=max(max1,s[i]);
	}
	printf("%d",max1);
}
