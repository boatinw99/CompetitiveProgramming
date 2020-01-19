#include<bits/stdc++.h>
using namespace std ;
main()
{
	int i,a,sum=0,x,y;
	vector<int> v;
	map<int,pair<int,int> > m;
	map<int,pair<int,int> > ::iterator it;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d %d",&x,&y);
		v[y]=x;
	}
	m[v[y]]={v[y],1};
	for(i=a-1;i>0;i--)
	{
		m[v[i]]={v[i],1};
		it=m.begin();
	}
}
