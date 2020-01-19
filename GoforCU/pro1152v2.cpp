#include<bits/stdc++.h>
using namespace std ;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator it;
set<int>s;
set<int>::iterator its ;
main()
{
	int i,n,j,k,x,co=0 ;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			v.push_back({x,i+j-1});
		}
	}
	sort(v.begin(),v.end(),greater<pair<int,int> >());
	for(i=2;i<=n*2-1;i++)s.insert(i);
	for(it=v.begin();it!=v.end();it++)
	{
		its=upper_bound(s.begin(),s.end(),it->second);
		if(its!=s.begin())
		{
			co+=it->first;
			its--;
			s.erase(its);
		}
	}
	printf("%d",co);
}
